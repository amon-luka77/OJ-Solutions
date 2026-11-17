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

const ll N = 5e3;
ll n, a[N + 1], dp[N + 1][N + 1], treeSize[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n;

    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    FOR(i, 0, n) dp[u][i] = -1e18;
    dp[u][1] = a[u];
    treeSize[u] = 1;

    for(auto v : edge[u]) if(v != par) {
        dfs(v, u);

        FORD(i, treeSize[u], 0) FOR(j, 0, treeSize[v]) {
            dp[u][i + j] =  max(dp[u][i + j], dp[u][i] + dp[v][j]);
        }

        treeSize[u] += treeSize[v];
    }
}

void solve() {
    dfs(1, -1);

    FOR(i, 1, n) {
        ll ans = -1e18;
        FOR(j, 1, n) ans = max(ans, dp[j][i]);
        cout << ans << el;   
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