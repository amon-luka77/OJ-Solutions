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
ll n, m, q;
ll node[2 * N + 1];
ll edgeId[N + 1]; set<ll> posPeople[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> m >> q;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y); edge[y].pb(x);
    }
    FOR(i, 1, m) {ll x; cin >> x; posPeople[x].insert(i); edgeId[i] = x;}
    FOR(i, 1, 2 * n) node[i] = 1e9;
}

void updated(ll i, ll val) {
    for(node[i += n] = val; i > 1; i >>= 1) node[i >> 1] = min(node[i], node[i ^ 1]);
}

ll getMin(ll l, ll r) {
    ll res = 1e9;
    for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if(l & 1) res = min(res, node[l++]);
        if(!(r & 1)) res = min(res, node[r--]);
    }
    return res;
}

ll treeSize[N + 1], par[N + 1], heavy[N + 1], head[N + 1], pos[N + 1], high[N + 1], cntPos = 0;
void dfs(ll u, ll parent) {
    treeSize[u] = 1; ll maxSize = 0; par[u] = parent;
    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i]; heavy[u] = i;
        }
    }
} 

void hld(ll u, ll h) {
    head[u] = h; pos[u] = ++cntPos;
    if(!posPeople[u].empty()) {
        updated(pos[u], *posPeople[u].begin());
    }

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != par[u] && i != heavy[u]) hld(i, i);
}

ll getPath(ll u, ll v) {
    ll res = 1e9;
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        res = min(res, getMin(pos[head[u]], pos[u]));
        u = par[head[u]];
    }

    if(pos[u] > pos[v]) swap(u, v); res = min(res, getMin(pos[u], pos[v]));
    return res;
}

ll ans[11], cntAns = 0, cntRoll = 0;
ll rollback[11]; bool vs[N + 1]; vector<ll> amon;
void rollBack() {
    amon.clear();
    FOR(j, 1, cntRoll) {
        auto i = rollback[j];
        if(!vs[edgeId[i]]) {amon.pb(edgeId[i]); vs[edgeId[i]] = 1;}
        posPeople[edgeId[i]].insert(i);
    }

    for(auto i : amon) {
        auto it = posPeople[i].begin();
        updated(pos[i], *it); vs[i] = 0;
    }
}

void query(ll u, ll v, ll cntPeople) {
    cntAns = 0, cntRoll = 0;
    FOR(i, 1, cntPeople) {
        ll x = getPath(u, v); if(x == 1e9) break;
        rollback[++cntRoll] = x; ans[++cntAns] = x; posPeople[edgeId[x]].erase(x);
        if(!posPeople[edgeId[x]].empty()) {
            updated(pos[edgeId[x]], *posPeople[edgeId[x]].begin());
        }
        else updated(pos[edgeId[x]], 1e9);
    }
    rollBack();

    cout << cntAns << ' ';
    FOR(i, 1, cntAns) cout << ans[i] << ' ';
    cout << el;
}

void solve() {
    dfs(1, 0); hld(1, 1);
    // FOR(i, 1, n) {
    //     cerr << "\ndinh thu: " << i << el;
    //     if(!posPeople[i].empty()) {
    //         for(auto j : posPeople[i]) cerr << j << ' ';
    //     }
    // }
    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y >> z;
        query(x, y, z);
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