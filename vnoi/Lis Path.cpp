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
ll n, a[N + 1], node[4 * N + 1], ans[N + 1];
vector<ll> b, edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(all(b));b.erase(unique(all(b)), b.end());
    fill(node + 1, node + 4 * b.size() + 1, -1e18);

    FOR(i, 1, n) a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) {
        node[id] = max(node[id], val);
        return;
    }

    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id * 2, l, mid, i, val);
    else updated(id * 2 + 1, mid + 1, r, i, val);

    node[id] = max(node[id * 2], node[id * 2 + 1]);
}

ll get(ll id, ll l, ll r, ll i) {
    if(l == r) return node[id];

    ll mid = (l + r) >> 1;
    if(i <= mid) return get(id * 2, l, mid, i);
    return get(id * 2 + 1, mid + 1, r, i);
}

ll getMax(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return -1e18;
    if(i <= l && r <= j) return node[id];

    ll mid = (l + r) >> 1;
    return max(getMax(id * 2, l, mid, i, j), getMax(id * 2 + 1, mid + 1, r, i, j));
}

void updatedPre(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) {
        node[id] = val;
        return;
    }

    ll mid = (l + r) >> 1;
    if(i <= mid) updatedPre(id * 2, l, mid, i, val);
    else updatedPre(id * 2 + 1, mid + 1, r, i, val);

    node[id] = max(node[id * 2], node[id * 2 + 1]);
}

void dfs(ll u, ll par) {
    ll k = max(1LL, getMax(1, 1, b.size(), 1, a[u] - 1) + 1);
    ll pre = get(1, 1, b.size(), a[u]);
    updated(1, 1, b.size(), a[u], k);
    if(k > 0) ans[u] = max(ans[par], k);

    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
    }

    updatedPre(1, 1, b.size(), a[u], pre);
}

void solve() {
    dfs(1, -1);

    FOR(i, 1, n) cout << ans[i] << el;
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