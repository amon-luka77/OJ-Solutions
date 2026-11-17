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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, m, q;

struct CANH {ll x, y, z;}; vector<CANH> E;
void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z; E.pb({x, y, z});
    }
}

ll parent[N + 1], val[N + 1], cntTree = 0; vector<ll> edge[N + 1];
ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

void union_set(ll u, ll v, ll w) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        ll _n = ++cntTree;
        parent[_n] = _n;
        parent[y] = _n;
        parent[x] = _n;

        edge[_n].pb(x);
        edge[_n].pb(y);
        val[_n] = w;
    }
}

void buildDsuTree() {
    sort(all(E), [](const CANH &x, const CANH &y) {
        return x.z > y.z;
    }); cntTree = n; FOR(i, 1, n) parent[i] = i;
    for(auto &[i, j, w] : E) union_set(i, j, w);

    FOR(i, 1, cntTree - 1) if(find_set(i) != find_set(i + 1)) union_set(i, i + 1, -1);
}

const ll LOG = 20;
ll cnt = 0, id[8 * N + 1], pos[2 * N + 1], high[2 * N + 1], minHigh[8 * N + 1][LOG + 1];
void dfs(ll u, ll par) {
    id[++cnt] = u;
    pos[u] = cnt;
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        id[++cnt] = u;
    }
}

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

void buildLca() {
    dfs(cntTree, 0);
    FOR(i, 1, cnt) minHigh[i][0] = id[i];
    FOR(j, 1, LOG) FOR(i, 1, cnt - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }
}

ll lca(ll u, ll v) {
    u = pos[u], v = pos[v]; if(u > v) swap(u, v);
    ll k = __lg(v - u + 1);
    return MIN_HIGH(minHigh[u][k], minHigh[v - MASK(k) + 1][k]);
}

void solve() {
    buildDsuTree();
    buildLca();

    cin >> q;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        // cerr << x << ' ' << y << ' ' << lca(x, y) << el;
        cout << val[lca(x, y)] << el;
    }
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}