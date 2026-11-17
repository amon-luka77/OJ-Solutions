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
ll n, k, dp[N + 1][101], sizeTree[N + 1];

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> k;

    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

void dfs(ll u, ll par) {
    FOR(i, 0, k) dp[u][i] = 1e18;
    dp[u][0] = 0;
    bool ok = 1;

    for(auto &[v, dis] : edge[u]) if(v != par) {
        dfs(v, u);
        ok = 0;

        vector<ll> newDp(k + 1, 1e18);

        FOR(i, 0, min(k, sizeTree[u])) FOR(j, 0, min(k, sizeTree[v])) {
            if(i + j <= k) newDp[i + j] = min(newDp[i + j], dp[u][i] + dp[v][j] + j * (k - j) * dis);
        }

        sizeTree[u] += sizeTree[v];

        FOR(i, 0, min(k, sizeTree[u])) {
            dp[u][i] = newDp[i];
        }
    }

    if(ok) {
        sizeTree[u] = 1;
        if(k >= 1) dp[u][1] = 0;
    }
}

void solve() {
    dfs(1, -1);

    cout << dp[1][k];
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