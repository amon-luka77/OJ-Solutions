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
const ll N = 1e5, mod = 2111992;
ll n, k, dp[N + 1][3];
void read() {
    cin >> n >> k;
}
void solve() {  
    // dp(i) so cach xep con bo tu 1 -> i
    dp[1][1] = 1;
    dp[1][2] = 1;
    for(ll i = 2; i <= n; i ++) {
        dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
        if(i >= k) dp[i][2] = (dp[i - k][1] + dp[i - k][2]) % mod;
    }

    cout << (dp[n][1] + dp[n][2]) % mod;
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