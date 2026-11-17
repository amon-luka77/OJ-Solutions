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

const ll N = 20;
ll A, B;
ll dp[N + 1][10][3][3], b[N + 1];

void read() {
    cin >> A >> B;
}

ll getCount(ll AB) {
    if(AB < 0) return 0; 
    string s = to_string(AB);
    ll numDigit = s.size();
    FOR(i, 0, numDigit - 1) b[i] = s[i] - '0';
    memset(dp, 0, sizeof dp);
    dp[0][0][0][1] = 1;

    FOR(i, 0, numDigit - 1) FOR(j, 0, 9) FOR(k, 0, 1) FOR(l, 0, 1) if(dp[i][j][k][l]) {
        FOR(t, 0, l ? b[i] : 9) if(!(k && t == j)) {
            ll newJ = t;
            ll newK = k || t != 0;
            ll newL = l && t == (l ? b[i] : 9) ? 1 : 0;

            dp[i + 1][newJ][newK][newL] += dp[i][j][k][l];
        }
    }

    ll res = 1;
    FOR(i, 0, 9) res += dp[numDigit][i][1][0] + dp[numDigit][i][1][1];
    return res;
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