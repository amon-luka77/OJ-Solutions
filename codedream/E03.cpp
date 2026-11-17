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

const ll N = 2e3, LOG = 20;
ll n, k;
ll S[N + 1], dp[N + 1][N + 1], sz[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> S[i];
}

void dfs(ll u, ll par) {
    sz[u] = 1;

    for(auto v : edge[u]) if(v != par) {
        dfs(v, u);

        FORD(i, sz[u], 0) FOR(j, 0, sz[v]) {
            dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[v][j] + i * j * S[u]);
        }

        sz[u] += sz[v];
    }
}

void solve() {
        FOR(i, 2, n) {
            ll x; cin >> x; x ++;
            edge[x].pb(i);
        }

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