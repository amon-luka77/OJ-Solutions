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
const ll N = 1e3;
ll n, m, a[N + 1], b[N + 1], dp[N + 1][N + 1];
pair<ll, ll> path[N + 1][N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(ll j = 1; j <= m; j ++) {
        cin >> b[j];
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(dp[i][j] == dp[i][j - 1]) {
                path[i][j] = {i, j - 1};
            }
            if(dp[i][j] == dp[i - 1][j]) {
                path[i][j] = {i - 1, j};
            }
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if(dp[i][j] == dp[i - 1][j - 1] + 1) {
                    path[i][j] = {i - 1, j - 1};
                }
            }
        }
    }
}
void write() {
    cout << dp[n][m] << el;
    vector<ll> trace;
    while(n > 0 && m > 0) {
        auto [i, j] = path[n][m];
        if(n == i + 1 && m == j + 1) {
            trace.pb(a[n]);
        }
        n = i, m = j;
    }
    for(ll i = trace.size() - 1; i >= 0; i --) {
        cout << trace[i] << ' ';
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}