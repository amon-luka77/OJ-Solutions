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
ll t, n, m, a[N + 1], b[N + 1], dp[2 * N + 1];
void read() {
    cin >> t >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cin >> m;
    for(ll i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
}
void solve() {
    
    for(ll i = 1; i <= m; i ++) {
        for(ll j = t; j >= 0; j --) {
            if(j >= b[i]) dp[j] = max(dp[j], dp[j - b[i]] + 1);
        }
    }

    ll ans = 0, sum = 0;
    for(ll i = 1; i <= n; i ++) {
        sum += a[i];
        if(sum > t) break;
        ans = max(ans, i + dp[t]);
        ll sum2 = 0;
        for(ll j = i + 1; j <= n; j ++) {
            sum2 += a[j];
            if(sum2 > t) break;
            ans = max(ans, j + dp[t - sum2]);
        }
    }

    sum = 0;
    for(ll i = 1; i <= n; i ++) {
        sum += a[i];
        if(sum > t) break;
        ll cnt = i + dp[t - sum];

        ll sum2 = 0;
        for(ll j = i + 1; j <= n; j ++) {
            sum2 += a[j];
            if(sum2 > t) break;
            cnt ++;
        }

        ans = max(ans, cnt);
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