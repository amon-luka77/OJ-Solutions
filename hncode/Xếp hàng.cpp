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
    ll min_n, max_n;
};

struct SegmentTree {
    vector<KK> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {(ll)1e18, (ll)-1e18});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id].min_n = a[l];
            node[id].max_n = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id].min_n = min(node[id * 2].min_n, node[id * 2 + 1].min_n);
        node[id].max_n = max(node[id * 2].max_n, node[id * 2 + 1].max_n);
    }

    KK get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return {(ll)1e18, (ll)-1e18};
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        auto get1 = get(id * 2, l, mid, i, j);
        auto get2 = get(id * 2 + 1, mid + 1, r, i, j);

        return {min(get1.min_n, get2.min_n), max(get1.max_n, get2.max_n)};
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
        ll l, r; cin >> l >> r;
        auto i = node.get(1, 1, n, l, r);
        cout << i.max_n - i.min_n << el;
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