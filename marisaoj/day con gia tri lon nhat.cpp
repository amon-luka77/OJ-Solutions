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

const ll N = 1e5;
ll n, m, k, a[N + 1], dp[N + 1][2];

void read() {
    cin >> n >> m >> k;

    FOR(i, 1, n) FOR(j, 1, k) dp[i][j] = -1e9;

    FOR(i, 1, n) {
        cin >> a[i];
        dp[i][1] = a[i];
    }
}

void solve() {
    ll ans = -1e9;

    FOR(j, 2, k) {
        deque<ll>  dq;

        FOR(i, 1, n) {
            while(!dq.empty() && dp[dq.back()][(j + 1) % 2] <= dp[i][(j + 1) % 2]) dq.pop_back();
            dq.push_back(i);
            while(!dq.empty() && i - dq.front() + 1 > m) dq.pop_front();

            if(!dq.empty() && i < n) {
                dp[i + 1][j % 2] = dp[dq.front()][(j + 1) % 2] + a[i + 1] * j;
                if(j == k) ans = max(ans, dp[i + 1][j % 2]);
            }
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