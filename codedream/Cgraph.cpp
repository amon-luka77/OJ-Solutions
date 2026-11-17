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

const ll N = 2e5, LOG = 19;
ll n, m, parent[N + 1], sz[N + 1], high[N + 1], par[N + 1][LOG + 1], maxEdge[N + 1][LOG + 1];
bool vs[N + 1];

struct CANH {
    ll x, y, z, t;
};

vector<CANH> canh, canhRoot;

vector<pair<ll, ll>> edge[N + 1];
void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        if(x == 2) canhRoot.pb({x, y, z, i});
        if(x == 1) canh.pb({x, y, z, i});
    }
    sort(all(canh), [](const CANH &x, const CANH &y) {
        return x.t < y.t;
    });

    FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}
}

void dfs(ll u, ll parent) {
    vs[u] = 1;
    for(auto &[i, j] : edge[u]) if(i != parent && !vs[i]) {
        high[i] = high[u] + 1;
        par[i][0] = u;
        maxEdge[i][0] = j;
        dfs(i, u);
    }
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    ll d = high[u] - high[v];
    FORD(i, LOG, 0) if(BIT(d, i)) u = par[u][i];
    if(u == v) return u;
    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i]; v = par[v][i];
    }
    return par[u][0];
}

ll MAX_EDGE(ll u, ll v) {
    ll d = lca(u, v);
    ll res = 0, dis1 = high[u] - high[d], dis2 = high[v] - high[d];

    FORD(i, LOG, 0) {
        if(BIT(dis1, i)) {res = max(res, maxEdge[u][i]); u = par[u][i];}
        if(BIT(dis2, i)) {res = max(res, maxEdge[v][i]); v = par[v][i];}
    }

    return res;
}

ll find_set(ll k) {
    return k == parent[k] ? k : parent[k] = find_set(parent[k]);
}

bool union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return 1;
    }

    return 0;
}

void solve() {
    for(auto &[i, j, z, idx] : canh) {
        if(union_set(z, j)) {
            edge[j].pb({z, idx});
            edge[z].pb({j, idx});
        }
    }

    FOR(i, 1, n) if(!vs[i]) {
        dfs(i, 0);
    }
    
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        maxEdge[i][j] = max(maxEdge[i][j - 1], maxEdge[par[i][j - 1]][j - 1]);
    }

    for(auto &[i, j, z, t] : canhRoot) {
        if(find_set(j) != find_set(z)) cout << -1 << el;
        else {
            ll x = MAX_EDGE(j, z);
            cout << (x <= t ? x : -1) << el;
        }
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
