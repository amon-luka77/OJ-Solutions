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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 2e5;
ll n, q, high[N + 1], treeSize[N + 1], heavy[N + 1], ans[N + 1];
vector<ll> edge[N + 1];
vector<pair<ll, ll>> query[N + 1];
map<ll, ll> *b[N + 1];

void read() {
    cin >> n;
    FOR(i, 2, n) {
        ll x; cin >> x;
        edge[x].pb(i); edge[i].pb(x);
    }
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    ll maxSize = 0;
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i]; heavy[u] = i;
        }
    }
}

void dfsAns(ll u, ll par) {
    for(auto i : edge[u]) if(i != par && i != heavy[u]) dfsAns(i, u);
    if(heavy[u]) {dfsAns(heavy[u], u); b[u] = b[heavy[u]];}
    else b[u] = new map<ll, ll>();

    for(auto i : edge[u]) if(i != par && i != heavy[u]) {
        for(auto &[x, y] : *b[i]) (*b[u])[x] += y;
        delete b[i];
    }
    (*b[u])[high[u]] ++;

    for(auto &[i, j] : query[u]) ans[j] = (*b[u])[i];
}

void solve() {
    cin >> q;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        query[x].pb({y, i});
    }

    dfs(1, 0);
    dfsAns(1, 0);

    FOR(i, 1, q) cout << ans[i] << el;
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}
