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
ll n, m, a[N + 1], dp[N + 1][101];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {

    if(a[1] == 0) {
        for(ll i = 1; i <= m; i ++) {
            dp[1][i] = 1;
        }
    } else {
        dp[1][a[1]] = 1;
    }

    for(ll i = 2; i <= n; i ++) {
        if(a[i] != 0) {
            dp[i][a[i]] = (dp[i - 1][a[i]] + (dp[i - 1][a[i] - 1] + dp[i - 1][a[i] + 1]) % mod) % mod;
            continue;
        }
        for(ll j = 1; j <= m; j ++) {
            dp[i][j] = ((dp[i][j] + dp[i - 1][j]) % mod + ( dp[i - 1][j + 1] + dp[i - 1][j - 1]) % mod) % mod;
        }
    }

}
void write() {
    ll ans = 0;

    if(a[n] != 0) cout << dp[n][a[n]];
    else {
        for(ll i = 1; i <= m; i ++) {
            ans = (ans + dp[n][i]) % mod;
        }
        cout << ans;
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