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
ll n, w, dp[(ll)1e5];
struct kk {
    ll weight, val;
} a[N + 1];
void read() {
    cin >> n >> w;
    for(ll i = 1; i <= n; i ++) {
        ll x, y; cin >> x >> y;
        a[i] = {x, y};
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = w; j >= 1; j --) {
            if(a[i].weight <= j) dp[j] = max(dp[j], dp[j - a[i].weight] + a[i].val);
        }
    }
    
    cout << dp[w];
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