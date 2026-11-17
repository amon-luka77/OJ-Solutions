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
ll n, m, a[N + 1];

struct SegmentTree {
    struct NODE {
        ll val, lazy;
    };

    vector<NODE> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, (ll)-1e18});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id].val = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id].val = max(node[id * 2].val, node[id * 2 + 1].val);
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

    void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            node[id].val = val;
            node[id].lazy = val;
            return;
        }

        push(id);

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, j, val);
        updated(id * 2 + 1, mid + 1, r, i, j, val);

        node[id].val = max(node[id * 2].val, node[id * 2 + 1].val);
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return -1e18;
        if(i <= l && r <= j) return node[id].val;

        push(id);

        ll mid = (l + r) >> 1;

        return max(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
    }
};

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    cin >> m;

    for(ll i = 1; i <= m; i ++) {
        ll x, l, r, k; cin >> x >> l >> r;

        if(x == 1) {
            cin >> k;
            node.updated(1, 1, n, l, r, k);
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