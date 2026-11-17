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
#define NAME "TRADEWAR"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 2e3;
ll n, k, t;

void read() {
    cin >> t;
}

ll s[N + 1];

void solve() {
    while(t --) {
        cin >> n >> k;
        FOR(i, 1, n) cin >> s[i];
        sort(s + 1, s + n + 1);
        vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1e18));
        dp[0][0] = 0;


        FOR(i, 1, n) FOR(j, 1, k) {
            ll res = 0;
            FORD(l, i, 1) {
                res += s[i] - s[l];
                dp[i][j] = min(dp[i][j], res + dp[l - 1][j - 1]);
            }
        } cout << dp[n][k] << el;
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
