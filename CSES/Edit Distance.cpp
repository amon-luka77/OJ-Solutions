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
const ll N = 5e3;
string x, y;
ll n, m, dp[N + 1][N + 1];
void read() {
    cin >> x >> y;
    n = x.size(), m = y.size();
    x = ' ' + x; y = ' ' + y;
    
    for(ll i = 1; i <= n; i ++) dp[i][0] = i;
    for(ll i = 1; i <= m; i ++) dp[0][i] = i;
}
void solve() {
    dp[0][0] = 0;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1});
            }
        }
    }
}
void write() {
    cout << dp[n][m];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}