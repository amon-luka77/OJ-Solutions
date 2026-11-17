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
ll n, q, ans[N + 1], value[N + 1], preValue[N + 1], par[N + 1][LOG + 1], high[N + 1];
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
        high[i] = high[u] + 1;
        par[i][0] = u;
        dfs(i);
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

void prepare() {
    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];
}

void dfsAns(ll u, ll par) {
    ans[u] = value[u];
    for(auto i : edge[u]) if(i != par) {
        dfsAns(i, u);
        ans[u] += ans[i];
    }
}

void solve() {
    prepare();
    while(q --) {
        ll x, y, z; cin >> x >> y >> z;
        ll d = lca(x, y);
        value[d] -= 2 * z;
        value[x] += z;
        value[y] += z;

        preValue[d] += z;
    }

    dfsAns(1, -1);
    FOR(i, 1, n) cout << ans[i] + preValue[i] << ' ';
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