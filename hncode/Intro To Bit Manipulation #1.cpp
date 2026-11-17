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
    ll a = 0;
    for(ll i = 1; i <= n; i ++) {
        ll l, r; cin >> l >> r;
        if(l == 1) {
            a |= (1LL << r);
        } else if(l == 2) {
            a &= ~(1LL << r);
        } else {
            a ^= (1LL << r);
        }

        cout << a << el;
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