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
using namespace std;

const ll N = 2e5;
ll n, q, heavy[N + 1], pos[N + 1], par[N + 1], node[4 * N + 1], a[N + 1];
ll treeSize[N + 1], head[N + 1], high[N + 1], cnt = 0;
vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) {
        node[id] = val;
        return;
    }

    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id * 2, l, mid, i, val);
    else updated(id * 2 + 1, mid + 1, r, i, val);

    node[id] = node[id * 2] + node[id * 2 + 1];
}

ll getSum(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return node[id];
    
    ll mid = (l + r) >> 1;

    return getSum(id * 2, l, mid, i, j) + getSum(id * 2 + 1, mid + 1, r, i, j);
}

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    ll maxSize = 0;
    par[u] = parent;

    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(treeSize[i] > maxSize) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++cnt;
    updated(1, 1, n, pos[u], a[u]);

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != par[u] && i != heavy[u]) {
        hld(i, i);
    }
}

void updatedQuery(ll u, ll val) {
    updated(1, 1, n, pos[u], val);
}

void query(ll u, ll v) {
    ll ans = 0;
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        ans += getSum(1, 1, n, pos[head[u]], pos[u]);
        u = par[head[u]];
    }

    if(high[u] > high[v]) swap(u, v);
    ans += getSum(1, 1, n, pos[u], pos[v]);

    cout << ans << el;
}

void solve() {
    dfs(1, -1);
    hld(1, 1);

    FOR(i, 1, q) {
        ll x, l, r; cin >> x >> l;
        if(x == 1) {
            cin >> r;
            updatedQuery(l, r);
        } else {
            query(1, l);
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