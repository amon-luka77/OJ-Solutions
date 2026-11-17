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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 15, mod = 1e9 + 7;
ll n, k, dp[N + 1][MASK(N) + 1][N * N];

void read() {
    cin >> n >> k;
}

void solve() {
    vector<ll> a;
    FOR(mask, 0, MASK(n) - 1) if(!(mask & (mask << 1LL)) && !(mask & (mask >> 1LL))) {
        a.pb(mask);

        if(__builtin_popcountll(mask) <= k) dp[1][mask][__builtin_popcountll(mask)] = 1;
    }
    
    FOR(i, 1, n - 1) for(auto mask : a) FOR(j, 0, k) for(auto l : a) {
        if(!(mask & l) && !(mask & (l << 1LL)) && !(mask & (l >> 1LL)) && j + __builtin_popcountll(l) <= k) {
            dp[i + 1][l][j + __builtin_popcountll(l)] += dp[i][mask][j];
            dp[i + 1][l][j + __builtin_popcountll(l)] %= mod;
        }
    }

    ll res = 0;
    for(auto j : a) res = (res + dp[n][j][k]) % mod;
    cout << res;
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