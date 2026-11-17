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
const ll N = 50;
ll n, a[N + 1], dp[N + 1][N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        dp[i][i] = 1;
    }
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j + i <= n; j ++) {
            ll l = j, r = j + i;
            dp[l][r] = dp[l][r - 1] + 1;
            for(ll k = r - 1; k >= l; k --) {
                if(a[r] == a[k]) {
                    dp[l][r] = min(dp[l][r], dp[l][k - 1] + dp[k + 1][r]);
                }
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