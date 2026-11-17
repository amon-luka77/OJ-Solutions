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

const ll N = 1e4;
ll n, a[N + 1][4], dp[N + 1][MASK(4) + 1];

void read() {
    cin >> n;
    FOR(i, 0, n - 1) FOR(j, 0, 3) cin >> a[i][j];
}

void solve() {
    vector<ll> b;
    FOR(mask, 0, MASK(4) - 1) if(!(mask & (mask << 1LL))) {
        b.pb(mask);
    }

    memset(dp, -0x3f, sizeof dp); dp[0][0] = 0;

    FOR(i, 0, n - 1) for(auto mask : b) for(auto j : b) if(!(mask & j)) {
        ll sum = 0;

        FOR(k, 0, 3) if(BIT(j, k)) sum += a[i][k];

        dp[i + 1][j] = max(dp[i + 1][j], dp[i][mask] + sum);
    } 

    ll ans = 0;
    for(auto mask : b) ans = max(ans, dp[n][mask]);

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