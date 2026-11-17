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
const ll N = 100;
ll n, S, dp[N + 1][(ll)1e5 + 1];

struct kk {
    ll w, v, a;
};

kk b[N + 1];

void read() {
    cin >> n >> S;
    for(ll i = 1; i <= n; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        b[i] = {x, y, z};
    }
}

ll tinh(ll i, ll j, ll mid) {
    return dp[i - 1][j - mid * b[i].w] + mid * b[i].v;
}

void solve() {
    for(ll j = 1; j <= S; j ++) {
        for(ll i = 1; i <= n; i ++) {
            dp[i][j] = dp[i - 1][j];

            ll l = 1, r = min(b[i].a, j / b[i].w);

            for(ll k = l; k <= r; k ++) {
                dp[i][j] = max(dp[i][j], tinh(i, j, k));
            }
        }
    }

    cout << dp[n][S];
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