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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
const ll LOG = 20;
const ll maxNode = 20 * N;
ll n, q, a[N + 1], high[N + 1], par[N + 1][LOG + 1], numNode = 0, root[N + 1];
vector<ll> b, edge[N + 1];

struct Node {ll ls, rs, val;};
Node node[maxNode + 1];

ll updated(ll preNode, ll l, ll r, ll i) {
    ll curNode = ++numNode; node[curNode] = node[preNode];
    if(l == r) {node[curNode].val ++; return curNode;}
    ll mid = (l + r) >> 1;
    if(i <= mid) node[curNode].ls = updated(node[curNode].ls, l, mid, i);
    else node[curNode].rs = updated(node[curNode].rs, mid + 1, r, i);
    node[curNode].val = node[node[curNode].ls].val + node[node[curNode].rs].val;
    return curNode;
}

ll get(ll rootU, ll rootV, ll rootLca, ll rootPar, ll l, ll r, ll i) {
    if(l == r) return l; 
    ll mid = (l + r) >> 1;

    ll sumLeft = node[node[rootU].ls].val + node[node[rootV].ls].val
                    - node[node[rootLca].ls].val - node[node[rootPar].ls].val;

    if(i <= sumLeft) return get(node[rootU].ls, node[rootV].ls, node[rootLca].ls, node[rootPar].ls, l, mid, i);
    else return get(node[rootU].rs, node[rootV].rs, node[rootLca].rs, node[rootPar].rs, mid + 1, r, i - sumLeft);
}

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {cin >> a[i]; b.pb(a[i]);}
    sort(all(b)); b.erase(unique(all(b)), b.end());
    FOR(i, 1, n) a[i] = upper_bound(all(b), a[i]) - b.begin();
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y); edge[y].pb(x);
    }
}

void dfs(ll u, ll parent) {
    root[u] = updated(root[parent], 1, n, a[u]);
    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        par[i][0] = u;
        dfs(i, u);
    }
}

void buildLca() {
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

ll query(ll u, ll v, ll k) {
    ll d = lca(u, v);
    return b[get(root[u], root[v], root[d], root[par[d][0]], 1, n, k) - 1];
}

void solve() {
    dfs(1, 0);
    buildLca();
    ll preAns = 0;
    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y >> z; x ^= preAns;
        preAns = query(x, y, z);
        cout << preAns << el;
    }

}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}
