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

const ll N = 1e3;
ll n, k, a[N + 1];
ll res = 0;

void read() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
}

bool check(ll i) {
    if(i - 1 >= 1 && a[i] < a[i - 1] - k) return 1;
    if(i + 1 <= n && a[i] < a[i + 1] - k) return 1;
    return 0;
}

void cal(ll i) {
    ll maxVal = 0;
    if(i - 1 >= 1 && a[i] < a[i - 1] - k) maxVal = max(maxVal, (a[i - 1] - k) - a[i]);
    if(i + 1 <= n && a[i] < a[i + 1] - k) maxVal = max(maxVal, (a[i + 1] - k) - a[i]);
    res += maxVal; a[i] += maxVal;
}

void solve() {
    while(1) {
        bool ok = 1;
        FOR(i, 1, n) if(check(i)) {
            cal(i); ok = 0; break;
        } if(ok) break;
    } cout << res;
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
