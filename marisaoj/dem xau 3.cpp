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

const ll N = 1e5, block = 320, base = 256, mod = 998244353;
ll n, h[N + 1], mul[N + 1];
string s;
vector<ll> b[block + 1];

ll getHash(ll l, ll r) {
    return (h[r] - h[l - 1] * mul[r - l + 1] % mod + mod) % mod;
}

void read() {
    cin >> s; n = s.size(); s = ' ' + s;

    mul[0] = 1;
    FOR(i, 1, n) {
        h[i]  =(h[i - 1] * base + s[i] % mod) % mod;
        mul[i] = (mul[i - 1] * base) % mod;
    }

    FOR(i, 1, block) {
        FOR(l, 1, n - i + 1) {
            ll r = l + i - 1;
            b[i].pb(getHash(l, r));
        }
        sort(all(b[i]));
    }
}

void solve() {
    ll q; cin >> q;
    while(q --) {
        string k; cin >> k;
        ll hashK = 0;
        FOR(i, 0, k.size() - 1) hashK = (hashK * base + k[i]) % mod;
        if(k.size() <= block) {
            cout << upper_bound(all(b[k.size()]), hashK) - lower_bound(all(b[k.size()]), hashK) << el;
        } else {
            ll cnt = 0;
            FOR(r, k.size(), n) if(getHash(r - k.size() + 1, r) == hashK) cnt ++;
            cout << cnt << el;
        }
    }
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