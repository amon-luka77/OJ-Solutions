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

const ll N = 1000, mod = 1e9 + 7;
ll n, m, dp[N + 1][MASK(10) + 1], ok[MASK(10) + 1];

void read() {
    cin >> n >> m;
}

void solve() {
    ok[0] = 1;
    FOR(mask, 0, MASK(n) - 1) if(ok[mask]) {    
        FOR(i, 0, n - 2)if(!BIT(mask, i) && !BIT(mask, i + 1)) {
            ok[mask | MASK(i) | MASK(i + 1)] = 1;
        }
    }

    dp[0][0] = 1;

   FOR(i, 0, m - 1) FOR(mask, 0, MASK(n) - 1) if(dp[i][mask]) {
        FORD(newMask, (MASK(n) - 1) ^ mask, 0) {
            newMask &= (MASK(n) - 1) ^ mask;
            ll curMask = (MASK(n) - 1) ^ (mask | newMask);

            if(ok[curMask]) {
                dp[i + 1][newMask] += dp[i][mask];
                dp[i + 1][newMask] %= mod;
            }
        }
   }

    cout << dp[m][0];
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