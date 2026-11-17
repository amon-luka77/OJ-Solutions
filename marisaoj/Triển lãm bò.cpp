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
const ll N = 500;
ll n;
pair<ll, ll> a[N + 1], dp[N + 1][N + 1];

void read() {
    cin >> n;

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i].ft >> a[i].sc;

        if(a[i].ft >= 0 && a[i].sc >= 0) {
            dp[i][i].ft = a[i].ft;
            dp[i][i].sc = a[i].sc;
        }
    }
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            for(ll k = i + 1; k <= j - 1; k ++) {
                ll x = dp[i][k - 1].ft + dp[k][j].ft;
                ll y = dp[k][j].sc + dp[i][k - 1].sc;

                if(x >= 0 && y >= 0 && dp[i][j].ft + dp[i][j].sc < x + y) {
                    dp[i][j].ft = x;
                    dp[i][j].sc = y;
                }
            }
        }
    }

    cout << dp[1][n].ft + dp[1][n].sc;
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