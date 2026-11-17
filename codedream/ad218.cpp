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

const ll N =  1e5, LOG = 20;
ll n, m, high[N + 1], par[N + 1][LOG + 1], minEdge[N + 1][LOG + 1];
ll parent[N + 1], sz[N + 1];
vector<pair<ll, ll>> edge[N + 1];
bool check[N + 1];

struct QUERY {
    ll x, y, z;
};

vector<QUERY> a;

void read() {
    cin >> n >> m;

    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        a.pb({x, y, z});
    }

    sort(all(a), [](const QUERY &x, const QUERY &y) {
        return x.z > y.z;
    });
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

bool union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];

        return 1;
    }

    return 0;
}

void kruskal() {
    FOR(i, 1, n) {
        parent[i] = i;
        sz[i] = 1;
    }

    FOR(i, 0, m - 1) {
        if(union_set(a[i].x, a[i].y)) {
            check[i] = 1;
            edge[a[i].x].pb({a[i].y, a[i].z});
            edge[a[i].y].pb({a[i].x, a[i].z});
        }
    }
}

void dfs(ll u) {
    for(auto &[i, j] : edge[u]) if(i != par[u][0]) {
        par[i][0] = u;
        minEdge[i][0] = j;
        high[i] = high[u] + 1;
        dfs(i);
    }
}

void prepare() {
    FOR(i, 0, n) FOR(j, 0, LOG) minEdge[i][j] = 1e18;

    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        minEdge[i][j] = min(minEdge[i][j - 1], minEdge[par[i][j - 1]][j - 1]);
    }

    high[0] = -1; 
}

ll minEdgeLca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    ll ans = 1e18;
    FORD(i, LOG, 0) if(high[par[u][i]] >= high[v]) {
        ans = min(ans, minEdge[u][i]);
        u = par[u][i];
    }

    if(u == v) return ans;

    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        ans = min({ans, minEdge[u][i], minEdge[v][i]});
        u = par[u][i];
        v = par[v][i];
    }

    return min({ans, minEdge[u][0], minEdge[v][0]});
}

void solve() {
    kruskal();
    prepare();
    ll ans = 0;

    FOR(i, 0, m - 1) {
        if(!check[i]) {
            ll k = minEdgeLca(a[i].x, a[i].y);

            ans += k - a[i].z;
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