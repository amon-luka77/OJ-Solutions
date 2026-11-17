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

const ll N = 5e4, LOG = 17, block = 225;
ll n, q, a[N + 1], high[N + 1], par[N + 1][LOG + 1], dis[block + 1][N + 1];

vector<ll> edge[N + 1], color[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        color[a[i]].pb(i);
    }

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll parent) {
    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        par[i][0] = u;
        dfs(i, u);
    }
}

void bfs(const vector<ll> &b, ll t) {
    queue<ll> q;
    memset(dis[t], -1, sizeof dis[t]);
    for(auto i : b) {
        q.push(i); dis[t][i] = 0;
    } 

    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto i : edge[u]) if(dis[t][i] == -1) {
            dis[t][i] = dis[t][u] + 1;
            q.push(i);
        }
    }
}

vector<ll> nen;
void prepare() {
    dfs(1, -1);
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];

    FOR(i, 1, n) if(color[i].size() >= block) {
        nen.pb(i);
    }

    FOR(i, 0, nen.size() - 1) {
        bfs(color[nen[i]], i + 1);
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
    prepare();
    FOR(i, 1, q) {
        ll u, x; cin >> u >> x;
        if(color[x].size() < block) {
            ll ans = 1e9;
            for(auto i : color[x]) {
                ll d = lca(u, i);
                ans = min(ans, high[u] + high[i] - 2 * high[d]);
            }
            if(ans == 1e9) cout << -1 << el;
            else cout << ans << el;
        } else {
            x = lower_bound(all(nen), x) - nen.begin() + 1;
            cout << dis[x][u] << el;
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