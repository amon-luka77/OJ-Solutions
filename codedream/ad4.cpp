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
struct KK {
    ll val, sl;
};
struct SegmentTree {
    vector<KK> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id].val = a[l];
            node[id].sl = 1;
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        if(node[id * 2].val < node[id * 2 + 1].val) {
            node[id].val = node[id * 2].val;
            node[id].sl = node[id * 2].sl;
        } else if(node[id * 2].val == node[id * 2 + 1].val) {
            node[id].val = node[id * 2].val;
            node[id].sl = node[id * 2].sl + node[id * 2 + 1].sl;
        } else {
            node[id].val = node[id * 2 + 1].val;
            node[id].sl = node[id * 2 + 1].sl;
        }
    }

    void updated(ll id, ll l, ll r, ll i, ll vl) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id].val = vl;
            node[id].sl = 1;
            return;
        }

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, vl);
        updated(id * 2 + 1, mid + 1, r, i, vl);

        if(node[id * 2].val < node[id * 2 + 1].val) {
            node[id].val = node[id * 2].val;
            node[id].sl = node[id * 2].sl;
        } else if(node[id * 2].val == node[id * 2 + 1].val) {
            node[id].val = node[id * 2].val;
            node[id].sl = node[id * 2].sl + node[id * 2 + 1].sl;
        } else {
            node[id].val = node[id * 2 + 1].val;
            node[id].sl = node[id * 2 + 1].sl;
        }
    }

    KK get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return {(ll) 1e18, 0};
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;
        auto get1 = get(id * 2, l, mid, i, j);
        auto get2 = get(id * 2 + 1, mid + 1, r, i, j);

        if(get1.val < get2.val) return get1;
        else if(get1.val > get2.val) return get2;
        else return {get1.val, get1.sl + get2.sl};
    }
};
void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    while(q --) {
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1) {
            node.updated(1, 1, n, l, r);
        } else {
            auto k = node.get(1, 1, n, l, r);
            cout << k.val << ' ' << k.sl << el;
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