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
bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.ft != y.ft) return x.ft < y.ft;
    else return x.sc > y.sc;
}
void read() {
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> a;
        for(ll i = 1; i <= n; i ++) {
            ll x, y; cin >> x >> y;
            a.pb({x, y});
        }
        sort(a.begin(), a.end(), cmp);
        vector<ll> dp(n + 1, 1);
        ll ans = 0;
        for(ll i = 0; i < a.size(); i ++) {
            for(ll j = i - 1; j >= 0; j --) {
                if(a[i].sc < a[j].sc) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << el;
    }
}
void solve() {

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
