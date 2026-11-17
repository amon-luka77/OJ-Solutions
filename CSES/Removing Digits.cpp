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
ll n, dp[N + 1];
vector<ll> a;
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        dp[i] = 1e18;
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        
        ll t = i;

        while(t > 0) {
            ll k = t % 10;
            if(i >= k) dp[i] = min(dp[i], dp[i - k] + 1);
            t /= 10;
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