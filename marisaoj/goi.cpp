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

const ll N = 1e5;
ll n, q, ans = 0, cnt = 0, pos[N + 1], heavy[N + 1], par[N + 1];
ll treeSize[N + 1], head[N + 1], high[N + 1];

vector<ll> edge[N + 1];

struct SegmentTree {
    ll val = 0, lz = -1;
};

SegmentTree node[4 * N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void lazy(ll id, ll l, ll r) {
    if(node[id].lz == -1) return;
    ll k = node[id].lz; node[id].lz = -1;

    ll mid = (l + r) >> 1;
    node[id * 2].val = (mid - l + 1) * k;
    node[id * 2 + 1].val = (r - mid) * k;
    node[id * 2].lz = k;
    node[id * 2 + 1].lz = k;
}

void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {
        node[id].val = (r - l + 1) * val;
        node[id].lz = val;
        return;
    }

    lazy(id, l, r);
    ll mid = (l + r) >> 1;

    updated(id * 2, l, mid, i, j, val);
    updated(id * 2 + 1, mid + 1, r, i, j, val);

    node[id].val = node[id * 2].val + node[id * 2 + 1].val;
}

ll getSum(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return node[id].val;

    lazy(id, l, r);
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

    if(heavy[u]) hld(heavy[u], h);
    
    for(auto i : edge[u]) if(i != par[u] && i != heavy[u]) {
        hld(i, i);
    }
}

void updatedPath(ll u, ll v) {
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        updated(1, 1, n, pos[head[u]], pos[u], 1);

        u = par[head[u]];
    }

    if(high[u] > high[v]) swap(u, v);
    updated(1, 1, n, pos[u], pos[v], 1);
}

void updatedSubTree(ll u) {
    ll k = min(n, pos[u] + treeSize[u] - 1);
    updated(1, 1, n, pos[u], k, 0);
}

void solve() {
    dfs(1, -1);
    hld(1, 1);


    FOR(i, 1, q) {
        ll x, u; cin >> x >> u;
        ll pre = ans;
        if(x == 1) {
            updatedPath(1, u);
        } else {
            updatedSubTree(u);
        }

        ans = getSum(1, 1, n, 1, n);
        cout << abs(ans - pre) << el;
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