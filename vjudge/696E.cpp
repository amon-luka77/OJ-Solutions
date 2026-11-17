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
ll n, m, q, treeSize[N + 1], high[N + 1], par[N + 1], head[N + 1], pos[N + 1], heavy[N + 1], cnt = 0;
pair<ll, ll> node[4 * N + 1]; ll lazy[4 * N + 1];
ll edgeId[N + 1];
vector<ll> edge[N + 1], girl[N + 1];

void read() {
    cin >> n >> m >> q;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    FOR(i, 1, m) {
        ll x; cin >> x;
        edgeId[i] = x;
        girl[x].pb(i);
    }
} 

// startHld-----------------------------

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    ll maxSize = 0;
    par[u] = parent;
    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++cnt;

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != par[u] && i != heavy[u]) hld(i, i);
}

// endHld-----------------------------

// startSegtree-----------------------------

void push(ll id) {
    if(!lazy[id]) return;
    ll k = lazy[id]; lazy[id] = 0;

    node[id << 1].ft += k;
    node[id << 1 | 1].ft += k;
    lazy[id << 1] += k;
    lazy[id << 1 | 1] += k;
}

pair<ll, ll> merge(const pair<ll, ll> &x, const pair<ll, ll> &y) {
    if(x.ft != y .ft) return (x.ft < y .ft ? x : y);
    if(x.sc == 1e18) return y;
    if(y.sc == 1e18) return x;
    return (edgeId[x.sc] < edgeId[y.sc] ? x : y);
} 

void updated(ll id, ll l, ll r, ll i, ll val, ll idGirl) {
    if(l == r){
        node[id] = {val, idGirl};
        return;
    }

    push(id);
    ll mid = (l + r) >> 1;

    if(i <= mid) updated(id << 1, l, mid, i, val, idGirl);
    else updated(id << 1 | 1, mid + 1, r, i, val, idGirl);

    node[id] = merge(node[id << 1], node[id << 1 | 1]);
}

void updatedLazy(ll id, ll l, ll r, ll i, ll j, ll val) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {
        node[id].ft += val;
        lazy[id] += val;
        return;
    }

    push(id);
    ll mid = (l + r) >> 1;

    updatedLazy(id << 1, l, mid, i, j, val);
    updatedLazy(id << 1 | 1, mid + 1, r, i, j, val);

    node[id] = merge(node[id << 1], node[id << 1 | 1]);
}

pair<ll, ll> getMin(ll id, ll l, ll r, ll i, ll j) {
    if(l > j || r < i) return {1e18, 1e18};
    if(i <= l && r <= j) return node[id];

    push(id);
    ll mid = (l + r) >> 1;

    return merge(getMin(id << 1, l, mid, i, j), getMin(id << 1 | 1, mid + 1, r, i, j));
}

// endSegtree-----------------------------

// startQuery-----------------------------

ll getMinGirl(ll u, ll v) {
    pair<ll, ll> res = {1e18, 1e18};
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        res = merge(res, getMin(1, 1, n, pos[head[u]], pos[u]));

        u = par[head[u]];
    }

    if(pos[u] > pos[v]) swap(u, v);
    res = merge(res, getMin(1, 1, n, pos[u], pos[v]));

    if(res.ft == 1e18) return 0;
    else {
        if(!girl[edgeId[res.sc]].empty()) {
            ll v = girl[edgeId[res.sc]].back(); girl[edgeId[res.sc]].pop_back();
            updated(1, 1, n, pos[edgeId[res.sc]], res.ft - res.sc + v, v);
        } else {            
            updated(1, 1, n, pos[edgeId[res.sc]], 1e18, 1e18);
        }

        // if(ok) cerr << res << ' ' << node[pos[edgeId[res]]] + base[pos[edgeId[res]]] << ' ';
        return res.sc;
    }
}

void getQuery(ll u, ll v, ll k) {
    vector<ll> ans;

    while(k --) {
        ll x = getMinGirl(u, v);
        if(!x) break;
        // cerr << x << el;
        ans.pb(x);
    }

    cout << ans.size() << ' ';
    for(auto i : ans) cout << i << ' ';
    cout << el;
}

// endQuery-----------------------------

void solve() {
    // cerr << "start hld" << endl;
    dfs(1, 0);
    hld(1, 1);
    // cerr << "end hld" << endl;

    FOR(i, 1, 4 * n) node[i] = {1e18, 1e18};

    // cerr << "1" << el;
    FOR(i, 1, n) if(!girl[i].empty()) {
        sort(all(girl[i]), greater<ll>());
        // cerr << "dinh thu " << i << endl;
        // for(auto j : girl[i]) cerr << j << ' ';
        // cerr << endl;
        updated(1, 1, n, pos[i], girl[i].back(), girl[i].back()); 
        // cerr << girl[i].back() << el;
        girl[i].pop_back();
    }
    // cerr << 1 << endl;

    // cerr << "start" << endl;

    while(q --) {
        ll x, y, z, t; cin >> x >> y >> z;
        if(x == 1) {cin >> t; getQuery(y, z, t);}
        else {
            updatedLazy(1, 1, n, pos[y], pos[y] + treeSize[y] - 1, z);
            // print(1, 1, n);
            // cerr << y << ' ' << pos[y] << el;
        }
    }

    // cerr << "end" << endl;
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