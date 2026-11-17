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
const ll N = 1e5, mod = 1e9 + 7;
ll n, k, a[N + 1], dp[N + 1][11];
struct SegmentTree {
    vector<vector<ll>> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 5, vector<ll>(15, 0));
    }

    void updated(ll id, ll l, ll r, ll i, ll val, ll idx) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id][idx] = (node[id][idx] + val) % mod;
            return;
        }

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, val, idx);
        updated(id * 2 + 1, mid + 1, r, i, val, idx);

        node[id][idx] = (node[id * 2][idx] + node[id * 2 + 1][idx]) % mod;
    }

    ll get(ll id, ll l, ll r, ll i, ll j, ll idx) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id][idx] % mod;

        ll mid = (l + r) >> 1;
        
        return (get(id * 2, l, mid, i, j, idx) + get(id * 2 + 1, mid + 1, r, i, j, idx)) % mod;
    }
};
void read() {   
    cin >> n >> k;
    k ++;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    for(ll i = 1; i <= n; i ++) {
        dp[i][1] = 1;
        node.updated(1, 1, n, a[i], dp[i][1], 1);
        for(ll j = 2; j <= k; j ++) {
            dp[i][j] = node.get(1, 1, n, 1, a[i] - 1, j - 1) % mod;
            node.updated(1, 1, n, a[i], dp[i][j], j);
        }
    }

    ll sum = 0;
    for(ll i = 1; i <= n; i ++) {
        sum = (sum + dp[i][k]) % mod;
    }
    cout << sum;
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