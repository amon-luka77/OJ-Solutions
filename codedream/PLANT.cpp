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
using namespace std;

const ll N = 1e5 + 5;
ll n, q, edgeId = 1;

struct Query {
    char type;
    ll u;
    ll newNode;
} query[N];

ll tin[N], tout[N], cnt = 0;
vector<ll> edge[N];

ll node[4 * N], lazy[4 * N];

void push(ll id) {
    if (lazy[id] == -1) return;

    lazy[id << 1] = lazy[id];
    node[id << 1] = 0;

    lazy[id << 1 | 1] = lazy[id];
    node[id << 1 | 1] = 0;

    lazy[id] = -1;
}

void updatePos(ll id, ll l, ll r, ll i) {
    if (l == r) {
        node[id] = 1;
        return;
    }
    push(id);
    ll mid = (l + r) >> 1;
    if (i <= mid) updatePos(id << 1, l, mid, i);
    else updatePos(id << 1 | 1, mid + 1, r, i);
    node[id] = node[id << 1] + node[id << 1 | 1];
}

void updated(ll id, ll l, ll r, ll i, ll j) {
    if (l > j || r < i) return;
    if (i <= l && r <= j) {
        node[id] = 0;
        lazy[id] = 0;
        return;
    }
    push(id);
    ll mid = (l + r) >> 1;
    updated(id << 1, l, mid, i, j);
    updated(id << 1 | 1, mid + 1, r, i, j);
    node[id] = node[id << 1] + node[id << 1 | 1];
}

ll get(ll id, ll l, ll r, ll i, ll j) {
    if (l > j || r < i) return 0;
    if (i <= l && r <= j) return node[id];
    push(id);
    ll mid = (l + r) >> 1;
    return get(id << 1, l, mid, i, j) + get(id << 1 | 1, mid + 1, r, i, j);
}

void dfs(ll u, ll par) {
    tin[u] = ++cnt;
    for (auto v : edge[u]) {
        if (v != par) dfs(v, u);
    }
    tout[u] = cnt;
}

void read() {
    cin >> q;
    FOR(i, 1, q) {
        cin >> query[i].type >> query[i].u;
        query[i].u ++;

        if (query[i].type == '+') {
            edgeId++;
            edge[query[i].u].pb(edgeId);
            edge[edgeId].pb(query[i].u);
            query[i].newNode = edgeId;
        }
    }
    n = edgeId;
}

void solve() {
    memset(lazy, -1, sizeof lazy);

    dfs(1, 0);

    updatePos(1, 1, n, tin[1]);

    FOR(i, 1, q) {
        if (query[i].type == '+') {
            updatePos(1, 1, n, tin[query[i].newNode]);
        }
        else if (query[i].type == '-') {
            updated(1, 1, n, tin[query[i].u], tout[query[i].u]);
        }
        else if (query[i].type == '?') {
            cout << get(1, 1, n, tin[query[i].u], tout[query[i].u]) << el;
        }
    }
}

int main() {
    boost;
    freopen("PLANT.inp", "r", stdin);
    freopen("PLANT.out", "w", stdout);
    read();
    solve();
    return 0;
}
