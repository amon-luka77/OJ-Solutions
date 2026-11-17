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
const ll N = 3e3;
ll n;
double a[N + 1], dp[N + 1][N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    // dp[i][j] i : 1 -> i, j cnt xu ngua
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i ++) {
        dp[i][0] = dp[i - 1][0] * (1 - a[i]);
    }

    for(ll j = 1; j <= n; j ++) {
        for(ll i = 1; i <= n; i ++) {
            dp[i][j] = dp[i - 1][j] * (1 - a[i]) + dp[i - 1][j - 1] * a[i];
        }
    }
}
void write() {
    double ans = 0;
    for(ll i = (n + 1) / 2; i <= n; i ++) {
        ans = (ans + dp[n][i]);
    }

    cout << fixed << setprecision(9) << ans;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}