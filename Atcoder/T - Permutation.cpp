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
const ll N = 3e3, mod = 1e9 + 7;
ll n, dp[N + 1][N + 1]; string s;
void read() {
    cin >> n >> s;
    s = ' ' + s;

    dp[0][1] = 1;
}
void solve() {
    for(ll i = 1; i < s.size(); i ++) {

        vector<ll> prefix(i + 5, 0);

        for(ll j = 1; j <= i + 1; j ++) {
            prefix[j] = (prefix[j - 1] + dp[i - 1][j]) % mod;
        }

        for(ll j = 1; j <= i + 1; j ++) {
            if(s[i] == '>') {
                dp[i][j] = (dp[i][j] + (mod + (prefix[i + 1] - prefix[j - 1]) % mod) % mod) % mod;
            } else {
                dp[i][j] = (dp[i][j] + prefix[j - 1] % mod) % mod;
            }
        }
    }

    ll ans = 0;

    for(ll i = 1; i <= n; i ++) {
        ans = (ans + dp[s.size() - 1][i]) % mod;
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