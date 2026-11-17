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

const ll N = 100;
ll n, m, dp[N + 1][20001], a[N + 1], b[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 2, n) cin >> a[i];
    FOR(i, 2, n) cin >> b[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    FOR(i, 1, n) FOR(j, 0, m) dp[i][j] = -1e18;
}

void dfs(ll u, ll par) {
    dp[u][b[u]] = a[u];

    for(auto v : edge[u]) if(v != par) {
        dfs(v, u);

        FORD(i, m, 0) FORD(j, m - i, 0) {
            dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j]); 
        }
    } 
}

void solve() {
    dfs(1, -1);

    ll ans = 0;
    FOR(i, 1, m) ans = max(ans, dp[1][i]);

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