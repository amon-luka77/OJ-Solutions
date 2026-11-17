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
ll n, a[N + 1], dp[N + 1][N + 1], vs[N + 1][N + 1];

void read() {
    cin >> n;    
    
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            dp[i][j] = 1e18;
            vs[i][j] = -1;
        }
    }

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        dp[i][i] = 1;
        vs[i][i] = a[i];
    }
}

void solve() {
    for(ll k = 1; k < n; k ++) {
        for(ll i = 1; i + k <= n; i ++) {
            ll j = i + k;
            for(ll l = i; l < j; l ++) {
                dp[i][j] = min(dp[i][j], dp[i][l] + dp[l + 1][j]);
                if(vs[i][l] != -1 && vs[i][l] == vs[l + 1][j]) {
                    if(dp[i][j] > 1) {
                        dp[i][j] = 1;
                        vs[i][j] = vs[i][l] + 1;
                    }
                }
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