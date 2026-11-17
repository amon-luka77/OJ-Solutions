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

const ll N = 300, mod = 1e9;
string s; ll n, b[N + 2], dp[N + 2][9 * (N + 1) + 2][4];

void read() {
    cin >> s; n = s.size();
}

void solve() {
    ll sum = 0;
    FOR(i, 0, n - 1) {
        b[i] = s[i] - '0';
        sum += b[i];
    }

    dp[0][0][1] = 1;

    FOR(i, 0, n - 1) FOR(j, 0, sum) FOR(k, 0, 1) if(dp[i][j][k]) {
        ll limit = k ? b[i] : 9;
        FOR(t, 0, limit) if(t + j <= sum) {
            ll newJ = t + j;
            ll newK = k && (t == limit);
            
            dp[i + 1][newJ][newK] += dp[i][j][k];
            dp[i + 1][newJ][newK] %= mod;
        }
    }

    cout << (dp[n][sum][0] + dp[n][sum][1]) % mod;
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