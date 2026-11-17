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
    for(ll i = 1; i <= t; i ++) {
        ll n; cin >> n;
        bool ok = 0;
        for(ll j = 1; j <= n; j ++) {
            ll x; cin >> x;
            if(!ok && x == 100) ok = 1;
        }

        if(ok) cout << "Yes";
        else cout << "No";
        cout << el;
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