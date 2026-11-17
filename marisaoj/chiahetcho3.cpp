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
struct NODE {
    ll so0, so1, so2, lazy;
} node[4 * N + 1];
void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}

void build(ll id, ll l, ll r) {
    if(l == r) {
        if(a[l] % 3 == 0) node[id].so0 ++;
        else if(a[l] % 3 == 1) node[id].so1 ++;
        else node[id].so2 ++;
        return;
    }

    ll mid = l + (r - l) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    node[id].so0 = node[id * 2].so0 + node[id * 2 + 1].so0;
    node[id].so1 = node[id * 2].so1 + node[id * 2 + 1].so1;
    node[id].so2 = node[id * 2].so2 + node[id * 2 + 1].so2;
}

void push(ll id, ll l, ll r) {
    if(node[id].lazy == 0) return;
    ll k = node[id].lazy; node[id].lazy = 0;

    if(k % 3 == 1) {
        ll k0 = node[id * 2].so0;
        ll k1 = node[id * 2].so1;
        ll k2 = node[id * 2].so2;
        
        node[id * 2].so0 = k2;
        node[id * 2].so1 = k0;
        node[id * 2].so2 = k1;

        k0 = node[id * 2 + 1].so0;
        k1 = node[id * 2 + 1].so1;
        k2 = node[id * 2 + 1].so2;
        
        node[id * 2 + 1].so0 = k2;
        node[id * 2 + 1].so1 = k0;
        node[id * 2 + 1].so2 = k1;
    } else if(k % 3 == 2) {
        ll k0 = node[id * 2].so0;
        ll k1 = node[id * 2].so1;
        ll k2 = node[id * 2].so2;
        
        node[id * 2].so0 = k1;
        node[id * 2].so1 = k2;
        node[id * 2].so2 = k0;

        k0 = node[id * 2 + 1].so0;
        k1 = node[id * 2 + 1].so1;
        k2 = node[id * 2 + 1].so2;
        
        node[id * 2 + 1].so0 = k1;
        node[id * 2 + 1].so1 = k2;
        node[id * 2 + 1].so2 = k0;
    }

    node[id * 2].lazy += k;
    node[id * 2 + 1].lazy += k;
}

void updated(ll id, ll l, ll r, ll i, ll j) {
    if(l > j ||r < i) return;
    if(i <= l && r <= j) {
        node[id].lazy ++;
        ll k0 = node[id].so0;
        ll k1 = node[id].so1;
        ll k2 = node[id].so2;
        
        node[id].so0 = k2;
        node[id].so1 = k0;
        node[id].so2 = k1;
        return;
    }

    push(id, l, r);

    ll mid = l + (r - l) / 2;
    updated(id * 2, l, mid, i, j);
    updated(id * 2 + 1, mid + 1, r, i, j);

    node[id].so0 = node[id * 2].so0 + node[id * 2 + 1].so0;
    node[id].so1 = node[id * 2].so1 + node[id * 2 + 1].so1;
    node[id].so2 = node[id * 2].so2 + node[id * 2 + 1].so2;
}

ll get(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return node[id].so0;

    push(id, l, r);

    ll mid = l + (r - l) / 2;

    return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
}

void solve() {
    build(1, 1, n);

    while(q--) {
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1) {
            updated(1, 1, n, l, r);
        } else {
            cout << get(1, 1, n, l, r) << el;
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