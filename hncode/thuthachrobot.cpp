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
const ll N = 1000;
ll n, m, q, k, ans[(ll)1e6 + 1];
unordered_map<ll, vector<pair<ll, ll>>> a;
struct seg {
    vector<ll> node;

    void SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] = val;
            return;
        }

        ll mid = l +(r - l) / 2;
        updated(id * 2, l, mid, i, val);
        updated(id * 2 + 1, mid + 1, r, i, val);

        node[id] = max(node[id * 2], node[id * 2 + 1]);
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = l + (r - l) / 2;

        return max(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
    }
};
void read() {
    cin >> n >> m >> q >> k;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            ll x; cin >> x;
            a[x % k].pb({i, j});
        }
    }
}
void solve() {
    for(ll i = 0; i < k; i ++) {
        if(a[i].empty()) continue;
        vector<pair<ll, ll>> b = a[i];
        seg c; c.SegmentTree(m);
        vector<ll> dp(b.size());
        for(ll i1 = 0; i1 < b.size(); i1 ++) {
            dp[i1] = 1;
            ll t = c.get(1, 0, m, 0, b[i1].sc);
            dp[i1] = max(dp[i1], t + 1);
            c.updated(1, 0, m, b[i1].sc, dp[i1]);
            ans[i] = max(ans[i], dp[i1]);
        }
    }
    while(q--) {
        ll x; cin >> x;
        cout << ans[x] << el;
    }
}
void write() {

}
int main() {
    boost;
    file("ROBOT");
    read();
    solve();
    write();
    return 0;
}