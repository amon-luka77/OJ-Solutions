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
ll n, k, a[101], dp[101][N + 1], prefix[N + 1];
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    dp[0][0] = 1;

    for(ll i = 1; i <= n; i ++) { 

        prefix[0] = dp[i - 1][0];
        for(ll j = 1; j <= k; j ++) {
            prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % mod;
        }

        for(ll j = 0; j <= k; j ++) {
            // dp[i][j] = dp[i - 1][j - 0] + .. + dp[i - 1][j - a[i]];
            //          = prefix[j] - prefix[j - a[i] - 1];
            dp[i][j] = prefix[j] % mod;
            if(j > a[i]) dp[i][j] = (mod + (dp[i][j] - prefix[j - a[i] - 1]) % mod) % mod;
        }

    }
}
void write() {
    cout << dp[n][k];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}