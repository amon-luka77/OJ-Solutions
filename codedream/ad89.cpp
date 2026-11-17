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

const ll N = 20;
ll n, dp[N + 1][MASK(N) - 1], a[N + 1][N + 1];

void read() {
    cin >> n;
    FOR(i, 0, n - 1) FOR(j, 0, n - 1) cin >> a[i][j];
}

void solve() {
    memset(dp, -0x3f, sizeof dp);
    FOR(i, 0, n - 1) dp[1][MASK(i)] = a[0][i];

    FOR(i, 1, n - 1) FOR(mask, 0, MASK(n) - 1) if(__builtin_popcountll(mask) == i) FOR(j, 0, n - 1) if(!BIT(mask, j)) {
        dp[i + 1][mask | MASK(j)] = max(dp[i + 1][mask | MASK(j)], dp[i][mask] + a[__builtin_popcountll(mask)][j]);
    }

    cout << dp[n][MASK(n) - 1];
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