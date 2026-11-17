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
const ll N = 1e5;
ll n, m, a[N + 1], cnt[N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] <= n) {
            cnt[a[i]] ++;
        }
    }
}
void solve() {
    vector<ll> value;
    vector<vector<ll>> prefix_sum;

    for(ll i = 1; i <= n; i ++) {
        if(cnt[i] >= i) {
            value.pb(i);
            vector<ll> prefix(n + 2, 0);
            prefix[0] = i;
            for(ll j = 1; j <= n; j ++) {
                prefix[j] = prefix[j - 1] + (a[j] == i);
            }
            prefix_sum.pb(prefix);
        }
    }

    for(ll i = 1; i <= m; i ++) {
        ll l, r; cin >> l >> r;

        ll ans = 0;

        for(auto &prefix : prefix_sum) {
            if(prefix[r] - prefix[l - 1] == prefix[0]) ans ++;
        }

        cout << ans << el;
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