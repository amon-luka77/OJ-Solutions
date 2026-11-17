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
const ll LOG = 20;
ll n, m, q, root = 0;
vector<ll> edge[N + 1];
ll b[2 * N + 1], posIdx[N + 1];

void read() {
    cin >> n >> m >> q;
    FOR(i, 1, n) {
        ll x; cin >> x;
        if(x == i) root = i;
        else {edge[x].pb(i); edge[i].pb(x);}
    }
    FOR(i, 1, m) {cin >> b[i]; b[i + m] = b[i]; posIdx[b[i]] = i;}
}

struct sparse_table {
    ll node[2 * N + 1], high[N + 1], minHigh[2 * N + 1][LOG + 1], cnt = 0, pos[N + 1];

    void dfs(ll u, ll par) {
        node[++cnt] = u; pos[u] = cnt;
        for(auto i : edge[u]) if(i != par) {
            high[i] = high[u] + 1;
            dfs(i, u);
            node[++cnt] = u;
        }
    }

    #define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

    void build() {
        dfs(root, 0);
        FOR(i, 1, cnt) minHigh[i][0] = node[i];
        FOR(j, 1, LOG) FOR(i, 1, cnt - MASK(j) + 1) {
            minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
        }
    }

    ll lca(ll u, ll v) {
        u = pos[u], v = pos[v];
        if(u > v) swap(u, v);
        ll k = __lg(v - u + 1);
        return MIN_HIGH(minHigh[u][k], minHigh[v - MASK(k) + 1][k]);
    }
} st;

struct NODE {ll lca, val, maxDis;}; NODE node[8 * N + 1]; NODE cur;

NODE merge(NODE x, NODE y) {
    ll d = st.lca(x.lca, y.lca);
    ll dis1 = st.high[x.val] - st.high[d];
    ll dis2 = st.high[y.val] - st.high[d];

    return {d, (dis1 < dis2 ? y.val : x.val), max(dis1, dis2)};
}

void build(ll id, ll l, ll r) {
    if(l == r) return node[id] = NODE{b[l], b[l], 0}, void();
    ll mid = (l + r) >> 1; build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
    node[id] = merge(node[id << 1], node[id << 1 | 1]);
}

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) return node[id] = NODE{val, val, 0}, void();
    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id << 1, l, mid, i, val);
    else updated(id << 1 | 1, mid + 1, r, i, val);
    node[id] = merge(node[id << 1], node[id << 1 | 1]);
}

ll lastPos = 0;

bool  walkRight(ll id, ll l, ll r, ll i, ll j, ll limit) {
    if(l > j || r < i) return 1;
    if(i <= l && r <= j) {
        NODE t = merge(cur, node[id]);
        if(t.maxDis <= limit) {cur = t; lastPos = r; return 1;}
        if(l == r) return 0;
    } ll mid = (l + r) >> 1;

    if(!walkRight(id << 1, l, mid, i, j, limit)) return 0;
    return walkRight(id << 1 | 1, mid + 1, r, i, j, limit);
}

bool walkLeft(ll id, ll l, ll r, ll i, ll j, ll limit) {
    if(l > j || r < i) return 1;
    if(i <= l && r <= j) {
        NODE t = merge(cur, node[id]);
        if(t.maxDis <= limit) {cur = t; lastPos = l; return 1;}
        if(l == r) return 0;
    } ll mid = (l + r) >> 1;

    if(!walkLeft(id << 1 | 1, mid + 1, r, i, j, limit)) return 0;
    return walkLeft(id << 1, l, mid, i, j, limit);
}

void updatedQuery() {
    ll x, y; cin >> x >> y;
    ll A = posIdx[x], B = posIdx[y];
    posIdx[x] = B; posIdx[y] = A;

    if(B) {
        b[B] = b[B + m] = x;
        updated(1, 1, 2 * m, B, x);
        updated(1, 1, 2 * m, B + m, x);
    }

    if(A) {
        b[A] = b[A + m] = y;
        updated(1, 1, 2 * m, A, y);
        updated(1, 1, 2 * m, A + m, y);
    }
}

void getQuery() {
    ll u, limit; cin >> u >> limit; ll ans = 1;

    cur = {b[u], b[u], 0}; lastPos = u + m; walkLeft(1, 1, 2 * m, u + 1, u + m, limit);
    ans = max(ans, u + m - lastPos + 1);

    cur = {b[u], b[u], 0}; lastPos = u; walkRight(1, 1, 2 * m, u, u + m - 1, limit);
    ans = max(ans, lastPos - u + 1);

    cout << ans << el;
}

void solve() {
    st.build();
    build(1, 1, 2 * m);

//    FOR(i, 1, 2 * m) FOR(j, i + 1, 2 * m) {
//        cout << "xet doan: [";
//        FOR(k, i, j) cout << b[k] << ", ";
//        cout << "] " << "co lca chung la: " << get(1, 1, 2 * m, i, j).lca << el;
//    }

    while(q --) {
        ll opt; cin >> opt;
        if(opt == 1) updatedQuery();
        else getQuery();
    }
}

void write() {

}

int main() {
    boost;
//    file();
    read();
    solve();
    write();
    return 0;
}
