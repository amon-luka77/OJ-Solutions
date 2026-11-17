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
const ll N = 1e5;
ll n, k, a[N + 5], dp[N + 1][25];

void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}

// dp[i][r] 
// 1 -> i va i thuoc nhom r

void solve() {
    for(ll i = 1; i <= n; i ++) {
        dp[i][0] = -1e18;
    }
    
    for(ll j = 1; j <= k; j ++) {
        for(ll i = 1; i <= n; i ++) {
            ll maxI = -1e18, minI = 1e18;
            for(ll l = i; l >= 1; l --) {
                maxI = max(maxI, a[l]);
                minI = min(minI, a[l]);

                dp[i][j] = max(dp[i][j], dp[l - 1][j - 1] + maxI + minI);
            }
        }
    }

    cout << dp[n][k];
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