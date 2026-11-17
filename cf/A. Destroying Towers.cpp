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
ll t;

void read() {
    cin >> t;
    while(t --) {
        ll n; cin >> n;
        vector<ll> a(n + 1, 0), minValue(n + 1, 1e18);
        FOR(i, 1, n) {
            cin >> a[i];
            minValue[i] = min(minValue[i - 1], a[i]);
        }

        ll ans = 0;
        FOR(i, 1, n) {
            ans += minValue[i];
        }
        cout << ans << el;
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