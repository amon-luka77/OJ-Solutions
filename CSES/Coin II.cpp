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
const ll N = 1e6, mod = 1e9 + 7;
ll n, k, a[N + 1], dp[N + 1];
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    dp[0] = 1;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j  <= k ; j++) {
            if(j >= a[i]) {
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            }
        }
    }
}
void write() {
    cout << dp[k];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}