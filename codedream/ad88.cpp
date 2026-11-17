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
#define MASK(i) (1ULL << (i))
#define BIT(x, i) (((x) >> (i)) & 1ULL)

const ll N = 1e6;
ll q;

void read() {
    cin >> q;
}

void solve() {
    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y;
        if(x == 1) cout <<__builtin_popcountll(y) << el;
        else {
            cin >> z;
            if(x == 2) cout << BIT(y, z) << el;
            else if(x == 3) cout << (y | MASK(z)) << el;
            else if(x == 4) cout << (y & ~MASK(z)) << el;
            else if(x == 5) cout << (y ^ MASK(z)) << el;
            else if(x == 6) cout << (y ^ (MASK(z) - 1)) << el;
            else if(x == 7) cout << !(y & z) << el;
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