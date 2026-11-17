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

const ll N = 2e5, LOG = 20;
ll n, q, dp[N + 1];
ll high[N + 1], d[N + 1], par[N + 1][LOG + 1];

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> q;

    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

void dfsDp(ll u, ll p) {
    for(auto &[i, j] : edge[u]) if(i != p) {
        dfsDp(i, u);

        dp[u] = max(dp[u], dp[i] + j);
    }
}

void dfs(ll u) {
    for(auto &[i, j] : edge[u]) if(i != par[u][0]) {
        high[i] = high[u] + 1;
        d[i] = d[u] + j;
        par[i][0] = u;
        dfs(i);
    }
}

void prepare() {
    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1; 
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    FORD(i, LOG, 0) if(high[par[u][i]] >= high[v]) u = par[u][i];
    if(u == v) return u;

    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }

    return par[u][0];
}

ll disLca(ll u, ll v) {
    ll k = lca(u, v);

    return d[u] + d[v] - 2 * d[k];
}

void solve() {
    dfsDp(1, -1);
    prepare();

    while(q --) {
        ll x, y, k; cin >> x >> y >> k;
        cout << max({k, disLca(x, y), dp[x] + dp[y] + k}) << el;
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