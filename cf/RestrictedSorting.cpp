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
void read() {
    cin >> t;
}
void solve() {
    while(t--) {
        ll n, ans = 1e18; cin >> n;
        vector<ll> a(n + 1, 0), b(n + 1, 0);
        for(ll i = 1; i <= n; i ++) {
            cin >> a[i]; b[i] = a[i];
        }
        sort(b.begin() + 1, b.end());
        for(ll i = 1; i <= n; i ++) {
            if(a[i] != b[i]) {
                ans = min(ans, max(a[i] - b[1], b[n] - a[i]));
            }
        }
        if(ans != 1e18) cout << ans << el;
        else cout << -1 << el;
    }
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