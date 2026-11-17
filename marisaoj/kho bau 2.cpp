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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 1e5;
ll n, m, low[N + 1], num[N + 1], a[N + 1];
ll deleted[N + 1], dp[N + 1], sum[N + 1];
ll cnt = 0, scc = 0, comp[N + 1], vs[N + 1];
pair<ll, ll> canh[N + 1];
ll ans = 0;
vector<ll> edge[N + 1], newEdge[N + 1];
stack<ll> st;

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh[i] = {x, y};
        edge[x].pb(y);
    }
}

void dfs(ll u) {
    num[u] = low[u] = ++cnt;
    st.push(u);

    for(auto i : edge[u]) if(!deleted[i]) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i);
            low[u] = min(low[u], low[i]);
        }
    }

    if(low[u] == num[u]) {
        ++scc;
        while(1) {
            ll v = st.top(); st.pop();
            deleted[v] = 1;
            comp[v] = scc;
            sum[scc] += a[v];
            if(u == v) break;
        }
    }
}

void dfsAns(ll u) {
    vs[u] = 1;
    dp[u] = sum[u];
    for(auto i : newEdge[u]) {
        if(!vs[i]) dfs(i);
        dp[u] = max(dp[u], sum[u] + dp[i]);
    }

    ans = max(ans, dp[u]);
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i);
    FOR(i, 1, m) {
        auto [u, v] = canh[i];
        if(comp[u] != comp[v]) {
            newEdge[comp[u]].pb(comp[v]);
        }
    }

    FOR(i, 1, scc) if(!vs[i]) dfsAns(i);

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