#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define el '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define NAME "8E02"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 1e6;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

ll check(ll x, ll y) {
    ll res = 0;
    FOR(i, 0, 18) if(BIT(x, i) && BIT(x, i + 1) && BIT(y, i) && BIT(y, i + 1)) res ++;
    return res;
}

void solve() {
    FOR(i, 1, n) {
        ll ans = 0;
        FOR(j, 1, n) {
            if(i != j) ans = max(ans, check(a[i], a[j]));
        } cout << ans << ' '; cerr << ans << ' ';
    }
}

void write() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    file();
    read();
    solve();
    write();
    return 0;
}
