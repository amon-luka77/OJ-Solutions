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
ll t;

void read() {
    cin >> t;
}
void solve() {
    while(t --) {
        ll n, m, k = 0, k1 = 0, ans = 0;
        vector<ll> sl, sc;

        cin >> n >> m;

        for(ll i = 1; i <= n; i ++) {
            ll x; cin >> x;
            ans += x;
            if(i % 2) sl.pb(x);
            else sc.pb(x);
        }

        for(ll i = 1; i <= m; i ++) {
            ll x; cin >> x;
            k += (x % 2);
            k1 += !(x % 2);
        }
        sort(all(sl), greater<ll>());
        sort(all(sc), greater<ll>());

        for(ll i = 0; i < sl.size(); i ++) {
            if(k == 0) break;
            ans -= sl[i];
            k --;
        }

        for(ll i = 0; i < sc.size(); i ++) {
            if(k1 == 0) break;
            ans -= sc[i];
            k1 --;
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