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
ll n, q, a[N + 1], node[4 * N + 1], node2[4 * N + 1];
void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}

void build(ll id, ll l, ll r) {
    if(l == r) {
        node[id] = a[l];
        return;
    }

    ll mid = l + (r - l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    node[id]= max(node[id * 2], node[id * 2 + 1]);
}

void updated1(ll id, ll l, ll r, ll i, ll val) {
    if(l > i || r < i) return;
    if(l == r) {
        node[id] = max(node[id], val);
        return;
    }

    ll mid = l + (r - l) / 2;
    updated1(id * 2, l, mid, i, val);
    updated1(id * 2 + 1, mid + 1, r, i, val);

    node[id] = max(node[id * 2], node[id * 2 + 1]);
}

void updated2(ll id, ll l, ll r, ll i) {
    if(l > i || r < i) return;
    if(l == r) {
        node2[id] --;
        return;
    }

    ll mid = l + (r - l) / 2;
    updated2(id * 2, l, mid, i);
    updated2(id * 2 + 1, mid + 1, r, i);

    node2[id] = node2[id * 2] + node2[id * 2 + 1];
}

ll get(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return -1e18;
    if(i <= l && r <= j) {
        return node[id];
    }

    ll mid = l + (r - l) / 2;

    return max(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
}

ll get2(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return node2[id];

    ll mid = l + (r - l) / 2;

    return get2(id * 2, l, mid, i, j) + get2(id * 2 + 1, mid + 1, r, i, j);
}

void solve() {
    build(1, 1, n);
    
    while(q--) {
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1) {
            updated1(1, 1, n, min(l, n), r);
            updated2(1, 1, n, min(n, l));
        } else {
            cout << l + get2(1, 1, n, 1, min(l, n)) << ' ' << r + get2(1, 1, n, 1, min(n, r)) << el;
            cout << get(1, 1, n, l + get2(1, 1, n, 1, min(l, n)), r + get2(1, 1, n, 1, min(n, r))) << el;
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