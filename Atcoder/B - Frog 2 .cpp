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
ll n, k, a[N + 1], dp[N + 1];
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    
    for(ll i = 2; i <= n; i ++) {
        dp[i] = 1e18;
        for(ll j = i - 1; j >= max(1LL, i - k); j --) {
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }

}
void write() {
    cout << dp[n];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}