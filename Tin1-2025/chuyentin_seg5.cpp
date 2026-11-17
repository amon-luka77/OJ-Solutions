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
const ll N = 3e5;
ll n, m, mark[N + 1];
struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id] = 1;
            return;
        }

        ll mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i ) return;
        if(node[id] == 0) return;

        if(l == r) {
            node[id] = 0;
            mark[l] = val;
            return;
        }

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, j, val);
        updated(id * 2 + 1, mid + 1, r, i, j, val);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }
};
void read() {
    cin >> n >> m;
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    while(m --) {
        ll l, r, x; cin >> l >> r >> x;
        node.updated(1, 1, n, l, x - 1, x);
        node.updated(1, 1, n, x + 1, r, x);
    }
}
void write() {
    for(ll i = 1; i <= n; i ++) {
        cout << mark[i] << ' ';
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}