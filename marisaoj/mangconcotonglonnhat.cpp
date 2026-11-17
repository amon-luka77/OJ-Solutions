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
    ll val, left, right, sum;
} node[4 * N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}

void build(ll id, ll l, ll r) {
    if(l == r) {
        node[id].val = a[l];
        node[id].left = a[l];
        node[id].right = a[l];
        node[id].sum = a[l];
        return;
    }

    ll mid = l + (r - l ) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    node[id].val = max({node[id * 2].val, node[id * 2 + 1].val, node[id * 2].right + node[id * 2 + 1].left});
    node[id].left = max(node[id * 2].left, node[id * 2].sum + node[id * 2 + 1].left);
    node[id].right = max(node[id * 2 + 1].right, node[id * 2 + 1].sum + node[id * 2].right);
    node[id].sum = node[id * 2].sum + node[id * 2 + 1].sum;
}

NODE get(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return {(ll)-1e18, (ll)-1e18, (ll)-1e18, 0};
    if(i <= l && r <= j) return node[id];

    ll mid = l + (r - l) / 2;
    auto get1 = get(id * 2, l, mid, i, j);
    auto get2 = get(id * 2 + 1, mid + 1, r, i, j);

    return {max({get1.val, get2.val, get1.right + get2.left}), max(get1.left, get1.sum + get2.left), max(get2.right, get2.sum + get1.right), get1.sum + get2.sum};
}

void solve() {
    build(1, 1, n);
    cin >> q;
    while(q--) {
        ll l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r).val << el;
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