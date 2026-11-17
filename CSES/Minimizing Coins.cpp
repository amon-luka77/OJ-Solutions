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
const ll N = 1e6;
ll n, k, a[N + 1], dp[N + 1];
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(ll i = 1; i <= k; i ++) {
        dp[i] = 1e18;
    }
}   
void solve() {
    for(ll i = 1; i <= k; i ++) {
        for(ll j = 1; j <= n; j ++) {
            if(i >= a[j]) {
                dp[i] = min(dp[i], dp[i - a[j]] + 1);
            }
        }
    }
}
void write() {
    if(dp[k] == 1e18) cout << -1;
    else cout << dp[k];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}