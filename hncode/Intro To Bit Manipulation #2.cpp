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
ll n;

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
       ll l, r; cin >> l >> r;
       if(l == 1) {
        ll cnt = 0;
        for(ll j = 0; j <= 31; j ++) {
            cnt += ((r >> j) & 1LL);
        }
        cout << cnt << el;
       } else if(l == 2) {
        ll ans = -1;
        for(ll j = 0; j <= 31; j ++) {
            if((r >> j) & 1LL) ans = j;
        }
        cout << ans << el;
       } else {
        ll ans = -1;
        for(ll j = 0; j <= 31; j ++) {
            if((r >> j) & 1LL) {
                ans = j; 
                break;
            }
        }
        cout << ans << el;
       }
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