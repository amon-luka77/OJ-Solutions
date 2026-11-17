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
string a, b;
ll n, m, k, dp[3][N + 1][N + 1][3];

void read() {
    cin >> n >> m >> k;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
}

void solve() {

    /*
    dp[i][j][t][l];
    1 --> i xau A
    1 --> j xau B
    co t xau
    l = 0 ko ghep
    l = 1 ghep voi xau truoc
    */

    dp[0][0][0][0] = 1;

    for(ll i = 1; i <= n; i ++) {

        for(ll j = 1; j <= m; j ++) {
            for(ll l = 1; l <= k; l ++) {
                dp[i % 2][j][l][0] = 0;
                dp[i % 2][j][l][1] = 0;
            }
        }

        dp[i % 2][0][0][0] = 1;

        for(ll j = 1; j <= m; j ++) {
            for(ll l = 1; l <= k; l ++) {
                dp[i % 2][j][l][0] = (dp[(i + 1) % 2][j][l][1] + dp[(i + 1) % 2][j][l][0]) % mod;

                if(a[i] == b[j]) {
                    dp[i % 2][j][l][1] = (dp[i % 2][j][l][1] + dp[(i + 1) % 2][j - 1][l - 1][1]) % mod;
                    dp[i % 2][j][l][1] = (dp[i % 2][j][l][1] + dp[(i + 1) % 2][j - 1][l - 1][0]) % mod;
                    dp[i % 2][j][l][1] = (dp[i % 2][j][l][1] + dp[(i + 1) % 2][j - 1][l][1]) % mod;
                }
            }
        }
    }

    cout << (dp[n % 2][m][k][0] + dp[n % 2][m][k][1]) % mod;
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