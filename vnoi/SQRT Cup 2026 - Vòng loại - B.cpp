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
const ll N = 1e3;
ll n, m, t, a[N + 1][N + 1], dp[N + 1][N + 1];

vector<ll> b;

void read() {
    cin >> n >> m >> t;
    b.pb(0);

    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
        b.pb(a[i][j]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
}

bool check(ll k) {
    memset(dp, 0, sizeof(dp));

    FOR(i, 1, n) FOR(j, 1, m) {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (a[i][j] >= k);
    }

    return dp[n][m] >= t;
}

void solve() {
    ll l = 1,  r = b.size() - 1, ans = 0;

    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(check(b[mid])) {
            ans = b[mid];
            l = mid + 1;
        } else {
            r = mid - 1;
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