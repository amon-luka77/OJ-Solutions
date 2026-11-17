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
const ll N = 0;
ll n;
vector<ll> a, b;
struct SegmentTree {
    vector<ll> node;

    SegmentTree (ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] += val;
            return;
        }

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, val);
        updated(id * 2 + 1, mid + 1, r, i, val);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;
        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};
void read() {
    cin >> n;
    a.assign(n + 1, 0);
    b.assign(n + 1, 0);
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i]; b[i] = a[i];
    }
    unordered_map<ll, ll> ts;
    sort(b + 1, b + n + 1);
    for(ll i = 1; i <= n; i ++) {
        if(ts[b[i]] == 0) ts[b[i]] = i;
    }
    for(ll i = 1; i <= n; i ++) {
        a[i] = ts[a[i]];
    }
}
void solve() {
    ll cnt = 0;
    SegmentTree left(n), right(n);
    for(ll i = n; i >= 1; i --) {
        right.updated(1, 1, n, a[i], 1);
    }

    for(ll i = 2; i < n; i ++) {
        right.updated(1, 1, n, a[i], -1);
        cnt += left.get(1, 1, n, a[i] + 1, n) * right.get(1, 1, n, 1, a[i] - 1);
        left.updated(1, 1, n, a[i], 1);
    }

    cout << cnt;
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