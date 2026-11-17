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
#define MASK(i) (1 << (i))
using namespace std;

const ll N = 1e5, LOG = 20;
ll n, m, a[N + 1], cntPos = 0, cnt = 0;
ll high[N + 1], minHigh[2 * N][LOG + 1], node[2 * N], pos[N + 1], state[N + 1];

vector<ll> edge[N + 1];

pair<ll, ll> b[N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 1, m) {
        cin >> a[i];
        a[i] ++;
    }
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        x ++; y ++;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    node[++cntPos] = u;
    pos[u] = cntPos;
    state[u] = ++cnt;
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        node[++cntPos] = u;
    }
}

ll MIN_HIGH(ll x, ll y) {
    return (high[x] < high[y] ? x : y);
}

void prepare() {
    dfs(1, -1);
    FOR(i, 1, cntPos) minHigh[i][0] = node[i];
    FOR(j, 1, LOG) FOR(i, 1, cntPos - MASK(j) + 1) {
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

    FOR(i, 1, m) {
        b[i] = {pos[a[i]], a[i]};
    }

    sort(b + 1, b + m + 1);

    ll ans = 0;

    FOR(i, 1, m - 1) {
        ans += (high[b[i].sc] + high[b[i + 1].sc] - 2 * high[lca(b[i].sc, b[i + 1].sc)]);
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
