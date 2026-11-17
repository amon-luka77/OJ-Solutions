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
const ll N = 4000;
ll n, a[N + 1], dp[N + 1][N + 1][2], prefix[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j + i - 1 <= n; j ++) {
            ll l = j, r = j + i - 1;
            dp[l][r][0] = max(a[l] + prefix[r] - prefix[l] - dp[l + 1][r][1], a[r] + prefix[r - 1] - prefix[l - 1] - dp[l][r - 1][1]);
            dp[l][r][1] = max(a[l] + prefix[r] - prefix[l] - dp[l + 1][r][0], a[r] + prefix[r - 1] - prefix[l - 1] - dp[l][r - 1][0]);
        }
    }
}
void write() {
    cout << 2 * dp[1][n][0] - prefix[n];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}