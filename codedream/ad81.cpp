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

const ll N = 1e5, mod = 1e9 + 7;
ll p, q;

void read() {
}    cin >> p >> q;


ll getCount(ll numDigit) {
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0][1] = 1; dp[0][0][0][1][1] = 1;
    // dp[i][j][k][l][j]: so thu i; lastPos = j; tang hay giam k; start l; h ez;

    FOR(i, 0, numDigit - 1) FOR(j, 0, 9) FOR(k, 0, 1) FOR(l, 0, 1) FOR(h, 0, 1) if(dp[i][j][k][l][h]) {
        ll left = l ? j + 1 : 0, right = l ? b[i] : j - 1;
        FOR(t, left, right) {
            ll newJ = t;
            ll newK = k || t != 0;
            ll newL = 1 - l;
            ll newH = h && (t == b[i]);

            dp[i + 1][newJ][newK][newL][newH] += dp[i][j][k][l][h];
        }
    }

    ll res = 0;

}

void solve() {
    ll ans = 0;

    FOR(i, 0, p - 1) {
        cin >> b[i];
        if(i == p) b[i] --
    }

    ans -= getCount(p);
    
    FOR(i, 0, q - 1) {
        cin >> b[i];
        if(i == q) b[i] --;
    }

    ans += getCount(q);

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