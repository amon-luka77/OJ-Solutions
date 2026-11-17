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
const ll N = 0;
ll t;
char a[4][(ll)2e5];
void read() {
    cin >> t;
}
void solve() {
    while(t --) {
        ll n; cin >> n;

        vector<ll> dp(n + 1, 0);

        for(ll i = 1; i <= 2; i ++) {
            for(ll j = 1; j <= n; j ++) {
                cin >> a[i][j];
            }
        }

        dp[1] = (a[1][1] != a[2][1]);

        for(ll i = 2; i <= n; i ++) {
            dp[i] = min(dp[i - 2] + (a[1][i] != a[1][i - 1]) + (a[2][i] != a[2][i - 1]), dp[i - 1] + (a[1][i] != a[2][i]));
        }

        cout << dp[n] << el;
    }
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