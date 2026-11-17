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
const ll N = 1000;
string s;
ll n, a[N + 1], dp[N + 1][N + 1];
void read() {
    cin >> s;
    n = s.size();
    s = ' ' + s;
    for(ll i = 1; i < s.size(); i ++) {
        a[i] = s[i] - 'A';
    }
}
void solve() {
    /* f[i, j] = i --> j số xau dx để i -> j là sau đối xứng
    a[i] == a[j] --> f[i, j] = f[i, j - 1] + f[i + 1, j] - f[i + 1, j - 1] + f[i + 1, j - 1] + 1;
    a[i] != a[j] --> f[i, j] = f[i, j - 1] + f[i + 1, j] - f[i + 1, j - 1]
    */
    for(ll i = 1; i <= n; i ++) {
        dp[i][i] = 1;
    }

    for(ll i = 2; i <= n; i ++) {
        for(ll j = 1; j + i - 1 <= n; j ++) {
            ll l = j, r = i + j - 1;
            if(a[l] == a[r]) dp[l][r] = dp[l][r - 1] + dp[l + 1][r] + 1;
            else dp[l][r] = dp[l][r - 1] + dp[l + 1][r] - dp[l + 1][r - 1];
        }
    }

    cout << dp[1][n];
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