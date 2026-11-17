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
ll n, x, h[N + 1], s[N + 1], dp[N + 1];
void read() {
    cin >> n >> x;
    for(ll i = 1; i <= n; i ++) {
        cin >> h[i];
    }

    for(ll j = 1; j <= n; j ++) {
        cin >> s[j];
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = x; j >= 1; j --) {
            if(j >= h[i]) {
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
            }
        }
    }

}
void write() {
    cout << dp[x];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}