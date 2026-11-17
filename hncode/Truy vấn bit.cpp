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
        ll val;
        bool lazy;
    };

    vector<NODE> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }

    void push(ll id, ll l, ll r) {
        if(!node[id].lazy) return;
        node[id].lazy = 0;

        ll mid = (l + r) >> 1;

        node[id * 2].val = (mid - l + 1) - node[id * 2].val;
        node[id * 2].lazy = (node[id * 2].lazy + 1) % 2;
        node[id * 2 + 1].val = (r - mid) - node[id * 2 + 1].val;
        node[id * 2 + 1].lazy = (node[id * 2 + 1].lazy + 1) % 2;

        return;
    }

    void updated(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            node[id].val = (r - l + 1) - node[id].val;
            node[id].lazy = (node[id].lazy + 1) % 2;
            return;
        }

        push(id, l, r);

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, j);
        updated(id * 2 + 1, mid + 1, r, i, j);

        node[id].val = node[id * 2].val + node[id * 2 + 1].val;
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id].val;

        push(id, l, r);

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

void read() {
    cin >> n >> m;
}
void solve() {
    SegmentTree node(n);

    for(ll i = 1; i <= m; i ++) {
        ll x, l, r; cin >> x >> l >> r;

        if(x == 0) {
            node.updated(1, 1, n, l, r);
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