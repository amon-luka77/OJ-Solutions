/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 250000;
ll n, k, m, p[N + 1], num[N + 1], low[N + 1], comp[N + 1];
ll scc = 0, cnt = 0, pos[N + 1], deg[N + 1];
bool vsNewEdge[N + 1], deleted[N + 1];
set<pair<ll, ll>> prio;
vector<pair<ll, ll>> canh;
vector<ll> edge[N + 1], newEdge[N + 1];
stack<ll> st;

void read() {
    cin >> k >> n;
    FOR(i, 1, k) cin >> p[i];
    cin >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        prio.insert({x, y});
        canh.pb({x, y});
        edge[x].pb(y);
    }

    // cout << 7; exit(0);
}   

void dfs(ll u) {
    num[u] = low[u] = ++cnt;
    st.push(u);

    for(auto i : edge[u]) if(!deleted[i]) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i);
            low[u] = min(low[u], low[i]);
        }
    }

    if(low[u] == num[u]) {
        ++scc;
        while(1) {
            ll v = st.top(); st.pop();
            comp[v] = scc;
            deleted[v] = 1;
            if(u == v) break;
        }
    }
}

bool dfsFind(ll u, ll endNode) {
    if(u == endNode) return 1;
    vsNewEdge[u] = 1;

    for(auto i : newEdge[u]) if(!vsNewEdge[i] && pos[i] <= pos[endNode]) {
        if(dfsFind(i, endNode)) {
            return 1;
        }
    }

    return 0;
}

void solve() {
    ll ans = 0;

    FOR(i, 1, n) if(!num[i]) dfs(i);

    for(auto &[i, j] : canh) {
        if(comp[i] != comp[j]) {
            newEdge[comp[i]].pb(comp[j]);
            deg[comp[j]] ++;
        }
    }

    queue<ll> q;
    vector<ll> topo;

    FOR(i, 1, scc) if(deg[i] == 0) {
        q.push(i);
    }

    while(!q.empty()) {
        ll v = q.front(); q.pop();
        topo.pb(v);
        for(auto i : newEdge[v]) {
            deg[i] --;
            if(deg[i] == 0) q.push(i);
        }
    }

    FOR(i, 0, topo.size() - 1) {
        pos[topo[i]] = i + 1;
    }

    FOR(i, 2, k) {
        if(prio.find({p[i - 1], p[i]}) != prio.end()) {
            ans += 2;
        }
        else {
            if(comp[p[i - 1]] == comp[p[i]]) ans ++;
            else if(dfsFind(comp[p[i - 1]], comp[p[i]])) ans ++;
            else break;
        }
    }

    cout << ans;
}

void write() {

}

int main() {
    boost;
    // file("7E07");
    read();
    solve();
    write();
    return 0;
}