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

const ll N = 120;
ll t, dp[N + 1][N + 1][3], b[N + 1];

void read() {
    cin >> t;
    FOR(i, 1, 120) b[i] = 9;
}   

ll getCnt(ll m, ll sum) {
    if(m == 0) return 0;
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = 1;

    FOR(i, 0, m - 1) b[i] = 9;
    FOR(i, 0, 9) {
        ll newK = i <= b[i] ? 1 : 0;
        dp[1][i][newK] = 1;
    }

    FOR(i, 1, m - 1) FOR(j, 0, sum - 1) FOR(k, 0, 1) if(dp[i][j][k]) {
        FOR(t, 0, 9) if(j + t <= sum) {
            ll newJ = j + t;
            ll newK = t == b[i] ? k : (t < b[i] ? 1 : 0);

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    ll res = 0;
    FOR(i, 0, m) res += dp[i][sum][1];
    return res;
}

void solve() {
    // cout << getCnt(1, 1) << ' ' << getCnt(0, 1) << el;
    // cout << getCnt(2, 1) << ' ' << getCnt(1, 1) << el;
    
    while(t --) {
        ll n, m; cin >> n >> m;
        ll res = 0;

        FOR(i, 1, n) {
            res += getCnt(i, m) - getCnt(i - 1, m);
        }

        cout << res << el;
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
