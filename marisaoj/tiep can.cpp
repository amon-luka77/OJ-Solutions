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

const ll N = 1e6;
ll n, m, scc= 0, cnt = 0, outdeg[N + 1];
ll num[N + 1], low[N + 1], comp[N + 1], sz[N + 1];
pair<ll, ll> canh[N + 1];
vector<ll> edge[N + 1];
stack<ll> st;
bool deleted[N + 1];

void read() {
    cin >> n >> m;
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
            comp[v] = scc;
            deleted[v] = 1;
            sz[scc] ++;
            if(v == u) break;
        }
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i);
    FOR(i, 1, m) {
        auto [x, y] = canh[i];
        if(comp[x] != comp[y]) {
            outdeg[comp[x]] ++;
        }
    }

    ll ans = 0, count = 0;

    FOR(i, 1, scc) if(!outdeg[i]) {
        count ++;
        ans = sz[i];
    }

    // cout << scc << el;

    if(count == 1) cout << ans;
    else cout << 0;
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