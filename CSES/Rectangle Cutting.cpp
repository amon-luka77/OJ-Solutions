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
const ll N = 500;
ll n, m, dp[N + 1][N + 1];
void read() {
    cin >> n >> m;
    ll n_1 = n, m_1 = m;
    n = min(n_1, m_1);
    m = max(n_1, m_1);
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            dp[i][j] = 1e18;
        }
    }

}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = i; j <= m; j ++) {
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }

            for(ll k = 1; k < j; k ++) {
                dp[i][j] = min(dp[i][j], dp[min(i, k)][max(i, k)] + dp[min(i, j - k)][max(i, j - k)] + 1);
            }

            for(ll k = 1; k < i; k ++) {
                dp[i][j] = min(dp[i][j], dp[min(k, j)][max(k, j)] + dp[min(i - k, j)][max(i - k, j)] + 1);
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