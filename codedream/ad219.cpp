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

const ll N = 1e3, LOG = 20;
ll n, high[N + 1], par[N + 1][LOG + 1], d[N + 1]; 
vector<pair<ll, ll>> edge[N + 1];

vector<pair<ll, ll>> a;

void read() {
    cin >> n;

    FOR(i, 1, n - 1) {
        ll s, t, p, q;
        cin >> s >> t >> p >> q;
        a.pb({s, t});

        edge[s].pb({t, p - q});
        edge[t].pb({s, p - q});
    }
}

void dfs(ll u) {
    for(auto &[i, j] : edge[u]) if(i != par[u][0]) {
        par[i][0] = u;
        high[i] = high[u] + 1;
        d[i] = d[u] + j;
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

ll dis(ll u, ll v) {
    ll k = lca(u, v);

    return d[u] + d[v] - 2 * d[k];
}

void trace(ll startNode, ll endNode) {
    ll k = lca(startNode, endNode);
    vector<ll> y;
    while(startNode != k) {
        cout << startNode << ' ';
        startNode = par[startNode][0];
    }

    if(startNode == k) cout << startNode << ' ';

    while(endNode != k) {
        y.pb(endNode);
        endNode = par[endNode][0];
    }

    FORD(i, y.size() - 1, 0) cout << y[i] << ' ';
}

void solve() {
    prepare();
    ll ans = 1e18;
    pair<ll, ll> t;

    FOR(i, 0, n - 2) FOR(j, 1, n) if(j != a[i].ft && j != a[i].sc) {
        ll k = dis(a[i].ft, j);
        if(ans > k) {
            ans = k;
            t = {a[i].ft, j};
        }
    }

    cout << ans << el;
    trace(t.ft, t.sc);
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