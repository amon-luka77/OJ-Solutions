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
const ll N = 1000, mod = 1e9 + 7;
ll n, m, dp[N + 1][N + 1];
char a[N + 1][N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}};
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            if(a[i][j] == '*') continue;
            if(i == 1 & j == 1) {
                dp[i][j] = 1;
                continue;
            }
            if(i > 1 && a[i - 1][j] != '*') dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if(j > 1 && a[i][j - 1] != '*') dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
}
void write() {
    cout << dp[n][n];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}