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
ll t, dp[N + 1][N + 1][3];

void read() {
    cin >> t;
}

ll countPair(ll numDigit, ll sumDigit) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    FOR(i, 0, numDigit - 1) FOR(j, 0, sumDigit) FOR(k, 0, 1) if(dp[i][j][k]) {
        FOR(t, 0, 9) if(t + j <= sumDigit) {
            if(k && t == 3) continue;
            ll newJ = j + t;
            ll newK = (t == 1);

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    return dp[numDigit][sumDigit][1] + dp[numDigit][sumDigit][0];
}

void solve() {
    while(t --) {
        ll n, m; cin >> n >> m;
        cout << countPair(n, m) << el;
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