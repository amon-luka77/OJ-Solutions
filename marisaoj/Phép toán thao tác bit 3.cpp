/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

const ll N = 0;
ll n = 0, q;

void read() {
    cin >> q;
    while(q --) {
        ll x, k; cin >> x;
        if(x == 1) {
            cin >> k;
            n ^= k;
        } else if(x == 2) {
            if(n == 0) continue;
            else {
                ll pos = __lg(n);
                n &= ~(1LL << pos);
            }
        } else {
            cout << __builtin_popcountll(n) << el;
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