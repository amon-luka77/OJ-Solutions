#include<bits/stdc++.h>
#define ll int
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
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e6;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

ll b[MASK(20) + 1];

// 7 = 111
// 3 = 011

void solve() {
    FOR(i, 1, n) {
        ll mask = a[i] & (a[i] << 1);
        for(ll sub = mask; sub > 0; sub = (sub - 1) & mask) b[sub] ++;
    }

    FOR(i, 1, n) {
        ll ans = 0, mask = a[i] & (a[i] << 1);
        for(ll sub = mask; sub > 0; sub = (sub - 1) & mask) {
            b[sub] --;
            if(b[sub] && ans < __builtin_popcount(sub)) ans = __builtin_popcount(sub);
            b[sub] ++;
        } cout << ans << ' ';
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
