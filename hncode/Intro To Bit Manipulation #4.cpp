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
ll a = 0, n;

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        ll x, l; cin >> x;
        if(x == 1) {
            cin >> l;
            a ^= l;
        } else if(x == 2) {
            for(ll j = 31; j >= 0; j --) {
                if((a >> j) & 1) {
                    a &= ~(1 << j);
                    break;
                }
            }
        } else {
            ll cnt = 0;
            for(ll j = 0; j <= 31; j ++) {
                if((a >> j) & 1) cnt ++;
            }

            cout << cnt << el;
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