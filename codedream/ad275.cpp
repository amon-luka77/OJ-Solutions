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

const ll N = 1e4;
ll n, m, cnt = 0, num[N + 1], low[N + 1];
pair<ll, ll> canh[N + 1];
vector<ll> articulation, bridge;

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh[i] = {x, y};
        edge[x].pb({y, i});
        edge[y].pb({x, i});
    }
}

void dfs(ll u, ll par) {
    num[u] = low[u] = ++cnt;
    ll node = (par != 0); bool skip = 0;

    for(auto &[i, j] : edge[u]) {
        if(!skip && i == par) {skip = 1; continue;}
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            if(low[i] > num[u]) bridge.pb(j);
            if(low[i] >= num[u]) node ++;
        } 
    }

    if(node >= 2) articulation.pb(u);
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfs(i, 0);
    sort(all(bridge)); sort(all(articulation));

    cout << articulation.size() << ' ' << bridge.size() << el;
    for(auto i : articulation) cout << i << el;
    for(auto i : bridge) cout << canh[i].ft << ' ' << canh[i].sc << el;
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