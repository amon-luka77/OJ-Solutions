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
ll n, dp[N + 1];
void read() {
    cin >> n;
}

ll power(ll t, ll k) {
    if(k == 0) return 1;
    ll res = power(t, k / 2);

    ll ans = (res * res) % mod;

    if(k % 2) ans = (ans * t) % mod;

    return ans;
}

void solve() {
    ll sum = (n + 1) * n / 2;
    if(sum % 2 != 0) {
        cout << 0;
        exit(0);
    }
    
    dp[0] = 1;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = sum / 2; j >= 1; j --) {
            if(j >= i) {
                dp[j] = (dp[j] + dp[j - i]) % mod;
            }
        }
    }

    ll t = power(2, mod - 2);
    cout << dp[sum / 2] * t % mod;
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