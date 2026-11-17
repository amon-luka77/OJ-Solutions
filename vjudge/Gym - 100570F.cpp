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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
int n, q;
vector<pair<int, ll>> edge[N + 1];
void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        int x, y; ll z; cin >> x >> y >> z;
        edge[x].pb({y, z}); edge[y].pb({x, z});
    }
}

const int LOG = 20;
int node[2 * N + 1], cntLca = 0, posLca[N + 1], minHigh[2 * N + 1][LOG + 1], high[N + 1];
ll dis[N + 1];

void dfsLca(int u, int par) {
    node[++cntLca] = u; posLca[u] = cntLca;
    for(auto &[i, j] : edge[u]) if(i != par) {
        high[i] = high[u] + 1; dis[i] = dis[u] + j;
        dfsLca(i, u); node[++cntLca] = u;
    }
}

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

void buildLca() {
    dfsLca(1, 0);
    FOR(i, 1, cntLca) minHigh[i][0] = node[i];
    FOR(j, 1, LOG) FOR(i, 1, cntLca - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }
}

inline int lca(int u, int v) {
    u = posLca[u]; v = posLca[v]; if(u > v) swap(u, v);
    int k = __lg(v - u + 1);
    return MIN_HIGH(minHigh[u][k], minHigh[v - MASK(k) + 1][k]);
}

inline ll getDis(int u, int v) {return dis[u] + dis[v] - 2 * dis[lca(u, v)];}

int treeSize[N + 1], parCentroid[N + 1]; 
bool vs[N + 1]; vector<ll> path[N + 1], pathParent[N + 1];

int getSize(int u, int par) {
    treeSize[u] = 1;
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) treeSize[u] += getSize(i, u);
    return treeSize[u];
}

int findCentroid(int u, int par, int curSize) {
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize); 
    }
    return u;
}

void add(int u, int par, ll dis, int centroid, int preCentroid) {
    path[centroid].pb(dis); if(preCentroid) pathParent[centroid].pb(getDis(u, preCentroid));
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) add(i, u, dis + j, centroid, preCentroid);
}

void solveCentroid(int u, int preCentroid) {
    int centroid = findCentroid(u, 0, getSize(u, 0));
    vs[centroid] = 1; path[centroid].pb(0);
    if(preCentroid) {
        parCentroid[centroid] = preCentroid;
        pathParent[centroid].pb(getDis(centroid, preCentroid));
    } else {
        parCentroid[centroid] = centroid;
    }

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) add(i, centroid, j, centroid, preCentroid);
    sort(all(path[centroid])); sort(all(pathParent[centroid]));

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) solveCentroid(i, centroid);
}


void query(ll u, ll dis) {
    ll res = upper_bound(all(path[u]), dis) - path[u].begin(); int cur = u;

    while(u != parCentroid[u]) {
        ll len = dis - getDis(cur, parCentroid[u]);
        int add = upper_bound(all(path[parCentroid[u]]), len) - path[parCentroid[u]].begin();
        int sub = upper_bound(all(pathParent[u]), len) - pathParent[u].begin();
        res += add - sub; u = parCentroid[u];
    }

    cout << res << el;
}

void solve() {
    buildLca();
    solveCentroid(1, 0);

    while(q --) {
        ll x, y; cin >> x >> y;
        query(x, y);
    }
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}