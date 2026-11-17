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
ll t, m, q;
void read() {
    cin >> t;
}
void solve() {
    while(t --) {
        cin >> q >> m;
        vector<ll> query(q + 1, 0);

        ll value = 1;

        for(ll i = 1; i <= q; i ++) {
            ll x, y; cin >> x >> y;
            if(x == 1) {
                value = (value * y % m) % m;
                query[i] = y;
            } else {
                value /= query[y];
            }

            cout << value % m << el;
        }
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