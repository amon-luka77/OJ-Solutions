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
const ll N = 3000;
string x, y;
ll dp[N + 1][N + 1];
pair<ll, ll> path[N + 1][N + 1];
void read() {
    cin >> x >> y;
    x = ' ' + x;
    y = ' ' + y;
}
void solve() {
    for(ll i = 1; i < x.size(); i ++) {
        for(ll j = 1; j < y.size(); j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(dp[i][j] == dp[i - 1][j]) {
                path[i][j] = {i - 1, j};
            }
            if(dp[i][j] == dp[i][j - 1]) {
                path[i][j] = {i, j - 1};
            }
            if(x[i] == y[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                if(dp[i][j] == dp[i - 1][j - 1] + 1) {
                    path[i][j] = {i - 1, j - 1};
                }
            }
        }
    }
}
void write() {
    vector<char> ans;
    ll i = x.size() - 1, j = y.size() - 1;

    while(i != 0 && j != 0) {
        auto [l, r] = path[i][j];
        if(l + 1 == i && r + 1 == j) {
            ans.pb(x[i]);
        }

        i = l, j = r;
    }

    for(ll i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i];
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