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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5;
ll n, m, b[N + 1];
multiset<ll> a;

void read() {
    cin >> n >> m;
    FOR(i, 1, n) {
        ll x; cin >> x;
        a.insert(x);
    }

    FOR(i, 1, m) cin >> b[i];

    FOR(i, 1, m) {
        auto it = a.upper_bound(b[i]);
        if(it != a.begin()) {
            it --;
            cout << *it << el;
            a.erase(it);
        } else {
            cout << -1 << el;
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