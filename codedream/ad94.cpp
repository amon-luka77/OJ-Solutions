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

const ll N = 15;
ll n, m, dp[MASK(N) + 1][N + 1], cost[N + 1][N + 1];
string a[N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 0, m - 1) {
        string s; cin >> s;
        a[i] = s;
    }
}

void solve() {
    memset(dp, 0x3f, sizeof dp);
    
    FOR(i, 0, m - 1) {
        ll cnt = 0;
        FOR(j, 0, n - 1) cnt += a[i][j] - '0';
        dp[MASK(i)][i] = cnt;
    }

    FOR(i, 0, m - 1) FOR(j, 0, m - 1) if(i != j) {
        ll cnt = 0;
        FOR(l, 0, n - 1) cnt += (a[i][l] != a[j][l]);

        cost[i][j] = cnt;
        cost[j][i] = cnt;
    }

    FOR(mask, 1, MASK(m) - 1) FOR(i, 0, m - 1) if(BIT(mask, i)) FOR(j, 0, m - 1) if(!BIT(mask, j)) {
        dp[mask | MASK(j)][j] = min(dp[mask | MASK(j)][j], dp[mask][i] + cost[i][j]);
    }

    ll ans = 1e18;
    FOR(i, 0, m - 1) ans = min(ans, dp[MASK(m) - 1][i]);
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