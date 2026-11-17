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

const ll N = 1e6, base = 77, mod1 = 1e9, mod2 = 998244353;
ll n, q, hashT1 = 0, hashT2 = 0, mul1[N + 1], mul2[N + 1];
string s; 

set<pair<ll, ll>> ans;

void read() {
    cin >> n >> q >> s;

    s = ' ' + s;

    mul1[0] = 1;
    mul2[0] = 1;

    FOR(i, 1, n) {
        mul1[i] = (mul1[i - 1] * base) % mod1;
        mul2[i] = (mul2[i - 1] * base) % mod2;
        hashT1 = (hashT1 * base + (s[i] - 'a' + 1)) % mod1;
        hashT2 = (hashT2 * base + (s[i] - 'a' + 1)) % mod2;
    }
    ans.insert({hashT1, hashT2});
}

void solve() {
    FOR(i, 1, q) {
        ll x; char y; cin >> x >> y;
        hashT1 = (hashT1 - ((s[x] - 'a' + 1) * mul1[n - x] % mod1) + mod1) % mod1;
        hashT1 = (hashT1 + ((y - 'a' + 1) * mul1[n - x] % mod1)) % mod1; 
        hashT2 = (hashT2 - ((s[x] - 'a' + 1) * mul2[n - x] % mod2) + mod2) % mod2;
        hashT2 = (hashT2 + ((y - 'a' + 1) * mul2[n - x] % mod2)) % mod2; 
        s[x] = y;
        ans.insert({hashT1, hashT2});
    }

    cout << ans.size();
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