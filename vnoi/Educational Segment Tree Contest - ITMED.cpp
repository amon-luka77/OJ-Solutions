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
ll n, k, a[N + 1], dp[N + 1];

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, (ll)-1e18);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] = max(node[id], val);
            return;
        }

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, val);
        updated(id * 2 + 1, mid + 1, r, i, val);

        node[id] = max(node[id * 2], node[id * 2 + 1]);
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return LLONG_MIN;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return max(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
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
    ll ans = LLONG_MIN;
    
    for(ll i = 1; i <= n; i ++) {
        ll t = node.get(1, 1, n, max(1LL, i - k), i - 1);

        if(t == LLONG_MIN) t = 0;
        else t = max(0LL, t);

        dp[i] = a[i] + t;

        ans = max(ans, dp[i]);
        node.updated(1, 1, n, i, dp[i]);
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