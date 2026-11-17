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
ll n, m, cnt = 0, articulation = 0, low[N + 1], num[N + 1];
vector<pair<ll, ll>> edge[N + 1];
vector<ll> bridge;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb({y, i});
        edge[y].pb({x, i});
    }
}

void dfs(ll u, ll par) {
    num[u] = low[u] = ++cnt;
    ll node = (par != 0);
    bool skip = 0;

    for(auto &[i, j] : edge[u]) {
        if(i == par && !skip) {skip = 1; continue;}
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            if(low[i] > num[u]) bridge.pb(j);
            if(low[i] >= num[u]) node ++;
        }
    }

    if(node >= 2) articulation ++;
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i, 0);

    cout << bridge.size() << el; sort(all(bridge));
    for(auto i : bridge) cout << i << ' ';
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