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

const ll N = 1e5;
ll n, q, cnt = 0, pos[N + 1], high[N + 1];
ll startTour[N + 1], endTour[N + 1], node[N << 2 + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 2, n) {
        ll x; cin >> x;
        edge[x].pb(i);
        // cerr << i << ' ' << x << el;
    }
    // cerr << el;
}

void updated(ll id, ll l, ll r, ll i, ll val) {
    if(l == r) {
        node[id] += val; node[id] = max(0LL, node[id]);
        return;
    }
    ll mid = (l + r) >> 1;
    if(i <= mid) updated(id << 1, l, mid, i, val);
    else updated(id << 1 | 1, mid + 1, r, i, val);
    node[id] = max(node[id << 1], node[id << 1 | 1]);
}

ll getMax(ll id, ll l, ll r, ll i, ll j) {
    if(l == i && r == j) return node[id];
    ll mid = (l + r) >> 1;
    if(j <= mid) return getMax(id << 1, l, mid, i, j);
    else if(i > mid) return getMax(id << 1 | 1, mid + 1, r, i, j);
    else return max(getMax(id << 1, l, mid, i, mid), getMax(id << 1 | 1, mid + 1, r, mid + 1, j));
}

void dfs(ll u, ll par) {
    startTour[u] = ++cnt; pos[u] = cnt; 
    high[u] = high[par] + 1; updated(1, 1, n, pos[u], high[u] - 1);
    for(auto i : edge[u]) if(i != par) dfs(i, u);
    endTour[u] = cnt;
}

void solve() {
    dfs(1, 0);
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        if(x == 1) updated(1, 1, n, pos[y], -1);
        else cout << max(0LL, getMax(1, 1, n, startTour[y], endTour[y]) - (high[y] - 1)) << el;
    }
}

void write() {

}

int main() {
    boost;
    // file();
    read();
    solve();
    write();
    return 0;
}