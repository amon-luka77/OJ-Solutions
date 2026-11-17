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

void read() {
    cin >> q;
    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        ll c = 0;
        
        for(ll j = 0; j <= 14; j ++) {
            ll rL = l & (1LL << j);
            ll rR = r & (1LL << j);
            if(j >= 0 && j <= 4) {
                c |= (rL ^ rR);
            } else if(j >= 5 && j <= 9) {
                c |= (rL & rR);
            } else {
                c |= (rL | rR);     
            }
        }

        cout << c << el;
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