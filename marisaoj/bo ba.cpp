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
ll n, q, high[N + 1], par[N + 1][LOG + 1], dis[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u) {
    for(auto i : edge[u]) if(i != par[u][0]) {
        par[i][0] = u;
        high[i] = high[u] + 1;
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

ll calDis(ll x, ll y) {
    ll k = lca(x, y);

    return high[x] + high[y] - 2 * high[k];
}

pair<ll, ll> minDis(ll x, ll y, ll z) {
    ll k = lca(x, y);

    return {k, calDis(x, k) + calDis(y, k) + calDis(z, k)};
}

void solve() {
    prepare();

    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y >> z;

        pair<ll, ll> dis1 = minDis(x, y, z);
        pair<ll, ll> dis2 = minDis(x, z, y);
        pair<ll, ll> dis3 = minDis(y, z, x);
        ll k = min({dis1.sc, dis2.sc, dis3.sc});

        if(k == dis1.sc) cout << dis1.ft << el;
        else if(k == dis2.sc) cout << dis2.ft << el;
        else cout << dis3.ft << el;
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