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
struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id] = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id] = min(node[id * 2], node[id * 2 + 1]);
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 1e18;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return min(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
    }
};

void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    for(ll i = 1; i <= n; i ++) {
        ll r = i + k - 1;
        if(r > n) break;
        cout << node.get(1, 1, n, i, r) << ' ';
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