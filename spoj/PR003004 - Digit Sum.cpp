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
ll l, r, t;
ll b[N + 1], dp[N + 1][9 * N][3];

void read() {
    cin >> t;
}

ll getCount(ll B) {
    ll m = 0;
    FOR(i, 0, 20) {
        if(B > 0) m ++;
        b[i] = B % 10; B /= 10;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][1] = 1;

    FOR(i, 0, m - 1) FOR(j, 0, 9 * m) FOR(k, 0, 1) if(dp[i][j][k]) {
        FOR(t, 0, 9) if(t + j <= 9 * m) {
            ll newJ = t + j;
            ll newK = t == b[i] ? k : (t < b[i] ? 1 : 0);

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    ll res = 0;
    FOR(i, 0, 9 * m) res += dp[m][i][1] * i;
    return res;
}

void solve() {
    while(t --) {
        cin >> l >> r;
        cout << getCount(r) - getCount(l - 1) << el;
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