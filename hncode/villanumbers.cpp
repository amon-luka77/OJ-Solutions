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
const ll N = 1e4;
ll t;
void read() {
    cin >> t;
    while(t--) {
        ll c; cin >> c;
        bool ok = false;
        for(ll i = 1; i * i <= c; i ++) {
            if(c % i == 0) {
                ll x = max(c / i, i);
                ll y = min(c / i, i);
                if(x % 2 != y % 2) continue;
                cout << (x + y) / 2 << ' ' << (x - y) / 2 << el;
                ok = true; break;
            }
        }
        if(!ok) cout << 0 << ' ' << 0 << el;
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