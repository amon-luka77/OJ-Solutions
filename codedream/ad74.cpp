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

const ll N = 100;
ll t, dp[N + 1][N + 1][N + 1], b[N + 1];

void read() {
    cin >> t;
}

ll getCount(ll numDigit, ll sumDigit, ll mod) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0] = 1;

    FOR(i, 0, numDigit -1) FOR(j, 0, sumDigit) FOR(k, 0, mod - 1) if(dp[i][j][k]) {
        FOR(t, 0, 9) if(j + t <= sumDigit) {
            ll newJ = j + t;
            ll newK = (k * 10 % mod + t) % mod;
            
            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    return dp[numDigit][sumDigit][0];
}

void solve() {
    while(t --) {
        ll n, m, k; cin >> n >> m >> k;
        cout << getCount(n, m, k) << el;
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