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
const ll numDigit = 20;
ll n, b[N + 1], dp[N + 5][3][3];

void read() {
    cin >> n;
}

ll getCount(ll B) {
    ll curB = B;
    FOR(i, 0, numDigit - 1) {
        b[i] = curB % 10; curB /= 10;
    }

    memset(dp, 0, sizeof dp);
    dp[0][1][0] = 1;

    FOR(i, 0, numDigit - 1) FOR(j, 0, 1) FOR(k, 0, 1) if(dp[i][j][k] > 0) {
        FOR(t, 0, 9) if(t != 4 && !(k && t == 1)) {
            ll newK = (t == 3);
            ll newJ;
            if(t < b[i]) newJ = 1;
            if(t > b[i]) newJ = 0;
            if(t == b[i]) newJ = j;

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    return B - (dp[numDigit][1][1] + dp[numDigit][1][0]) + 1;
}

void solve() {
    cout << getCount(n);
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