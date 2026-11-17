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
ll t, n, dp[MASK(15) + 1], h[N + 1], a[N + 1][N + 1];

void read() {
    cin >> t;
}

void solve() {
    FOR(amon, 1, t) {
        cin >> n;
        FOR(i, 0, n - 1) cin >> h[i];
        FOR(i, 0, n - 1) FOR(j, 0, n - 1) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }

        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;

        FOR(mask, 0, MASK(n) - 1) FOR(i, 0, n - 1) if(!BIT(mask, i)) {
            ll damage = 1;

            for(ll temp = mask; temp; temp ^= temp & -temp) {
                ll pos = __lg(temp & -temp);
                damage = max(damage, a[pos][i]);
            }

            dp[mask | MASK(i)] = min(dp[mask | MASK(i)], dp[mask] + (h[i] + damage - 1) / damage);
        }

        cout << "Case " << amon << ": " << dp[MASK(n) - 1] << el;
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