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
ll n, m, scc = 0, cnt = 0, low[N + 1], num[N + 1];
vector<ll> edge[N + 1];
stack<ll> st;
bool deleted[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
    }
}

void dfs(ll u) {
    num[u] = low[u] = ++cnt;
    st.push(u);

    for(auto v : edge[u]) if(!deleted[v]) {
        if(num[v]) low[u] = min(low[u], num[v]);
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == num[u]) {
        ++scc;
        while(1) {
            auto v = st.top(); st.pop();
            deleted[v] = 1;
            if(u == v) return;
        }
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) {
        dfs(i);
    }

    cout << scc;
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