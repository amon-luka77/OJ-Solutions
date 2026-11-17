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
const ll N = 1e6;
ll n, a[N + 1];

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] += 1;
            return;
        }

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i);
        updated(id * 2 + 1, mid + 1, r, i);

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
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    ll cnt = 0;
    SegmentTree node(n);
    unordered_map<ll, ll> tsl, tsr;
    for(ll i = 1; i < n; i ++) {
        tsl[a[i]] ++;
    }

    tsr[a[n]] ++;
    node.updated(1, 1, n, tsr[a[n]]);
    for(ll i = n - 1; i >= 1; i --) {
        ll k = node.get(1, 1, n, 1, tsl[a[i]] - 1);
        cnt += k;
        tsl[a[i]] --;
        tsr[a[i]] ++;
        node.updated(1, 1, n, tsr[a[i]]);
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