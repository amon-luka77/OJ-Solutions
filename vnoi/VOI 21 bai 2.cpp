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
ll n, k, a, b, dp[N + 1][N + 1][5], sizeTree[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> k >> a >> b;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    sizeTree[u] = 1;
    dp[u][0][1] = 1;
    dp[u][0][0] = 1;

    for(auto v : edge[u]) if(v != par) {
        dfs(v, u);

        FORD(i, sizeTree[u] - 1, 0) FOR(j, 0, sizeTree[v] - 1) FORD(x, k, 0) FOR(y, 1, k - x) {
            dp[u][i + j + (y < k)][x + y] += dp[u][i][x] * dp[v][j][y];
        }

        sizeTree[u] += sizeTree[v];
    } 
}

void solve() {
    dfs(1, -1);
    ll ans = 0;

    FOR(i, a, b) ans += dp[1][i][k];

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