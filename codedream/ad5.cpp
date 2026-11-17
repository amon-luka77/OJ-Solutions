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
ll n, q;
struct KK {
    ll val, lazy;
};
struct SegmentTree {
    vector<KK> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, (ll)-1e18});
    }

    void push(ll id) {
        if(node[id].lazy == -1e18) return;
        ll k = node[id].lazy; node[id].lazy = -1e18;

        node[id * 2].val = k;
        node[id * 2].lazy = k;
        node[id * 2 + 1].val = k;
        node[id * 2 + 1].lazy = k;

        return;
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll vl) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            node[id].val = vl;
            node[id].lazy = vl;
            return;
        }

        push(id);

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, j, vl);
        updated(id * 2 + 1, mid + 1, r, i, j, vl);

        node[id].val = min(node[id * 2].val, node[id * 2 + 1].val);
    } 

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 1e18;
        if(i <= l && r <= j) return node[id].val;

        ll mid = (l + r) >> 1;

        push(id);

        return min(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
    }
};
void read() {
    cin >> n >> q;
}
void solve() {
    SegmentTree node(n);

    while(q--) {
        ll x, l, r, val;
        cin >> x >> l >> r;
        if(x == 1) {
            cin >> val;
            node.updated(1, 1, n, l, r, val);
        } else {
            cout << node.get(1, 1, n, l, r) << el;
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
