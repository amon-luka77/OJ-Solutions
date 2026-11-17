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
ll n, k, a[N + 1];
struct kk {
    ll max_n, min_n;
};
struct SegmentTree {
    vector<kk> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id].min_n = a[l];
            node[id].max_n = a[r];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id].min_n = min(node[id * 2].min_n, node[id * 2 + 1].min_n);
        node[id].max_n = max(node[id * 2].max_n, node[id * 2 + 1].max_n);
    }

    ll get_min(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 1e18;
        if(i <= l && r <= j) return node[id].min_n;

        ll mid = (l + r) >> 1;

        return min(get_min(id * 2, l, mid, i, j), get_min(id * 2 + 1, mid + 1, r, i, j));
    }

    ll get_max(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return -1e18;
        if(i <= l && r <= j) return node[id].max_n;

        ll mid = (l + r) >> 1;

        return max(get_max(id * 2, l, mid, i, j), get_max(id * 2 + 1, mid + 1, r, i, j));
    }
};
void read() {
    cin >> n >> k;
    for(ll i= 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    ll ans = -1e18;
    ll l = 1;
    for(ll r = 1; r <= n; r ++) {
        while(node.get_max(1, 1, n, l, r) - node.get_min(1, 1, n, l, r) > k) {
            l ++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans;
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