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

const ll N = 3e5, LOG = 20;
ll n, q;
struct CANH {ll x, y, z;}; vector<CANH> E;
void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        E.pb({x, y, z});
    }
}

ll parent[2 * N + 1], cntTree = 0, a[2 * N + 1]; vector<ll> edge[2 * N + 1];
ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

inline void addEdge(ll x, ll y) {
    ll _n = ++cntTree;
    parent[_n] = _n; parent[x] = parent[y] = _n;
    edge[_n].pb(x); edge[_n].pb(y);
}

void union_set(ll u, ll v, ll w) {
    ll x = find_set(u), y = find_set(v);
    if(x != y) {addEdge(x, y); a[cntTree] = w;}
}

void buildDsuTree() {
    sort(all(E), [](const CANH &x, const CANH &y) {
        return x.z < y.z;
    }); cntTree = n;
    FOR(i, 1, n) parent[i] = i;
    for(auto &[i, j, w] : E) union_set(i, j, w);
}

ll id[8 * N + 1], pos[2 * N + 1], high[2 * N + 1], cntLca = 0, minHigh[8 * N + 1][LOG + 1];
void dfs(ll u, ll par) {
    id[++cntLca] = u;
    pos[u] = cntLca;

    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        id[++cntLca] = u;
    }
}

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

void buildLca() {
    dfs(cntTree, 0);
    FOR(i, 1, cntLca) minHigh[i][0] = id[i];
    FOR(j, 1, LOG) FOR(i, 1, cntLca - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }
}

inline ll lca(ll u, ll v) {
    if(!u || !v) return u + v;
    u = pos[u], v = pos[v]; if(u > v) swap(u, v);
    ll k = __lg(v - u + 1);
    return MIN_HIGH(minHigh[u][k], minHigh[v - MASK(k) + 1][k]);
}

struct NODE {ll val, lazy, lca;}; NODE node[4 * N + 1];

void build(ll id, ll l, ll r) {
    if(l == r) return node[id].lca = l, void();
    ll mid = (l + r) >> 1;
    build(id << 1, l, mid); build(id << 1 | 1, mid + 1, r);
    node[id].lca = lca(node[id << 1].lca, node[id << 1 | 1].lca);
}

inline void merge(ll id) {node[id].val = lca(node[id << 1].val, node[id << 1 | 1].val);}

inline void updatedLca(ll id, ll v) {
    node[id].val = v > 0 ? node[id].lca : 0;
    node[id].lazy = v;
}

inline void push(ll id) {
    ll &k = node[id].lazy; if(!k) return;
    updatedLca(id << 1, k), updatedLca(id << 1 | 1, k);
    k = 0;
}

void updated(ll id, ll l, ll r, ll i, ll j, ll v) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) return updatedLca(id, v);
    ll mid = (l + r) >> 1; push(id);
    updated(id << 1, l, mid, i, j, v); updated(id << 1 | 1, mid + 1, r, i, j, v);
    merge(id);
}

inline void solve1() {
    ll x, y; cin >> x >> y;
    updated(1, 1, n, x, y, 1);
}

inline void solve2() {
    ll x, y; cin >> x >> y;
    updated(1, 1, n, x, y, -1);
}

inline void solve3() {
    ll x; cin >> x;
    cout << (!node[1].val || node[1].val == x ? -1 : a[lca(x, node[1].val)]) << el;
}

void solve() {
    buildDsuTree();
    buildLca();
    build(1, 1, n);

    FOR(i, 1, q) {
        ll opt; cin >> opt;
        switch (opt) {
            case 1: solve1(); break;
            case 2: solve2(); break;
            case 3: solve3(); break;
        }
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