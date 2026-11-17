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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "GCDFACT"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 1e5;
ll n, t, a[N + 1];

void read() {
    cin >> t;
}

void solve() {
    while(t --) {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        ll d1 = a[1], d2 = 0;
        FOR(i, 2, n) d1 = __gcd(a[i], d1);
        FOR(i, 1, n) {
            ll x = 1;
            FOR(j, 1, a[i]) x *= j;
            d2 = (i == 1 ? x : __gcd(d2, x));
        } cout << (d1 == d2 ? "YES\n" : "NO\n");
        cerr << (d1 == d2 ? "YES\n" : "NO\n");
    }
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}
