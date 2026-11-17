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

const ll N = 1e5, mod = 1e9, base = 77;
ll n, m; string s, t;

ll h[N + 1], mul[N + 1];

void read() {
    cin >> t >> s;

    n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    mul[0] = 1;

    FOR(i, 1, n) {
        h[i] = (h[i - 1] * base + (s[i] - 'A' + 1)) % mod;
        mul[i] = (mul[i - 1] * base) % mod;
    }
}

ll getHash(ll l, ll r) {
    return (h[r] - h[l - 1] * mul[r - l + 1] % mod + mod) % mod;
}

void solve() {
    ll hashT = 0, cnt = 0;

    FOR(i, 1, m) {
        hashT = (hashT * base + (t[i] - 'A' + 1)) % mod;
    }

    // n - i + 1 <= m
    FOR(i, 1, n - m + 1) {
        if(hashT == getHash(i, i + m - 1)) {
            cnt ++;
        }
    }

    cout << cnt;
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