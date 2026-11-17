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

const ll N = 3e5;
ll n, m, num[N + 1], low[N + 1], szScc[N + 1], comp[N + 1];
ll dp[N + 1], cnt = 0, scc = 0;
vector<ll> edge[N + 1], newEdge1[N + 1], newEdge2[N + 1];
vector<pair<ll, ll>> canh;
set<pair<ll, ll>> b;
stack<ll> st;
bool deleted[N + 1], vs[N + 1], mark[N + 1], khuyen[N + 1], vs2[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh.pb({x, y});
        if(x == y) khuyen[x] = 1;
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
            deleted[v] = 1;
            comp[v] = scc;
            szScc[scc] ++;
            if(v == u) break;
        }
    }
}

ll dfsAns(ll u) {
    if(dp[u]) return dp[u];
    if(u == comp[1]) return dp[u] = 1;
    
    ll res = 0;
    for(auto i : newEdge1[u]) {
        res += dfsAns(i);
    }

    return dp[u] = res;
}

void chutrinh(ll u) {
    vs2[u] = 1;
    for(auto i : newEdge2[u]) {
        if(mark[u]) mark[i] = 1;
        if(!vs2[i]) chutrinh(i);
    }
}

void dfsPath(ll u) {
    vs[u] = 1;
    for(auto i : newEdge2[u]) if(!vs[i]) dfsPath(i);
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i);
    // cout << el;
    // FOR(i, 1, n) cout << i << ' ' << comp[i] << el;
    // cout << el;

    for(auto &[i, j] : canh) if(comp[i] != comp[j] && b.find({comp[i], comp[j]}) == b.end()) {
        newEdge1[comp[j]].pb(comp[i]);
        newEdge2[comp[i]].pb(comp[j]);
        b.insert({comp[i], comp[j]});
    }

    FOR(i, 1, n) if(khuyen[i]) mark[comp[i]] = 1;

    FOR(i, 1, scc) {
        if(szScc[i] >= 2) mark[i] = 1;
    }

    chutrinh(comp[1]);
    dfsPath(comp[1]);
    FOR(i, 1, scc) if(!dp[i]) dfsAns(i);

    FOR(i, 1, n) {
        if(!vs[comp[i]]) cout << 0;
        else if(mark[comp[i]]) cout << -1;
        else if(dp[comp[i]] == 1) cout << 1;
        else cout << 2;
        cout << ' ';
    }
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