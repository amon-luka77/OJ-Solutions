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

const ll N = 3e4;
ll n, m, cnt = 0, scc = 0, low[N + 1], num[N + 1], rootScc[N + 1], comp[N + 1], inDeg[N + 1], outDeg[N + 1];
vector<pair<ll, ll>> canh;
set<pair<ll, ll>> b;
stack<ll> st;
vector<ll> edge[N + 1];
bool deleted[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh.pb({x, y});
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

    if(num[u] == low[u]) {
        ++scc;
        while(1) {
            ll v = st.top(); st.pop();
            deleted[v] = 1;
            comp[v] = scc;
            rootScc[scc] = v;
            if(v == u) break;
        }
    }
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i);
    for(auto &[i, j] : canh) if(comp[i] != comp[j] && b.find({comp[i], comp[j]}) == b.end()) {
        b.insert({comp[i], comp[j]});
        outDeg[comp[i]] ++;
        inDeg[comp[j]] ++;
    }

    ll x = 0, y = 0, dau = 0, cuoi = 0;
    FOR(i, 1, scc) {
        if(inDeg[i] == 0) {x ++, dau = i;}
        if(outDeg[i] == 0) {y ++; cuoi = i;}
    } 

    if(max(x, y) > 1) cout << "NO";
    else {cout << "YES" << el; cout << rootScc[dau] << ' ' << rootScc[cuoi];}
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