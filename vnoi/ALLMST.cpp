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

const ll N = 2e5;
ll n, m, cnt = 0, num[N + 1], low[N + 1], parent[N + 1], sz[N + 1];
bool ans[N + 1];

vector<pair<ll, ll>> edge[N + 1];

struct CANH {
    ll x, y, z, t;
};

vector<CANH> canh;

set<ll> curEdge;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        canh.pb({x, y, z, i});
    }

    sort(all(canh), [](const CANH &x, const CANH &y) {
        return x.z < y.z;
    });

    FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}
}

void dfs(ll u, ll id) {
    num[u] = low[u] = ++cnt;

    for(auto &[i, j] : edge[u]) if(j != id) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfs(i, j);

            low[u] = min(low[u], low[i]);

            if(low[i] > num[u]) ans[j] = 1;
        }
    }
}

ll find_set(ll k) {
    return parent[k] == k ? k : parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
    }
}

void solve() {
    FOR(i, 0, m - 1) {
        ll j = i;

        while(j <= m - 1 && canh[i].z == canh[j].z) {
            ll x = find_set(canh[j].x), y = find_set(canh[j].y);
            if(x != y) {
                edge[x].pb({y, canh[j].t});
                edge[y].pb({x, canh[j].t});
                curEdge.insert(x); 
                curEdge.insert(y); 
                // cerr << canh[j].t << el;
            } 

            j ++;
        }

        for(auto k : curEdge) if(!num[k]) dfs(k, 0);

        FOR(k, i, j - 1) union_set(canh[k].x, canh[k].y);

        for(auto k : curEdge) {
            num[k] = 0; low[k] = 0;
            edge[k].clear();
        }
        cnt = 0; curEdge.clear();


        // cerr << i << ' ' << j - 1 << el;
        i = j - 1;
    }

    FOR(i, 1, m) cout << (ans[i] ? "Yes" : "No") << ' ';
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