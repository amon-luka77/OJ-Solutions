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
ll n, a[N + 1][4], dp[N + 1][4];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= 3; j ++) {
            cin >> a[i][j];
        }
    }
}   
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= 3; j ++) {
            for(ll k = 1; k <= 3; k ++) {
                if(k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + a[i][j]);
            }
        }
    }
}
void write() {
    cout << max({dp[n][1], dp[n][2], dp[n][3]});
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}