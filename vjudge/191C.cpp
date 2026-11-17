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
ll n, q;
vector<pair<ll, ll>> edge[N + 1];
void read() {
    cin >> n;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb({y, i}); edge[y].pb({x, i});
    }
}

ll node[4 * N + 1], lazy[4 * N + 1], ans[N + 1];
void push(ll id) {
    ll k = lazy[id]; if(!k) return; lazy[id] = 0;
    node[id << 1] += k; node[id << 1 | 1] += k;
    lazy[id << 1] += k; lazy[id << 1 | 1] += k;
}

void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {node[id] += val; lazy[id] += val; return;}
    ll mid = (l + r) >> 1; push(id);
    updated(id << 1, l, mid, i, j, val);
    updated(id << 1 | 1, mid + 1, r, i, j, val);
}

void getDown(ll id, ll l, ll r) {
    if(l == r) return ans[l] = node[id], void();
    ll mid = (l + r) >> 1; push(id);
    getDown(id << 1, l, mid); getDown(id << 1 | 1, mid + 1, r);
}

ll treeSize[N + 1], par[N + 1], high[N + 1], head[N + 1], pos[N + 1], cntPos = 0;
ll posEdge[N + 1], heavy[N + 1];
void dfs(ll u, ll parent) {
    treeSize[u] = 1; ll maxSize = 0; par[u] = parent;
    for(auto &[i, j] : edge[u]) if(i != parent) {
        high[i] = high[u] + 1; posEdge[j] = i;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h; pos[u] = ++cntPos;

    if(heavy[u]) hld(heavy[u], h);

    for(auto &[i, j] : edge[u]) if(i != par[u] && i != heavy[u]) hld(i, i);
}

void queryPath(ll u, ll v) {
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        updated(1, 1, n, pos[head[u]], pos[u], 1);
        u = par[head[u]];
    }
    if(high[u] > high[v]) swap(u, v); updated(1, 1, n, pos[u] + 1, pos[v], 1);
}

void solve() {
    dfs(1, 0); hld(1, 1);
    cin >> q;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y; queryPath(x, y);
    }
    getDown(1, 1, n);
    // FOR(i, 1, n) cerr << "dinh thu: " << i << " co pos la: " << pos[i] << " co gia tri la: " << node[i] << el;
    FOR(i, 1, n - 1) cout << ans[pos[posEdge[i]]] << ' ';
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