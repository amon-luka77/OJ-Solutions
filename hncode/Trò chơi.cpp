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
const ll N = 1e5;
ll n, q, a[N + 1], dp[N + 1][51][3];
void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    vector<ll> query;
    bool sub3 = 1;

    for(ll i = 1; i <= q; i ++) {
        ll x; cin >> x;
        if(sub3 && x > 50) sub3 = 0;
        query.pb(x);
    }

    if(sub3) {
        for(ll i = 1; i <= 50; i ++) {
            for(ll j = 1; j <= n; j ++) {
                dp[j][i][0] = max(dp[j - 1][i][0], dp[j - 1][i][1]);
                dp[j][i][1] = max(a[j] + dp[j - 1][i][1], a[j] + dp[j - 1][i - 1][0]);
            }
        }

        for(auto i : query) {
            cout << max(dp[n][i][0], dp[n][i][1]) << el;
        }
    } else {
        cout << 77 << el;
    }
}
void write() {

}
int main() {
    boost;
    file("TROCHOI");
    read();
    solve();
    write();
    return 0;
}