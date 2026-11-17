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

const ll N = 5e5;
ll n, q;

struct QUERY {ll x, y, z;}; vector<QUERY> query[N + 1];
vector<pair<ll, ll>> edge[N + 1];
void read() {
    cin >> n >> q;
    FOR(i, 2, n) {
        ll x, y; cin >> x >> y; edge[i].pb({x, y}); edge[x].pb({i, y});
        // cerr << i << ' ' << x << ' ' << y << el;
    }
    FOR(i, 1, q) {
        ll u, l, r; cin >> u >> l >> r;
        query[u].pb({l, r, i});
    }
}

ll node[4 * N + 1], lazy[4 * N + 1];
void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) return node[id] = val, void();
    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id << 1, l, mid, i, val);
    else updated(id << 1 | 1, mid + 1, r, i, val);
    node[id] = min(node[id << 1], node[id << 1 | 1]);
}

inline void push(ll id) {
    ll &k = lazy[id]; if(!k) return;
    node[id << 1] += k; lazy[id << 1] += k;
    node[id << 1 | 1] += k; lazy[id << 1 | 1] += k;
    k = 0;
}

inline ll merge(ll x, ll y) {return (x < y ? x : y);}

void updatedLazy(ll id, ll l, ll r, ll i, ll j, ll val) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {node[id] += val; lazy[id] += val; return;}
    ll mid = (l + r) >> 1; push(id);
    updatedLazy(id << 1, l, mid, i, j, val);
    updatedLazy(id << 1 | 1, mid + 1, r, i, j, val);
    node[id] = merge(node[id << 1], node[id  << 1 | 1]);
}

ll getMin(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return 1e18;
    if(i <= l && r <= j) return node[id];
    ll mid = (l + r) >> 1; push(id);
    return min(getMin(id << 1, l, mid, i, j), getMin(id << 1 | 1, mid + 1, r, i, j));
}

ll cnt = 0, startTour[N + 1], endTour[N + 1], pos[N + 1], dis[N + 1], ans[N + 1];
void preDfs(ll u, ll par) {
    startTour[u] = ++cnt; pos[u] = cnt; bool leaf = 1;
    for(auto &[i, j] : edge[u]) if(i != par) {dis[i] = dis[u] + j; preDfs(i, u); leaf = 0;}
    endTour[u] = cnt; 
    if(leaf) updated(1, 1, n, pos[u], dis[u]);
}

void dfs(ll u, ll par) {
    for(auto &[l, r, id] : query[u]) ans[id] = getMin(1, 1, n, l, r);

    for(auto &[i, j] : edge[u]) if(i != par) {
        updatedLazy(1, 1, n, 1, n, j);
        updatedLazy(1, 1, n, startTour[i], endTour[i], -2 * j);
        dfs(i, u);
        updatedLazy(1, 1, n, 1, n, -j);
        updatedLazy(1, 1, n, startTour[i], endTour[i], 2 * j);
    }
}

void solve() {
    FOR(i, 1, 4 * n) node[i] = 1e18;
    preDfs(1, 0);
    dfs(1, 0);

    FOR(i, 1, n) cerr << i << ' ' << dis[i] << el;

    FOR(i, 1, q) cout << ans[i] << el;
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