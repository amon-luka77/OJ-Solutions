
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
#define NAME "8H20"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 1e5;
const ll mod = 998244353;
ll n, q;
ll a[N + 1], b[N + 1];

ll power(ll x, ll y) {
    ll res = 1; x %= mod;
    while(y) {
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod; y >>= 1;
    } return res;
}

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

void cal() {
    ll res = 0;
    FOR(i, 1, n) res = (res + power(b[i], i)) % mod;
    cout << res << ' ';
}

void solve() {
    FOR(i, 1, q) {
        ll x; cin >> x;
        if(x == 1) {
            FOR(i, 1, n) b[i] = a[n - i + 1];
        } else if(x == 2) {
            FOR(i, 1, n) b[i] = n - a[i] + 1;
        } else {
            FOR(i, 1, n) b[a[i]] = i;
        } cal(); FOR(i, 1, n) a[i] = b[i];
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
