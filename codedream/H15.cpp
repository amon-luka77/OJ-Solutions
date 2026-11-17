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

const ll N = 4e5, LOG = 19;
ll n, q, minHigh[2 * N][LOG], euler[2 * N], d[N], pos[N];
ll treeSize[N], parCentroid[N], high[N], cnt = 0;
bool vs[N];
vector<pair<ll, ll>> path[N];
vector<pair<ll, ll>> edge[N];
vector<pair<ll, ll>> disCentroid[N + 1];

struct SegmentTree {
    ll maxN;
    vector<ll> node;

    void resize(ll m) {
        maxN = m;
        node.assign(4 * maxN + 5, 1e18);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l == r) {
            node[id] = val;
            return;
        }

        ll mid = (l + r) >> 1;
        if(i <= mid) updated(id * 2, l, mid, i, val);
        else updated(id * 2 + 1, mid + 1, r, i, val);

        node[id] = min(node[id * 2], node[id * 2 + 1]);
    }

    ll getMin(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 1e18;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return min(getMin(id * 2, l, mid, i, j), getMin(id * 2 + 1, mid + 1, r, i, j));
    }
};

SegmentTree node[N];

void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

void dfs(ll u, ll par) {
    euler[++cnt] = u;
    pos[u] = cnt;

    for(auto &[i, j] : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        d[i] = d[u] + j; 
        dfs(i, u);
        euler[++cnt] = u;
    }
}

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)
#define MASK(i) (1 << i)

void buildLca() {
    dfs(1, -1);
    FOR(i, 1, cnt) minHigh[i][0] = euler[i];
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
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

ll getSize(ll u, ll par) {
    treeSize[u] = 1;

    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }

    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }
    return u;
}

void add(ll u, ll par, ll dis, ll centroid) {
    path[centroid].pb({u, dis});
    disCentroid[u].pb({centroid, getDis(u, centroid)});

    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        add(i, u, dis + j, centroid);
    }
}

void solveCentroid(ll u, ll preCentroid) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    parCentroid[centroid] = preCentroid;
    disCentroid[centroid].pb({centroid, 0});

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        add(i, centroid, j, centroid);
    }

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        solveCentroid(i, centroid);
    }
}

ll binaryLeft(const vector<pair<ll, ll>> &nen, ll tg) {
    ll l = 0, r = nen.size() - 1, ans = -1;

    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(tg <= nen[mid].ft) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    return ans + 1;
}

ll binaryRight(const vector<pair<ll, ll>> &nen, ll tg) {
    ll l = 0, r = nen.size() - 1, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(nen[mid].ft <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans + 1;
}

void query(ll u, ll l, ll r) {
    ll ans = 1e18;
    if(l <= u && u <= r) ans = 0;
    else {
        for(auto &[centroid, dis] : disCentroid[u]) {
            ll left = binaryLeft(path[centroid], l);
            ll right = binaryRight(path[centroid], r);

            if(left > 0 && right > 0 && left <= right) {
                ans = min(ans, dis + node[centroid].getMin(1, 1, path[centroid].size(), left, right));
            }
        } 
    }


    cout << ans << el;
}

void solve() {
    buildLca();
    solveCentroid(1, -1);

    FOR(i, 1, n) {
        path[i].pb({i, 0});
        sort(all(path[i]));
        node[i].resize(path[i].size());

        FOR(j, 0, path[i].size() - 1) {
            node[i].updated(1, 1, path[i].size(), j + 1, path[i][j].sc);
        }
    }

    while(q --) {
        ll k, l, r; cin >> k >> l >> r;
        query(k, l, r);
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