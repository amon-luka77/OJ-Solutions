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

const ll N = 3e5;
ll n, m, scc = 0, cnt = 0, num[N + 1], low[N + 1], comp[N + 1];
bool deleted[N + 1];
stack<ll> st;
vector<ll> edge[N + 1];
vector<pair<ll, ll>> canh;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        canh.pb({x, y});
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

    if(num[u] == low[u]) {
        ++scc;
        while(1) {
            ll v = st.top(); st.pop();
            comp[v] = scc;
            deleted[v] = 1;
            if(v == u) break;
        }
    }
}

void solve() { 
    FOR(i, 1, n) if(!num[i]) dfs(i);

    ll cntAns = 0;
    for(auto &[i, j] : canh) if(comp[i] != comp[j]) cntAns ++;
    cout << cntAns;
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