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
#define mask(i) (1 << (i))
using namespace std;

const ll N = 1e5, LOG = 19, mod = 1e9 + 7;
ll n, a[N + 1], calGcd[N + 1][LOG + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) calGcd[i][0] = a[i];
    FOR(j, 1, LOG) FOR(i, 1, n - mask(j) + 1) {
        calGcd[i][j] = __gcd(calGcd[i][j - 1], calGcd[i + mask(j - 1)][j - 1]);
    }
}


ll getGcd(ll l, ll r) {
    ll k = __lg(r - l + 1);
    return __gcd(calGcd[l][k], calGcd[r - mask(k) + 1][k]);
}

void solve() {
    ll ans = 0;

    FOR(i, 1, n) {
        ll pos = i;
        while(pos <= n) {
            ll l = pos, r = n, idx = 0;
            ll d = getGcd(i, pos);
            while(l <= r) {
                ll mid = (l + r) >> 1;
                if(d == getGcd(i, mid)) {
                    l = mid + 1;
                    idx = mid;
                } else {
                    r = mid - 1;
                }
            }

            ans = (ans + (idx - pos + 1) * d % mod) % mod;
            pos = idx + 1;
        }
    }

    cout << ans;
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