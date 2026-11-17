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
ll k, dp[N + 1][(N + 1) * 9 + 1][3], b[N + 1];
vector<ll> Prime = {2, 3, 5, 7, 11, 13, 17, 19,  23, 29, 31, 37, 41, 43, 47, 53,
                     59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
void read() {
    cin >> k;
}

ll getPrime(ll B) {
    memset(dp, 0, sizeof dp);
    ll m = 0;

    FOR(i, 0, N) {
        if(B > 0) m ++;
        b[i] = B % 10; B /= 10;
    }
    dp[0][0][1] = 1;

    FOR(i, 0, m - 1) FOR(j, 0, 9 * m) FOR(k, 0, 1) if(dp[i][j][k]) {
        FOR(t, 0, 9) {
            ll newJ = t + j;
            ll newK = t == b[i] ? k : (t < b[i] ? 1 : 0);

            dp[i + 1][newJ][newK] += dp[i][j][k];
        }
    }

    ll res = 0;
    for(auto i : Prime) res += dp[m][i][1];
    // cout << B << ' ' << res << el;
    return res;
}

void solve() {
    ll l = 1, r = 1e13, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(getPrime(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

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