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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 222222;
ll n, m, low[N + 1], num[N + 1], isBridge[N + 1], sz[N + 1], mark[N + 1];
ll cnt = 0, bridge = 0, cntBridge = 0, comp[N + 1], ans = 0, szTree[N + 1];
ll parent[N + 1];
pair<ll, ll> canh[N + 1];
vector<pair<ll, ll>> edge[N + 1];
vector<ll> newEdge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh[i] = {x, y};
        edge[x].pb({y, i});
        edge[y].pb({x, i});
    }
}

void dfs(ll u, ll id) {
    num[u] = low[u] = ++cnt;

    for(auto &[i, j] : edge[u]) if(id != j) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i, j);
            low[u] = min(low[u], low[i]);
            if(low[i] > num[u]) isBridge[j] = 1;
        }
    }
}

void dfsBridge(ll u) {
    comp[u] = cntBridge;
    szTree[cntBridge] ++;

    for(auto &[i, j] : edge[u]) if(!comp[i] && !isBridge[j]) {
        dfsBridge(i);
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i, 0);
    FOR(i, 1, n) if(!comp[i]) {
        cntBridge ++;
        dfsBridge(i);
    }
    FOR(i, 1, cntBridge) {
        parent[i] = i;
        sz[i] = 1;
    }

    // FOR(i, 1, cntBridge) cout << i << ' ' << sz[i] << el;

    FOR(i, 1, m) if(isBridge[i]) {
        ll x = comp[canh[i].ft], y = comp[canh[i].sc];
        if(szTree[x] == 1 && szTree[y] == 1) union_set(x, y);
        else {
            newEdge[x].pb(y);
            newEdge[y].pb(x);
        }
    }

    FOR(i, 1, cntBridge) {
        if(szTree[i] == 1) {
            ll x = find_set(i);
            if(!mark[x]) {
                ans += sz[x] * (sz[x] - 1) / 2;
                mark[x] = 1;
            }
        }
        else {
            for(auto j : newEdge[i]) if(szTree[j] == 1) ans += sz[find_set(j)];
        }
    }

    // FOR(i, 1, cntBridge) cout << i << ' ' << dp[i] << el;

    // cout << bridge << el;
    // cout << bridge

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