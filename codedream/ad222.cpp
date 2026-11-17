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

const ll N = 1e5, LOG = 20;
ll n, q, high[N + 1], par[N + 1][LOG + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u) {
    for(auto i : edge[u]) if(i != par[u][0]) {
        par[i][0] = u;
        high[i] = high[u] + 1;
        dfs(i);
    }
} 

void prepare() {
    dfs(1);
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];
    high[0] = -1;
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    FORD(i, LOG, 0) if(high[par[u][i]] >= high[v]) u = par[u][i];

    if(u == v) return u;

    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }

    return par[u][0];
}

ll dis(ll u, ll v) {
    return high[u] + high[v] - 2 * high[lca(u, v)];
}

ll check2(ll x, ll y) {
    if(x <= y && (x - y) % 2 == 0) return 1;
    return 0;
}

bool check(ll x, ll y, ll a, ll b, ll k) {
    ll disAB = dis(a, b), disAX = dis(a, x), disBY = dis(b, y);
    ll disAY = dis(a, y), disBX = dis(b, x);

    if(check2(disAB, k) || check2(disAX + disBY + 1, k) ||
        check2(disAY + disBX + 1, k)) {
            return 1;
    }

    if(a == x && check2(1 + disBY, k)) return 1;
    if(a == y && check2(1 + disBX, k)) return 1;
    if(b == x && check2(1 + disAY, k)) return 1;
    if(b == y && check2(1 + disAX, k)) return 1;

    return 0;

}

void solve() {
    prepare();

    cin >> q;

    FOR(i, 1, q) {
        ll x, y, a, b, k; cin >> x >> y >> a >> b >> k;
        if(check(x, y, a, b, k)) {
            cout << 1 << el;
        } else {
            cout << 0 << el;
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