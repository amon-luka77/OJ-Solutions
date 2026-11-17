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

const ll N = 18;
ll L, R, b[N + 1], dp[N + 1][10][3];

void read() {
    cin >> L >> R;
}

ll getCount(ll B, ll m) {
    string s = to_string(B);
    memset(dp, 0, sizeof dp);
    FOR(i, 0, m - 1) {
        b[i] = s[i] - '0';
    }

    FOR(i, 0, b[0]) dp[0][i][(i == b[0])] = 1;

    FOR(i, 1, m - 1) FOR(j, 0, 9) FOR(k, 0, 1) {
        ll limit = k ? b[i] : 9;
        FOR(t, 0, limit) if(j != t) {
            ll newJ = t;
            ll newK = k && (t == limit);

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    ll res = 0;
    FOR(i, 0, b[m]) res += dp[m][i][1] + (i != b[m]) * dp[m][i][0];
    return res;
}

ll getQuery(ll B) {
    string s = to_string(B);
    ll n = s.size();
    FOR(i, 0, n - 1) b[i] = s[i] - '0';

    ll start = 10, end = 9, res = 0;
    FOR(i, 1, n) {
        res += getCount(end, i);
        end = end * 10 + 9;
        start *= 10;
    }

    res += getCount(B, n) - getCount(start - 1, n);

    return res;
}

void solve() {
    cout << getQuery(R) - getQuery(L - 1);
    // ll x; cin >> x;
    // cout << countPair(20) << el;
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