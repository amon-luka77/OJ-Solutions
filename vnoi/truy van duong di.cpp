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
ll n, q, high[N + 1], heavy[N + 1], head[N + 1], pos[N + 1];
ll bit[N + 1], a[N + 1], treeSize[N + 1], parent[N + 1], cnt = 0;

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

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll get(ll l, ll r) {
    ll sum = 0;
    for(; l >= 1; l -= l & -l) sum -= bit[l];
    for(; r >= 1; r -= r & -r) sum += bit[r];
    return sum;
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    ll maxSize = 0;
    parent[u] = par;

    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll par, ll h) {
    head[u] = h;
    pos[u] = ++cnt;
    updated(pos[u], a[u]);

    if(heavy[u]) hld(heavy[u], u, h);

    for(auto i : edge[u]) if(i != par && i != heavy[u]) {
        hld(i, u, i);
    }
}

void updatedQuery(ll u, ll val) {
    updated(pos[u], val - a[u]);
    a[u] = val;
}

void getQuery(ll u, ll v) {
    ll sum = 0;
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        sum += get(pos[head[u]] - 1, pos[u]);
        u = parent[head[u]];
    }

    if(high[u] > high[v]) swap(u, v);
    sum += get(pos[u] - 1, pos[v]);
    cout << sum << el;
}

void solve() {
    dfs(1, -1);
    hld(1, -1, 1);

    while(q --) {
        ll x, l, r; cin >> x;
        if(x == 1) {
            cin >> l >> r;
            updatedQuery(l, r);
        } else {
            cin >> l;
            getQuery(1, l);
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