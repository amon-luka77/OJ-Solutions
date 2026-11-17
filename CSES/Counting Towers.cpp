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
const ll N = 1e6, mod = 1e9 + 7;
ll t, n, dp[N + 1][3];
void read() {
    cin >> t;
}
void solve() {
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(ll i = 2; i <= N; i ++) {
        dp[i][0] = (2 * dp[i - 1][0] % mod + dp[i - 1][1]) % mod;
        dp[i][1] = (4 * dp[i - 1][1] % mod + dp[i - 1][0]) % mod;
    }
}
void write() {
    while(t --) {
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << el;
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