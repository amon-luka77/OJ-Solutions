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
const ll N = 5e3;
ll n, m, a[N + 1], c[N + 1], dp[N + 1][N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= n; i ++) {
        cin >> c[i];
    }

}

void solve() {
    ll ans = -1e18;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            ll val = a[i] * c[j];
            dp[i][j] = max({val, dp[i - 1][j - 1] + val});
            ans = max(ans, dp[i][j]);
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