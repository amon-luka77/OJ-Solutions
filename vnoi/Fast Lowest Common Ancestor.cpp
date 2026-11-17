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
#define MASK(i) (1 << i)
using namespace std;

const ll N = 1e5, LOG = 18;
ll n, q, X, Y, ans = 0, u1, v1, uj, vj, ua, va, cnt = 0;
ll node[2 * N + 1], pos[N + 1], minHigh[2 * N + 1][LOG + 1], high[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    node[++cnt] = u;
    pos[u] = cnt;

    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        node[++cnt] = u;
    }
}

#define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)

void prepare() {
    dfs(1, -1);
    FOR(i, 1, cnt) minHigh[i][0] = node[i];
    FOR(j, 1, LOG) FOR(i, 1, cnt - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }
}

ll lca(ll u, ll v) {
    ll pu = pos[u], pv = pos[v];
    if(pu > pv) swap(pu, pv);

    ll k = __lg(pv - pu + 1);
    return MIN_HIGH(minHigh[pu][k], minHigh[pv - MASK(k) + 1][k]);
}

void solve() {
    prepare();
    
    FOR(i, 1, q) {
        if(i == 1) {
            cin >> u1 >> v1 >> uj >> vj >> ua >> va;
            X = u1, Y = v1;
            ans = lca(X, Y);
        } else {
            ans ^= lca(X, Y);
        }

        X = (X * uj + ua) % n + 1;
        Y = (Y * vj + va) % n + 1;
    }

    cout << ans;
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