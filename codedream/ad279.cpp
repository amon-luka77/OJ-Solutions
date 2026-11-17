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

const ll N = 700;
ll n, m, scc = 0, cnt = 0, num[N + 1], low[N + 1], comp[N + 1], inDeg[N + 1], rootScc[N + 1];
vector<ll> edge[N + 1];
vector<pair<ll, ll>> canh;
set<pair<ll, ll>> b;
bool deleted[N + 1];
stack<ll> st;

void read() {
    cin >> n;
    ll x, y;
    while(cin >> x >> y) {
        edge[x].pb(y);
        canh.pb({x, y});
    }
}

void dfs(ll u) {
    num[u] = low[u] = ++cnt;
    st.push(u); deleted[u] = 1;

    for(auto i : edge[u]) {
        if(!num[i]) {
            dfs(i);
            low[u] = min(low[u], low[i]);
        }
        else if(deleted[i]) {
            low[u] = min(low[u], num[i]);
        }
    }

    if(num[u] == low[u]) {
        ++scc; rootScc[scc] = 1e18;
        while(1) {
            ll v = st.top(); st.pop();
            deleted[v] = 0;
            comp[v] = scc;
            rootScc[scc] = min(rootScc[scc], v);
            if(u == v) break;
        }
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i);

    for(auto &[i, j] : canh) if(comp[i] != comp[j] && b.find({comp[i], comp[j]}) == b.end()) {
        b.insert({comp[i], comp[j]});
        inDeg[comp[j]] ++;
    }

    vector<ll> ans;

    FOR(i, 1, scc) if(inDeg[i] == 0) {
        ans.pb(rootScc[i]);
    }

    cout << ans.size() << el;
    for(auto i : ans) cout << i << ' ';
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