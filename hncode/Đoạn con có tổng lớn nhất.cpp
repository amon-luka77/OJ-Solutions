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
const ll N = 5e4;
ll n, m, a[N + 1];

struct SegmentTree {
    struct NODE {
        ll val, left, right, sum;
    };

    vector<NODE> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0, 0, 0});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id] = {a[l], a[l], a[l], a[l]};
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id].val = max({node[id * 2].val, node[id * 2 + 1].val, node[id * 2].right + node[id * 2 + 1].left});
        node[id].sum = node[id * 2].sum + node[id * 2 + 1].sum;
        node[id].left = max(node[id * 2].left, node[id * 2].sum + node[id * 2 + 1].left);
        node[id].right = max(node[id * 2 + 1].right, node[id * 2].right + node[id * 2 + 1].sum);
    }

    NODE get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return {(ll)-1e18, 0, 0, 0};
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        auto get1 = get(id * 2, l, mid, i, j);
        auto get2 = get(id * 2 + 1, mid + 1, r, i, j);

        if(get1.val == -1e18) return get2;
        if(get2.val == -1e18) return get1;

        return {max({get1.val, get2.val, get1.right + get2.left}), max(get1.left, get1.sum + get2.left), max(get2.right, get2.sum + get1.right), get1.sum + get2.sum};
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
        ll x, y; cin >> x >> y;
        cout << node.get(1, 1, n, x, y).val << el;
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