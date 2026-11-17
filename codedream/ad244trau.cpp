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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 0;
multiset<ll> a;
ll n;

void read() {
    cin >> n; a.insert(0);
    FOR(i, 1, n) {
        char x; ll y; cin >> x >> y;
        if(x == '+') a.insert(y);
        else if(x == '-') a.erase(a.find(y));
        else {
            ll res = 0;
            for(auto j : a) res = max(res, j ^ y);
            cout << res << el;
        }
    }
}

void solve() {

}

void write() {

}

int main() {
    boost;
    file("ad244");
    read();
    solve();
    write();
    return 0;
}