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

const ll N = 1e5, LOG = 20;

ll n, high[N + 1], par[N + 1][LOG + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u) {
    for(auto i : edge[u]) if(i != par[u][0]) {
        high[i] = high[u] + 1;
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

void solve() {
    prepare();
    ll sum = 0;

    FOR(i, 2, n) {
        FOR(j, 1, sqrt(i)) {
            if(i % j == 0) {
                sum += high[j] + high[i] - 2 * high[lca(i, j)] + 1;
                
                if(j != 1 && j * j != i) {
                    sum += high[i] + high[i / j] - 2 * high[lca(i, i / j)] + 1;
                }
            }
        }
    }

    cout << sum;
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