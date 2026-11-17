#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e5;
ll n, q, a[N + 1];
multiset<ll> node[4 * N + 1];

void build(ll id, ll l, ll r) {
    if(l == r) {
        node[id].insert(a[l]);
        return;
    }

    ll mid = (l + r) >> 1;

    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    node[id] = node[id * 2];

    for(auto &i : node[id * 2 + 1]) {
        node[id].insert(i);
    }
}

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l > i || r < i) return;
    ll pre = a[i];
    if(l == r) {
        node[id].clear();
        node[id].insert(val);
        a[i] = val;
        return;
    }

    ll mid = (l + r) >> 1;

    updated(id * 2, l, mid, i, val);
    updated(id * 2 + 1, mid + 1, r, i, val);

    node[id].erase(node[id].find(pre));
    node[id].insert(val);
}

ll get(ll id, ll l, ll r, ll i, ll j, ll val) {
    if(l > j || r < i) return 1e18;
    if(i <= l && r <= j) {
        auto it = node[id].lower_bound(val);
        if(it != node[id].end()) {
            return (*it);
        } else {
            return 1e18;
        }
    }

    ll mid = (l + r) >> 1;
    return min(get(id * 2, l, mid, i, j, val), get(id * 2 + 1, mid + 1, r, i, j, val));
}

void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() { 
    build(1, 1, n);

    for(ll i = 1; i <= q; i ++) {
        ll x, l, r, k; cin >> x >> l >> r;

        if(x == 1) {
            updated(1, 1, n, l, r);
        } else {
            cin >> k;
            ll t = get(1, 1, n, l, r, k);
            cout << (t != 1e18) * t + (t == 1e18) * (-1) << el;
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