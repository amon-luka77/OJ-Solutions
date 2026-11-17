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
#define MASK(i) (1 << i)
using namespace std;
const ll N = 1e5, LOG = 18;
ll n, m, high[N + 1], minHigh[2 * N + 1][LOG + 1], dp[N + 1];
ll cnt = 0, treeSize[N + 1], pos[N + 1], node[2 * N + 1], parCentroid[N + 1];
bool vs[N + 1];

vector<ll> edge[N + 1];
vector<pair<ll, ll>> query;
vector<ll> nen[N + 1];

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

struct BIT {
    ll maxN;
    vector<ll> bit;
    
    void resize(ll k) {
        maxN = k;
        bit.assign(maxN + 1, -1e18);
    }

    void updated(ll i, ll val) {
        for(; i <= maxN; i += i & -i) bit[i] = max(bit[i], val);
    }

    ll getMax(ll i) {
        ll ans = -1e18;
        for(; i >= 1; i -= i & -i) ans = max(ans, bit[i]);
        return ans;
    }
};

BIT bit[N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        x ++; y ++;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    query.pb({1, 0});

    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        x ++;
        query.pb({x, y});
    }
    sort(all(query), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        if(x.sc != y.sc) return x.sc < y.sc;
        return x.ft < y.ft;
    });
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

ll lca(ll u, ll v) {
    ll pu = pos[u], pv = pos[v];
    if(pu > pv) swap(pu, pv);
    ll k = __lg(pv - pu + 1);

    return MIN_HIGH(minHigh[pu][k], minHigh[pv - MASK(k) + 1][k]);
}

ll getSize(ll u, ll parent) {
    treeSize[u] = 1;

    for(auto i : edge[u]) if(i != parent && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }

    return treeSize[u];
}

ll findCentroid(ll u, ll parent, ll curSize) {
    for(auto i : edge[u]) if(i != parent && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }
    return u;
}

void solveCentroid(ll u, ll preCentroid) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    parCentroid[centroid] = preCentroid;

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i, centroid);
    }
}

ll binary(vector<ll> &amon, ll tg) {
    ll l = 0, r = amon.size() - 1, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(amon[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    return ans + 1;
}

ll getQuery(ll u, ll curTime) {
    ll v = u;
    ll ans = -1e18;

    while(v > 0) {
        ll dis = high[u] + high[v] - 2 * high[lca(u, v)];
        ll tg = curTime - dis;
        tg = binary(nen[v], tg);

        if(tg >= 0) ans = max(ans, bit[v].getMax(tg));
        v = parCentroid[v];
    }

    return ans;
}

void updatedQuery(ll u, ll curTime, ll val) {
    ll v = u;

    while(v > 0) {
        ll dis = high[u] + high[v] - 2 * high[lca(u, v)];
        ll tg = curTime + dis;
        tg = binary(nen[v], tg);

        bit[v].updated(tg, val);

        v = parCentroid[v];
    }
}

void solve() {
    dfs(1, -1);
    solveCentroid(1, -1);
    ll ans = 0;
    fill(dp + 1, dp + m + 1, -1e18);

    // build lca
    FOR(i, 1, cnt) minHigh[i][0] = node[i];
    FOR(j, 1, LOG) FOR(i, 1, cnt - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }
    // end build

    // nen
    for(int i = 1; i <= m; i++) {
        int u = query[i].ft;
        ll t = query[i].sc;

        int v = u;

        while(v > 0) {
            ll dis = high[u] + high[v] - 2 * high[lca(u, v)];
            nen[v].push_back(t + dis);

            v = parCentroid[v];
        }
    }

    for(int i = 1; i <= n; i++) {
        sort(nen[i].begin(), nen[i].end());
        nen[i].erase(unique(all(nen[i])), nen[i].end());

        bit[i].resize(nen[i].size());
    }
    // end nen

    FOR(i, 1, m) {
        if(high[query[i].ft] <= query[i].sc) dp[i] = 1;
        
        dp[i] = max(dp[i], getQuery(query[i].ft, query[i].sc) + 1);
        updatedQuery(query[i].ft, query[i].sc, dp[i]);

        ans = max(ans, dp[i]);
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