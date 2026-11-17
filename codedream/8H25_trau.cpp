
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
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e6;
ll n, a[2 * N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {cin >> a[i]; a[i + n] = a[i];}
}

void solve() {
    ll ans = 0;
    FOR(i, 1 , n) {
        ll j = i + n - 1;
        ll res = 0, maxVal = 0;
        FOR(k, i, j) {res += (a[k] > maxVal); maxVal = max(maxVal, a[k]);}
        ans = max(ans, res);
    } cout << ans;
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
