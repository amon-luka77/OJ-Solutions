/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5, LOG = 18;
ll n, q, cnt = 0, treeSize[N + 1], a[N + 1], minHigh[2 * N + 1][LOG + 1], pos[N + 1], node[2 * N + 1], high[N + 1];
bool vs[N + 1];
multiset<ll> d[N + 1];
vector<ll> parCentroid[N + 1], edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
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
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }
    return u;
}

void add(ll u, ll par, ll centroid, ll height) {
    parCentroid[u].pb(centroid);

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        add(i, u, centroid, height + 1);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, 0, getSize(u, 0));
    vs[centroid] = 1;
    parCentroid[centroid].pb(centroid);

    for(auto i : edge[centroid]) if(!vs[i]) {
        add(i, centroid, centroid, 1);
    }

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void dfs(ll u, ll par) {
    node[++cnt] = u;
    pos[u] = cnt;
    
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        node[++cnt] = u;
    }
}

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

void prepare() {
    dfs(1, -1);
    FOR(i, 1, cnt) minHigh[i][0] = node[i];
    FOR(j, 1, LOG) FOR(i, 1, cnt - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }
}

ll lca(ll u, ll v) {
    ll pu = pos[u], pv = pos[v];
    if(pu > pv) swap(pu, pv);
    ll k = __lg(pv - pu + 1);
    return MIN_HIGH(minHigh[pu][k], minHigh[pv - MASK(k) + 1][k]);
}

ll getDis(ll u, ll v) {
    return high[u] + high[v] - 2 * high[lca(u, v)];
}

void solve() {
    prepare();
    solveCentroid(1);

    while(q --) {
        ll x, u; cin >> x >> u;
        if(x == 1) {
            if(a[u] == 1) {
                for(auto i : parCentroid[u]) d[i].erase(d[i].find(getDis(u, i)));
            } else {
                for(auto i : parCentroid[u]) d[i].insert(getDis(u, i));
            }
            a[u] = 1 - a[u];
        } else {
            ll ans = 1e9;
            for(auto i : parCentroid[u]) if(!d[i].empty()) ans = min(ans, getDis(u, i) + *d[i].begin());
            if(ans != 1e9) cout << ans << el;
            else cout << -1 << el;
        }
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