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

const ll N = 3e5, LOG = 16;
ll n, minHigh[2 * N + 1][LOG + 1][3], node[2 * N + 1][3], pos[N + 1][3], high[N + 1][3];
vector<ll> edge[N + 1][3];

ll cnt = 0;

void read() {
    cin >> n;
    FOR(i, 2, n) {
        ll x, y; cin >> x; y = i;
        edge[x][1].pb(y);
        edge[y][1].pb(x);
    }
    
    FOR(i, 2, n) {
        ll x, y; cin >> x; y = i;
        edge[x][2].pb(y);
        edge[y][2].pb(x);
    }
}

void dfs(ll u, ll par, ll type) {
    node[++cnt][type] = u;
    pos[u][type] = cnt;
    
    for(auto i : edge[u][type]) if(i != par) {
        high[i][type] = high[u][type] + 1;
        dfs(i, u, type);
        node[++cnt][type] = u;
    }
}

#define MIN_HIGH(x, y, k) (high[x][k] < high[y][k] ? x : y)
#define MASK(i) (1 << i)

ll lca(ll u, ll v, ll type) {
    ll pu = pos[u][type];
    ll pv = pos[v][type];

    if(pu > pv) swap(pu, pv);
    ll k = __lg(pv - pu + 1);

    return MIN_HIGH(minHigh[pu][k][type], minHigh[pv - MASK(k) + 1][k][type], type);
}

void solve() {
    pair<ll, ll> ans; ll minDis = 1e18;
    dfs(1, -1, 1); 
    cnt = 0;
    dfs(1, -1, 2);

    FOR(i, 1, cnt) FOR(j, 1, 2) minHigh[i][0][j] = node[i][j];

    FOR(j, 1, LOG) FOR(i, 1, cnt - MASK(j) + 1) FOR(k, 1, 2) {
        minHigh[i][j][k] = MIN_HIGH(minHigh[i][j - 1][k], minHigh[i + MASK(j - 1)][j - 1][k], k);
    }

    FOR(i, 1, n) FOR(j, i + 1, n) {
        ll dis = high[i][1] + high[j][1] - 2 * high[lca(i, j, 1)][1] +
                    high[i][2] + high[j][2] - 2 * high[lca(i, j, 2)][2];
        if(minDis > dis) {
            minDis = dis;
            ans = {i, j};
        }
    }
    
    cout << minDis << el;
    cout << ans.ft << ' ' << ans.sc;
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