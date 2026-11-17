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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5;
ll n, m, k, q, X[N + 1];

vector<pair<ll, ll>> edge[N + 1], query;


void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }

    cin >> k;
    FOR(i, 1, k) cin >> X[i];
    
    cin >> q;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        query.pb({x, y});
    }
}

namespace Sub4 {
    const ll LOG = 18;
    ll minA[N + 1][LOG + 1], par[N + 1][LOG + 1], high[N + 1], d[N + 1];

    bool check() {
        return (m == n - 1);
    }

    void dijkstra() {
        FOR(i, 1, n) d[i] = 1e18;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        FOR(i, 1, k) {
            d[X[i]] = 0; pq.push({0, X[i]});
        }

        while(!pq.empty()) {
            auto [dis, u] = pq.top(); pq.pop();

            if(dis > d[u]) continue;

            for(auto &[i, j] : edge[u]) if(dis + j < d[i]) {
                d[i] = dis + j;
                pq.push({d[i], i});
            }
        }
    }

    void dfs(ll u, ll parent) {
        for(auto &[i, j] : edge[u]) if(i != parent) {
            par[i][0] = u;
            high[i] = high[u] + 1;
            dfs(i, u);
        } 
    }

    ll lca(ll u, ll v) {
        if(high[u] < high[v]) swap(u, v);
        ll dis = high[u] - high[v];
        FORD(i, LOG, 0) if(BIT(dis, i)) u = par[u][i];
        if(u == v) return u;
        FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
        return par[u][0];
    }

    ll getQuery(ll u, ll v) {
        ll c = lca(u, v);
        // cout << c << ' ' << u << ' ' << v << el;
        ll ans = 1e18;

        ll dis = high[u] - high[c];
        FORD(i, LOG, 0) if(BIT(dis, i)) {
            ans = min(ans, minA[u][i]);
            u = par[u][i];
        }

        dis = high[v] - high[c];
        FORD(i, LOG, 0) if(BIT(dis, i)) {
            ans = min(ans, minA[v][i]);
            v = par[v][i];
        }

        return min(ans, d[c]);
    }

void solve() {
    memset(minA, 0x3f, sizeof minA);
    dijkstra();
    dfs(1, -1);
    FOR(i, 1, n) minA[i][0] = d[i];
    FOR(j, 1, LOG) FOR(i, 1, n) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        minA[i][j] = min(minA[i][j - 1], minA[par[i][j - 1]][j - 1]);
    }

    for(auto &[x, y] : query) {
        cout << getQuery(x, y) << el;
    }
}
}

void solve() {
    if(Sub4::check()) {Sub4::solve(); return;}
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