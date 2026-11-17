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
const ll maxNode = 20 * N;
ll n, r, high[N + 1], a[N + 1], tin[N + 1], tour[N + 1];
ll limit = 0, cnt = 0, numNode = 0, root[N + 1];
vector<ll> edge[N + 1], b, childHigh[N + 1];

struct Node {ll ls, rs, val;} node[maxNode + 1];

ll build(ll l, ll r) {
    ll curNode = ++numNode;
    if(l == r) {node[curNode].val = 1e18; return curNode;}
    ll mid = (l + r) >> 1;
    node[curNode].ls = build(l, mid); node[curNode].rs = build(mid + 1, r);
    node[curNode].val = min(node[node[curNode].ls].val, node[node[curNode].rs].val);
    return curNode;
}

ll updated(ll preNode, ll l, ll r, ll i, ll val) {
    ll curNode = ++numNode; node[curNode] = node[preNode];
    if(l == r) {node[curNode].val = val; return curNode;}
    ll mid = (l + r) >> 1;
    if(i <= mid) node[curNode].ls = updated(node[curNode].ls, l, mid, i, val);
    else node[curNode].rs = updated(node[curNode].rs, mid + 1, r, i, val);
    node[curNode].val = min(node[node[curNode].ls].val, node[node[curNode].rs].val);
    return curNode;
}

ll get(ll curNode, ll l, ll r, ll i, ll j) {
    if(l == i && r == j) return node[curNode].val;
    ll mid = (l + r) >> 1;
    if(j <= mid) return get(node[curNode].ls, l, mid, i, j);
    else if(i > mid) return get(node[curNode].rs, mid + 1, r, i, j);
    return min(get(node[curNode].ls, l, mid, i, mid), get(node[curNode].rs, mid + 1, r, mid + 1, j)); 
}

void read() {
    cin >> n >> r;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y); edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    tin[u] = ++cnt; childHigh[high[u]].pb(u); 
    limit = max(limit, high[u]);
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
    }
    tour[u] = cnt;
}

void solve() {
    dfs(r, 0); root[0] = build(1, n);
    
    root[0] = updated(root[0], 1, n, tin[r], a[r]);
    FOR(i, 1, limit) {
        root[i] = root[i - 1];
        for(auto j : childHigh[i]) root[i] = updated(root[i], 1, n, tin[j], a[j]);
    }

    ll q; cin >> q; ll preAns = 0;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y; x = (x + preAns) % n + 1, y = (y + preAns) % n;
        ll maxHigh = min(high[x] + y, limit);
        preAns = get(root[maxHigh], 1, n, tin[x], tour[x]); cout << preAns << el;
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