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
const ll N = 100;
string s;
ll n, dp[N + 1][N + 1];

void read() {
    cin >> s;
    n = s.size();
    s = ' ' + s;
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = i; j <= n; j ++) {
            dp[i][j] = 1e18;
        }
    }

    for(ll i = 1; i <= n; i ++) {
        dp[i][i] = 1;
    }

    for(ll k = 1; k < n; k ++) {
        for(ll l = 1; l + k <= n; l ++) {
            ll r = l + k;
            if(s[l] == '[' && s[r] == ']' || s[l] == '(' && s[r] == ')') {
                dp[l][r] = dp[l + 1][r - 1];
            }

            for(ll i = l; i <= r; i ++) {
                dp[l][r] = min({dp[l][r], dp[l][i] + dp[i + 1][r], dp[l][i - 1] + dp[i][r]});
            }
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