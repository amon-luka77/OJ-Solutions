/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
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
ll n, m, high[N + 1], treeSize[N + 1], parCentroid[N + 1];
ll ans[N + 1], par[N + 1][LOG + 1];
bool vs[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    FOR(i, 1, n) ans[i] = 1e18;
}

void dfsLca(ll u, ll parLca) {
    for(auto i : edge[u]) if(i != parLca) {
        high[i] = high[u] + 1;
        par[i][0] = u;
        FOR(j, 1, LOG) par[i][j] = par[par[i][j - 1]][j - 1];
        dfsLca(i, u);
    }
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

ll getDis(ll x, ll y) {
    return high[x] + high[y] - 2 * high[lca(x, y)];
}

ll getSize(ll u, ll par) {
    treeSize[u] = 1;
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }

    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > curSize) return findCentroid(i, u, curSize);
    }
    return u;
}

void solveCentroid(ll u, ll preCentroid) {
    ll centroid = findCentroid(u, -1, getSize(u, -1) >> 1);
    vs[centroid] = 1;  parCentroid[centroid] = preCentroid;

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i, centroid);
    }
}

void updated(ll i) {
    ll x = i;
    while(x > 0) {
        ans[x] = min(ans[x], getDis(i, x));
        x = parCentroid[x];
    }
}

void query(ll i) {
    ll kq = 1e18;
    ll x = i;
    while(x > 0) {
        kq = min(kq, ans[x] + getDis(x, i));
        x = parCentroid[x];
    }
    cout << kq << el;
}

void solve() {
    dfsLca(1, -1);
    solveCentroid(1, -1);
    updated(1);
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        if(x == 1) updated(y);
        else query(y);
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