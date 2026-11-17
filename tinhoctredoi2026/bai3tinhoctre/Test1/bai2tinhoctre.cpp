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
const ll N = 2000;
ll n;
string x, y, z;
ll dpA[N + 5][N + 5], dpB[N + 5][N + 5], dpC[N + 5][N + 5];
ll ansA[N + 5][N + 5], ansB[N + 5][N + 5], ansC[N + 5][N + 5];

void read() {
    cin >> n;
    cin >> x >> y >> z;
    x = ' ' + x;
    y = ' ' + y;
    z = ' ' + z;
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));
            for(ll k = 1; k <= i; k ++) {
                for(ll l = j; l <= n; l ++) {
                    if(x[k] == y[l]) {
                        dp[k][l] = dp[k - 1][l - 1] + 1; 
                    } else {
                        dp[k][l] = 0;
                    }
                    ansA[i][j] = max(ansA[i][j], dp[k][l]);
                }
            }
        }
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            vector<vector<ll>> dp(n  + 1, vector<ll> (n + 1, 0));
            for(ll k = 1; k <= i; k ++) {
                for(ll l = j; l <= n; l ++) {
                    if(z[k] == x[l]) {
                        dp[k][l] = dp[k - 1][l - 1] + 1; 
                    } else {
                        dp[k][l] = 0;
                    }
                    ansB[i][j] = max(ansB[i][j], dp[k][l]);
                }
            }
        }
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));
            for(ll k = 1; k <= i; k ++) {
                for(ll l = j; l <= n; l ++) {
                    if(y[k] == z[l]) {
                        dp[k][l] = dp[k - 1][l - 1] + 1; 
                    } else {
                        dp[k][l] = 0;
                    }
                    ansC[i][j] = max(ansC[i][j], dp[k][l]);
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            for(ll k = 1; k <= n; k ++) {
                ans = max(ans, ansA[i][j] + ansB[k][i] + ansC[j][k]);
            }
        }
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