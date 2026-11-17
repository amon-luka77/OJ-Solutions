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
    while(t --) {
        ll n, ans = 0; cin >> n;
        vector<ll> a(n + 1, 0);

        for(ll i = 1; i <= n; i ++) {
            cin >> a[i];
        }

        for(ll i = 1; i <= n; i ++) {
            vector<ll> b(n + 1, 0);

            for(ll j = 1; j <= n; j ++) {
                if(a[j] >= a[i]) b[j] = 1;
                else b[j] = -1;
            }

            ll sum = 0, cnt = 0;
            for(ll j = 1; j <= n; j ++) {
                sum += b[j];

                if(sum >= 1) {
                    sum = 0;
                    cnt ++;
                };
            }

            ans = max(ans, cnt);
            
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