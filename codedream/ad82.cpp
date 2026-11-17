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

const ll N = 65;
ll A, B, K, dp[N + 1][N + 1][3];

void read() {
    cin >> A >> B >> K;
}

ll getCount(ll C) {
    if(C <= 0) return 0;
    vector<ll> b;
    FORD(i, 63, 0) b.pb(BIT(C, i)); 
    ll numDigit = b.size();
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = 1;

    FOR(i, 0, numDigit - 1) FOR(j, 0, K) FOR(k, 0, 1) if(dp[i][j][k]) {
        FOR(t, 0, k ? b[i] : 1) if(j + (t == 1) <= K) {
            ll newJ = j + (t == 1);
            ll newK = k && (t == (k ? b[i] : 1));

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    return dp[numDigit][K][0] + dp[numDigit][K][1];
}

void solve() {
    cout << getCount(B) - getCount(A - 1);
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