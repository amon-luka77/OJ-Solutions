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

const ll N = 3e5, LOG = 20;
ll n, m, sumEdge = 0, parent[N + 1], sz[N + 1];
ll high[N + 1], par[N + 1][LOG + 1], maxEdge1[N + 1][LOG + 1], maxEdge2[N + 1][LOG + 1];
vector<pair<ll, ll>> edge[N + 1];

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query, a;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        query.pb({x, y, z});
    }

    sort(all(query), [](const QUERY &x, const QUERY &y) {
        return x.z < y.z;
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
        sz[x] += sz[y];
        parent[y] = x;
        return 1;
    }

    return 0;
}

void solve() {
    FOR(i, 1, n) {
        parent[i] = i;
        sz[i] = 1;
    }

    FOR(i, 0, query.size() - 1) {
        auto [x, y, z] = query[i];
        if(union_set(x, y)) {
            edge[x].pb({y, z});
            edge[y].pb({x, z});
            sumEdge += z;
        } else {
            a.pb({x, y, z});
        }
    }
}

pair<ll, ll> combine(ll x, ll y, ll z, ll t) {
    ll val[4] = {x, y, z, t};
    ll ans1 = -1, ans2 = -1;

    for(auto i : val) if(i != -1) {
        if(i > ans1) {
            ans2 = ans1;
            ans1 = i;
        } else if(i != ans1) {
            ans2 = max(ans2, i);
        }
    }

    return {ans1, ans2};
}

void dfs(ll u) {
    for(auto &[i, j] : edge[u]) if(i != par[u][0]) {
        high[i] = high[u] + 1;
        maxEdge1[i][0] = j;
        par[i][0] = u;
        dfs(i);
    }
}

void prepare() {
    FOR(i, 1, n) FOR(j, 1, LOG) {
        maxEdge1[i][j] = -1; maxEdge2[i][j] = -1;
    }
    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        auto k = combine(maxEdge1[i][j - 1], maxEdge2[i][j - 1],
                            maxEdge1[par[i][j - 1]][j - 1], maxEdge2[par[i][j - 1]][j - 1]);
        maxEdge1[i][j] = k.ft;
        maxEdge2[i][j] = k.sc;
    }
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    ll d = high[u] - high[v];
    FORD(i, LOG, 0) if((d >> i) & 1) u = par[u][i];
    if(u == v) return u;
    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

pair<ll, ll> getMax(ll u, ll v) {
    if(high[u] > high[v]) swap(u, v);
    ll k = lca(u, v);
    ll d1 = high[u] - high[k];
    ll d2 = high[v] - high[k];
    ll ans1 = -1, ans2 = -1;

    FORD(i, LOG, 0) {
        if((d1 >> i) & 1) {
            auto k = combine(ans1, ans2, maxEdge1[u][i], maxEdge2[u][i]);
            ans1 = k.ft; ans2 = k.sc;
            u = par[u][i];
        }

        if((d2 >> i) & 1) {
            auto k = combine(ans1, ans2, maxEdge1[v][i], maxEdge2[v][i]);
            ans1 = k.ft; ans2 = k.sc;
            v = par[v][i];
        }
    }

    return {ans1, ans2};
}

void write() {
    prepare();
    ll ans = 1e18;

    for(auto &[x, y, z] : a) {
        auto k = getMax(x, y);
        if(k.ft != z) {
            ans = min(ans, sumEdge - k.ft + z);
        } else if(k.sc != -1) {
            ans = min(ans, sumEdge - k.sc + z);
        }
    }

    cout << ans;
}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}