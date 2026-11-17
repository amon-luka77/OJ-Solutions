/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5;
ll n, m, num[N + 1], low[N + 1], treeSize[N + 1], comp[N + 1], outDeg[N + 1];
vector<ll> edge[N + 1], newEdge[N + 1], childScc[N + 1];
bool vs[N + 1], deleted[N + 1];
ll scc = 0, cnt = 0;
set<pair<ll, ll>> b;
vector<pair<ll, ll>> canh;
stack<ll> st;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh.pb({x, y});
        edge[x].pb(y);
    }
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

    if(num[u] == low[u]) {
        ++scc;
        while(1) {
            ll v = st.top(); st.pop();
            comp[v] = scc;
            deleted[v] = 1;
            childScc[scc].pb(v);
            if(v == u) break;
        }
    }
}

void dfsAns(ll u) {
    vs[u] = 1;
    for(auto i : newEdge[u]) if(!vs[i]) dfsAns(i);
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i);
    // cout << el;
    // FOR(i, 1, n) cout << i << ' ' << comp[i] << el;
    // cout << el;
    for(auto &[i, j] : canh) if(comp[i] != comp[j] && b.find({comp[j], comp[i]}) == b.end()) {
        // cout << comp[j] << ' ' << comp[i] << el;
        outDeg[comp[i]] ++;
        newEdge[comp[j]].pb(comp[i]);
        b.insert({comp[j], comp[i]});
    }

    ll root = 0;
    FOR(i, 1, scc) {
        // cout << i << ' ' << outDeg[i] << el;
        if(outDeg[i] == 0) {root = i; break;}
    }

    dfsAns(root);
    ll res = 0;
    FOR(i, 1, scc) res += vs[i];

    if(res != scc) {cout << 0; return;}

    cout << childScc[root].size() << el;
    sort(all(childScc[root]));
    for(auto i : childScc[root]) cout << i << ' ';
}

void write() {

}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}