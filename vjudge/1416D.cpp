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

const ll N = 2e5;
ll n, m, q;
ll treeSize[2 * N + 1], heavy[2 * N + 1], head[2 * N + 1], pos[2 * N + 1], cnt = 0;
ll parent[2 * N + 1], cntTree = 0;
vector<ll> edge[2 * N + 1];
ll a[N + 1];
pair<ll, ll> canh[N + 1];
vector<pair<ll, ll>> query;
bool delEdge[N + 1];

void read() {
    cin >> n >> m >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh[i] = {x, y};
    }
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        if(x == 2) delEdge[y] = 1;
        query.pb({x, y});
    }
}

pair<ll, ll> node[8 * N + 1];

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) {
        node[id] = {i, val};
        return;
    }

    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id << 1, l, mid, i, val);
    else updated(id << 1 | 1, mid + 1, r, i, val);

    node[id] = (node[id << 1].sc < node[id << 1 | 1].sc ? node[id << 1 | 1] : node[id << 1]);
}

pair<ll, ll> getMax(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return {0, 0};
    if(i <= l && r <= j) return node[id];

    ll mid = (l + r) >> 1;

    auto x = getMax(id << 1, l, mid, i, j);
    auto y = getMax(id << 1 | 1, mid + 1, r, i, j);

    return (x.sc < y.sc ? y : x);
}

ll find_set(ll k) {
    return k == parent[k] ? k : parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        ll _n = ++cntTree;
        parent[_n] = _n;
        parent[x] = _n;
        parent[y] = _n;

        edge[_n].pb(x);
        edge[_n].pb(y);
        edge[x].pb(_n);
        edge[y].pb(_n);
    }
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    ll maxSize = 0;
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h, ll par) {
    head[u] = h;
    pos[u] = ++cnt;
    if(u <= n) updated(1, 1, cntTree, pos[u], a[u]);

    if(heavy[u]) hld(heavy[u], h, u);

    for(auto i : edge[u]) if(i != par && i != heavy[u]) hld(i, i, u);
}

void queryPath(ll u) {
    // cerr << u << el;
    auto [x, y] = getMax(1, 1, cntTree, pos[u], pos[u] + treeSize[u] - 1);
    cout << y << el;
    if(y) updated(1, 1, cntTree, x, 0);
    // cerr << u << el;
}

void solve() {
    cntTree = n;
    // cerr << "begin tree\n";
    FOR(i, 1, n) parent[i] = i;
    FOR(i, 1, m) if(!delEdge[i]) union_set(canh[i].ft, canh[i].sc);

    FORD(i, query.size() - 1, 0) {
        if(query[i].ft == 1) query[i].sc = find_set(query[i].sc);
        else {
            union_set(canh[query[i].sc].ft, canh[query[i].sc].sc);
        }
    }

    
    FOR(i, 1, cntTree - 1) if(find_set(i) != find_set(i + 1)) union_set(i, i + 1);

    // FOR(i, 1, cntTree) {
    //     cerr << "dinh la: " << i << el;
    //     cerr << "{ "; 
    //     for(auto j : edge[i]) cerr << j << ", ";
    //     cerr << "}\n";
    // }

    // cerr << "end tree\n";
    // cerr << "hld begin\n";
    // cerr << cntTree << el;
    dfs(cntTree, 0);
    hld(cntTree, cntTree, 0);
    // cerr << "hld end\n";

    for(auto &[i, j] : query) {
        if(i == 1) queryPath(j);
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