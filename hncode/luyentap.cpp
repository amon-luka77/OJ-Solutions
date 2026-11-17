#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e7;
ll n, k, a[(ll)1e6 + 1], cnt[N + 1];
vector<ll> b;
void read() {
    cin >> n >> k;
    ll mu = 0;
    for(ll i = 1; i <= N; i ++) {
        for(ll j = i; j <= N; j += i) {
            cnt[j] ++;
        }
    }
    for(ll i = 1; i <= n; i ++) {
        ll x; cin >> x;
        a[i] = cnt[x];
        mu = max(mu, a[i]);
    }
    ll l = 1, r = 1, ans = 1e9, sum = 0;
    while(l <= r && r <= n) {
        sum += (a[r] == mu);
        while(l <= r && sum >= k) {
            ans = min(ans, r - l + 1);
            sum -= (a[l] == mu);
            l ++;
        }
        r ++;
    } 
    if(ans != 1e9) cout << ans;
    else cout << -1;
}
void solve() {

}
void write() {

}
int main() {
    boost;
    file("DOANCON");
    read();
    solve();
    write();
    return 0;
}