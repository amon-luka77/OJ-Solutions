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

const ll N = 2e5, LOG = 18;
ll n, q, high[N + 1], par[N + 1][LOG + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 2, n) {
        ll x; cin >> x;
        // cout << x << ' ' << i << el;
        edge[x].pb(i);
    }
}

void dfs(ll u, ll parent) {
    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        par[i][0] = u;
        dfs(i, u);
    }
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    ll d = high[u] - high[v];
    FORD(i, LOG, 0) if(BIT(d, i)) u = par[u][i];
    if(u == v) return u;
    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

void solve() {
    dfs(1, -1);
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];

    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        cout << lca(x, y) << el;
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