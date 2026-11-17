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
ll q;
ll mu(ll n) {
    ll t = 1;
    for(ll i = 1; i <= n; i ++) {
        t *= 10;
    }
    return t;
}
void read() {
    cin >> q;
    while(q--) {
        ll l, r, t, k;
        cin >> l >> r >> t >> k;
        ll d = k / t;
        if(d == 0) {
            cout << 0 << el; 
            continue;
        }
        ll v = mu(d);
        cout << (r / v - (l - 1) / v) - (r / (v * 10) - (l - 1) / (v * 10)) << el;
    }
}
void solve() {

}
void write() {

}
int main() {
    boost;
    file("AMIZERO");
    read();
    solve();
    write();
    return 0;
}