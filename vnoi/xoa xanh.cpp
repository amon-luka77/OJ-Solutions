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

const ll N = 5e3, mode = 998244353;
ll n, k, dp[N + 1][N + 1], treeSize[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> k;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    dp[u][0] = 1;

    for(auto v : edge[u]) if(v != par) {
        dfs(v, u);

        vector<ll> newDp(N + 1, 0);

        ll sum = 0;
        FOR(i, 0, treeSize[v] - 1) sum = (sum + dp[v][i]) % mode;

        FOR(i, 0, treeSize[u] - 1) {
            newDp[i] = (newDp[i] + dp[u][i] * sum % mode) % mode;

            FOR(j, 0, treeSize[v] - 1) {
                ll dis = max(i, j + 1);
                if(i + j + 1 <= k) newDp[dis] = (newDp[dis] + dp[v][j] * dp[u][i] % mode) % mode;
            }
        }

        treeSize[u] += treeSize[v];

        FOR(i, 0, treeSize[u] - 1) {
            dp[u][i] = newDp[i];
        }
    }
}

void solve() {
    dfs(1, -1);

    ll ans = 0;
    FOR(i, 0, k) ans = (ans + dp[1][i]) % mode;
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