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

const ll N = 5e5;
ll n, m, q;

struct CANH {ll x, y, z;}; CANH canh[N + 1];
vector<pair<ll, ll>> E[N + 1];
void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        canh[i] = {x, y, z};
        E[z].pb({x, y});
    }
}

ll parent[N + 1], sz[N + 1], ans[N + 1];
stack<CANH> history;
ll find_set(ll k) {
    return k == parent[k] ? k : find_set(parent[k]);
}

bool union_set(ll u, ll v, ll k) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        if(k) history.push({x, y, sz[x]});
        parent[y] = x;
        sz[x] += sz[y];

        return 1;
    }

    return 0;
}

void rollback() {
    while(history.top().x != -1){
        auto [x, y, sizeX] = history.top(); history.pop();
        parent[y] = y;
        sz[x] = sizeX;
    }    
    history.pop();
}

map<ll, vector<ll>> query[N + 1];
void solve() {
    FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}
    
    cin >> q;
    FOR(i, 1, q) {
        ll k; cin >> k; ans[i] = 1;
        FOR(j, 1, k) {
            ll x; cin >> x;
            query[canh[x].z][i].pb(x);
        }
    }

    FOR(i, 1, 5e5) {
        for(auto &[u, b] : query[i]) if(ans[u]) {
            history.push({-1, 0, 0});
            for(auto j : b) if(!union_set(canh[j].x, canh[j].y, 1)) {ans[u] = 0; break;}
            rollback();
        }
        for(auto &[x, y] : E[i]) union_set(x, y, 0);
    }

    FOR(i, 1, q) cout << (ans[i] ? "YES\n" : "NO\n");
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