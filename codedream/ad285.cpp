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

const ll N = 6e5;
ll n, m, cnt = 0, cntBridge = 0, num[N + 1], low[N + 1], szBridge[N + 1], treeSize[N + 1], comp[N + 1], ans[N + 1], cha[N + 1], sub[N + 1];
bool vs[N + 1], isBridge[N + 1];
vector<pair<ll, ll>> edge[N + 1];
pair<ll, ll> canh[N + 1];
vector<ll> articulation, newEdge[N + 1];

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
    num[u] = low[u] = ++cnt; sub[u] = 1;
    ll node = (id != 0);

    for(auto &[i, j] : edge[u]) if(j != id) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i, j);
            low[u] = min(low[u], low[i]);
            if(low[i] > num[u]) isBridge[j] = 1;
                sub[u] += sub[i];
            if(low[i] >= num[u]) {
                node ++;
            }
        }
    }

    if(node >= 2) articulation.pb(u);
}

void dfsBridge(ll u) {
    comp[u] = cntBridge;
    szBridge[cntBridge] ++;
    for(auto &[i, j] : edge[u]) if(!isBridge[j] && !comp[i]) dfsBridge(i);
}

void dfsAns(ll u, ll par, ll parent) {
    treeSize[u] = szBridge[u];
    cha[u] = parent;
    vs[u] = 1;
    for(auto i : newEdge[u]) if(i != par) {
        dfsAns(i, u, parent);
        treeSize[u] += treeSize[i];
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i, 0);

    FOR(i, 1, n) if(!comp[i]) {
        ++cntBridge; dfsBridge(i);
    }

    FOR(i, 1, m) if(isBridge[i]) {
        newEdge[comp[canh[i].ft]].pb(comp[canh[i].sc]);
        newEdge[comp[canh[i].sc]].pb(comp[canh[i].ft]);
    }

    FOR(i, 1, cntBridge) if(!vs[i]) dfsAns(i, 0, i);

    for(auto i : articulation) {
        ll x = treeSize[cha[comp[i]]];
        ans[i] = (x - sub[i]) * (sub[i] - 1);
        cout << i << ' ' << sub[i] << el;
    }

    FOR(i, 1, n) cout << ans[i] << ' ';
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