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
const ll N = 2000, mod = 123456789;
ll n, k, a[N + 1], idx[N + 1], dp[N + 1][N + 1];

void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= n; i ++) {
        ll pos = 0;

        for(ll j = i - 1; j >= 1; j --) {
            if(a[i] == a[j]) {
                pos = j;
                break;
            }
        }

        if(pos == 0) {
            dp[i][1] = 1;
            pos = 1;
        }
        idx[i] = pos;
    }

    ll ans = 0;

    for(ll j = 2; j <= k; j ++) {
        vector<ll> prefix(n + 1, 0);

        for(ll i = 1; i <= n; i ++) {
            prefix[i] = (prefix[i - 1] + dp[i][j - 1] % mod) % mod;
        }

        for(ll i = 1; i <= n; i ++) {
            dp[i][j] = (mod + (prefix[i - 1] - prefix[idx[i] - 1]) % mod) % mod;
            if(j == k) {
                ans = (ans + dp[i][j]) % mod;
            }
        }
    }

    cout << ans;
}

void solve() {

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