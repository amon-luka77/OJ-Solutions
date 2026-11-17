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

const ll N = 2e5, LOG = 19;
ll n, q, t, high[N + 1], par[N + 1][LOG + 1], preHighDown[N + 1], highUp[N + 1];
pair<ll, ll> highDown[N + 1];
vector<ll> edge[N + 1];

void read() {
    // cin >> t;
}

void dfs(ll u, ll parent) {
    for(auto i : edge[u]) if(i != parent) {
        par[i][0] = u;
        high[i] = high[u] + 1;
        dfs(i, u);
    }
} 

void buildLca() {
    dfs(1, 0);
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    ll d = high[u] - high[v];
    FORD(i, LOG, 0) if(BIT(d, i)) u = par[u][i];
    if(u == v) return u;
    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i]; v = par[v][i];
    }
    return par[u][0];
}

void dfsDown(ll u, ll par) {
    for(auto i : edge[u]) if(i != par) {
        dfsDown(i, u);

        ll k = highDown[i].sc + 1;

        if(k > highDown[u].sc) {
            preHighDown[u] = highDown[u].sc;
            highDown[u] = {i, k};
        } else {
            preHighDown[u] = max(preHighDown[u], k);
        }
    }
}

void dfsUp(ll u, ll par) {
    for(auto i : edge[u]) if(i != par) {
        highUp[i] = highUp[u] + 1;
        if(highDown[u].ft == i) highUp[i] = max(highUp[i], preHighDown[u] + 1);
        else highUp[i] = max(highUp[i], highDown[u].sc + 1);

        dfsUp(i, u);
    }
} 

ll getDis(ll u, ll v) {
    return high[u] + high[v] - 2 * high[lca(u, v)];
}

ll nhanhcon(ll u, ll target) {
    FORD(i, LOG, 0) if(BIT(target, i)) u = par[u][i];
    return u;
}

void query(ll u, ll v) {
    ll d = lca(u, v);
    ll dis = high[u] + high[v] - 2 * high[d];
    ll kc = (dis - 1) / 2;

    ll res = 0, p;

    if(high[v] - high[d] > kc) {
        p = v;
        // cout << p << el;
        FORD(i, LOG, 0) if(BIT(kc, i)) p = par[p][i];

        // cout << getDis(p, u) + highDown[p].sc << ' ';
    } else {
        kc -= (high[v] - high[d]);
        ll revKc = (high[u] - high[d] - kc);
        p = u;
        FORD(i, LOG, 0) if(BIT(revKc, i)) p = par[p][i];

        // ll x;
        // if(parHighDown[highDown[p].ft] == parHighDown[u]) x = preHighDown[p];
        // else x = highDown[p].sc;
        // cout << getDis(u, p) + max(x, highUp[p]) << ' ';
    }

    dis = 0;
    if(lca(u, p) == p && u != p) {
        dis = highUp[p];
        if(highDown[p].ft == nhanhcon(u, high[u] - high[p] - 1)) {
            dis = max(dis, preHighDown[p]);
        } else dis = max(dis, highDown[p].sc);
        // cout << "\ntruy van " << u << ' ' << v <<  " dinh xa nhat ma u nhay duoc la: " << p << " co khoang cach la: " << 77 << el;
    } else {
        dis = max(dis, highDown[p].sc);
    }

    cout << getDis(u, p) + dis << el;
}

// 1 2 3 4
// 1 2 3 4 5

void solve() {
    // while(t --) {
        cin >> n >> q;

        FOR(i, 1, n) {
            edge[i].clear();
            highUp[i] = 0;
            highDown[i] = {0, 0};
            preHighDown[i] = 0;
            high[i] = 0;
            FOR(j, 1, LOG) par[i][j] = 0;
        }

        FOR(i, 1, n - 1) {
            ll x, y; cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        } 

        buildLca();
        dfsDown(1, 0);
        dfsUp(1, 0);

        // cin >> q;
        FOR(i, 1, q) {
            ll x, y; cin >> x >> y;
            query(x, y);
        }

        // cerr << el;
        // FOR(i, 1, n) {
        //     cout << "dinh " << i << " co khoang cach voi dinh con xa nhat la: " << highDown[i].sc << el;
        // }

        // cerr << el << lca(4, 7) << ' ' << lca(7, 8) << ' ' << lca(1, 5) << el;
    // }
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