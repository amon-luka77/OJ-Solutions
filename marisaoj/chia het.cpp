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

const ll N = 13;
ll t, b[N + 3], pw10[N + 3], dp[3][110][110][3];

void read() {
    cin >> t;
}

ll getCount(ll B, ll mod) {
    memset(dp[0], 0, sizeof dp[0]);
    pw10[0] = 1; dp[0][0][0][1] = 1;
    ll m = 0;

    FOR(i, 0, 13) {
        if(B > 0) m ++;
        b[i] = B % 10; B /= 10;
    }

    if(mod > m * 9) return 1;

    FOR(i, 1, m) pw10[i] = (pw10[i - 1] * 10) % mod;

    FOR(i, 0, m - 1) {
        memset(dp[(i + 1) % 2], 0, sizeof dp[(i + 1) % 2]);

        FOR(j, 0, mod - 1) FOR(k, 0, mod - 1) FOR(l, 0, 1) if(dp[i % 2][j][k][l]) {
            FOR(t, 0, 9) {
                ll newJ = (j + t * pw10[i] % mod) % mod;
                ll newK = (t + k) % mod;
                ll newL = t == b[i] ? l : (t < b[i] ? 1 : 0);

                dp[(i + 1) % 2][newJ][newK][newL] += dp[i % 2][j][k][l];
            }
        }

    }

    return dp[m % 2][0][0][1];
}

void solve() {
    while(t --) {
        ll l, r, k; cin >> l >> r >> k;
        cout << getCount(r, k) - getCount(l - 1, k) << el;
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