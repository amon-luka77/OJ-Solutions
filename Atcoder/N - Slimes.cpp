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
const ll N = 400;
ll n, a[N + 1], dp[N + 1][N + 1], prefix[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
}
void solve() {
    for(ll i = 1; i < n; i ++) {
        for(ll j = 1; j + i <= n; j ++) {
            ll l = j, r = i + j;
            dp[l][r] = 1e18;
            for(ll mid = l; mid < r; mid ++) {
                dp[l][r] = min(dp[l][mid] + dp[mid + 1][r] + prefix[r] - prefix[l - 1], dp[l][r]);
            }
        }
    }
}
void write() {
    cout << dp[1][n];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}