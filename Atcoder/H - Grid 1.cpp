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
const ll N = 1000, mod = 1e9 + 7;
ll n, m, dp[N + 1][N + 1]; 
char a[N + 1][N + 1];
vector<pair<ll, ll>> d = {{0, -1}, {-1, 0}};
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
}
void solve() {
    dp[1][1] = 1;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(a[i][j] == '#') continue;
            for(auto [x, y] : d) {
                ll new_i = i + x, new_j = j + y;
                if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || a[new_i][new_j] == '#') continue;
                dp[i][j] = (dp[i][j] + dp[new_i][new_j]) % mod;
            }
        }
    }
}
void write() {
    cout << dp[n][m];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}