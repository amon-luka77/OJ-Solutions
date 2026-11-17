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

const ll N = 1e5;
ll n, m, cnt = 0, pos[N + 1], treeSize[N + 1], heavy[N + 1], head[N + 1];
ll bit[N + 1], par[N + 1], high[N + 1], edgeId[N + 1];

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb({y, i});
        edge[y].pb({x, i});
    }
}

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll get(ll i) {
    ll sum = 0;
    for(; i >= 1; i -= i & -i) sum += bit[i];
    return sum;
}

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    par[u] = parent;
    ll maxSize = 0;

    for(auto &[i, j] : edge[u]) if(i != parent) {
        edgeId[j] = i;
        high[i] = high[u] + 1;
        dfs(i, u);

        treeSize[u] += treeSize[i];
        if(treeSize[i] > maxSize) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++cnt;

    if(heavy[u]) hld(heavy[u], h);

    for(auto &[i, j] : edge[u]) if(i != par[u] && i != heavy[u]) {
        hld(i, i);
    }
}

void updatedQuery(ll u, ll v) {
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        // pos[head[u]] -> pos[u];
        updated(pos[head[u]],  1); updated(pos[u] + 1, -1); 
        u = par[head[u]];
    }

    if(high[u] > high[v]) swap(u, v);
    // pos[u] + 1 -> pos[v];
    updated(pos[u] + 1, 1); updated(pos[v] + 1, -1); 
}

void solve() {
    dfs(1, -1);
    hld(1, 1);

    FOR(i, 1, m) {
        ll x, l, r; cin >> x;
        if(x == 1) {
            cin >> l >> r;
            updatedQuery(l, r);
        } else {
            cin >> l;
            cout << get(pos[edgeId[l]]) << el;
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