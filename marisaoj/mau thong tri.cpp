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

const ll N = 1e5;
ll n, q, high[N + 1], par[N + 1], head[N + 1], pos[N + 1];
ll treeSize[N + 1], heavy[N + 1], idx[N + 1], a[N + 1], cnt = 0;
map<ll, vector<ll>> b;
pair<ll, ll> node[4 * N + 1];

vector<ll> edge[N + 1];

pair<ll, ll> merge(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.ft == y.ft) return {x.ft, x.sc + y.sc};
    if(x.sc < y.sc) swap(x, y);
    return {x.ft, x.sc - y.sc};
}

void build(ll id, ll l, ll r) {
    if(l == r) {
        node[id] = {a[idx[l]], 1};
        return;
    }

    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    node[id] = merge(node[id * 2], node[id * 2 + 1]);
}

pair<ll, ll> getVal(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return {0, 0};
    if(i <= l && r <= j) return node[id];

    ll mid = (l + r) >> 1;

    return merge(getVal(id * 2, l, mid, i, j), getVal(id * 2 + 1, mid + 1, r, i, j));
}

void read() {
    cin >> n >> q;

    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    ll maxSize = 0;

    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        par[i] = u;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            heavy[u] = i;
            maxSize = treeSize[i];
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++cnt;
    idx[cnt] = u;

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != heavy[u] && i != par[u]) {
        hld(i, i);
    }
}

pair<ll, ll> getHld(ll u, ll v) {
    pair<ll, ll> ans = {0, 0};

    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        ans = merge(ans, getVal(1, 1, n, pos[head[u]], pos[u]));

        u = par[head[u]];
    }
    if(pos[u] > pos[v]) swap(u, v);
    ans = merge(ans, getVal(1, 1, n, pos[u], pos[v]));

    return ans;
}

bool getQuery(ll u, ll v, ll color) {
    ll x = u, y = v;
    ll cntC = 0, len = 0;
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        cntC += upper_bound(all(b[color]), pos[u]) - lower_bound(all(b[color]), pos[head[u]]);
        len += pos[u] - pos[head[u]] + 1;

        u = par[head[u]];
    }

    if(pos[u] > pos[v]) swap(u, v);
    cntC += upper_bound(all(b[color]), pos[v]) - lower_bound(all(b[color]), pos[u]);
    len += pos[v] - pos[u] + 1;

    // cout << x << ' ' << y << ' ' << color << ' ' << cntC << ' ' << len << el;
    return (cntC >= len /  2 + 1);
}

void solve() {
    dfs(1, -1);
    hld(1, 1);
    build(1, 1, n);

    FOR(i, 1, n) b[a[i]].pb(pos[i]);
    for(auto &[i, j] : b) sort(all(j));

    FOR(i, 1, q) {
        ll u, v; cin >> u >> v;
        pair<ll, ll> ans = getHld(u, v);
        if(ans.ft != 0 && getQuery(u, v, ans.ft)) cout << ans.ft << el;
        else cout << -1 << el;
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