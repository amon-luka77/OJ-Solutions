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

const ll N = 1e4;
ll n, m, ans = 0, parent[N + 1][3], sz[N + 1][3];

struct EDGE {
    ll x, y, z, t;
};

vector<EDGE> edge[4];
bool vs[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        if(z == 3) {
            edge[3].pb({x, y, z, i});
        } 
        if(z == 1) {
            edge[1].pb({x, y, z, i});
        } 
        if(z == 2) {
            edge[2].pb({x, y, z, i});
        }
    }

    sort(all(edge[3]), [](const EDGE &x, const EDGE &y) {
        return x.t > y.t;
    });
}

ll find_set(ll k, ll i) {
    return k == parent[k][i] ? k : parent[k][i] = find_set(parent[k][i], i);
}

bool union_set(ll u, ll v, ll i) {
    ll x = find_set(u, i);
    ll y = find_set(v, i);

    if(x != y) {
        if(sz[x][i] < sz[y][i]) swap(x, y);
        parent[y][i] = x;
        sz[x][i] += sz[y][i];
        return 1;
    }

    return 0;
}

bool checkNode(ll u, ll v, ll i) {
    return find_set(u, i) != find_set(v, i);
}

void solve() { 
    FOR(i, 1, n) FOR(j, 1, 2) {
        parent[i][j] = i;
        sz[i][j] = 1;
    }

    for(auto &[x, y, z, i] : edge[3]) {
        if(checkNode(x, y, 1) && checkNode(x, y, 2)) {
            union_set(x, y, 1);
            union_set(x, y, 2);
            vs[i] = 1;
        } else {
            edge[1].pb({x, y, z, i});
            edge[2].pb({x, y, z, i});
        }
    }

    sort(all(edge[1]), [](const EDGE &x, const EDGE &y) {
        return x.t > y.t;
    });

    sort(all(edge[2]), [](const EDGE &x, const EDGE &y) {
        return x.t > y.t;
    });

    FOR(i, 0, edge[1].size() - 1) {
        auto [x, y, z, idx] = edge[1][i];
        // cout << "1 " << idx << el;
        if(union_set(x, y, 1)) {
            ans ++;
            vs[idx] = 1;
        }
    }

    FOR(i, 0, edge[2].size() - 1) {
        auto [x, y, z, idx] = edge[2][i];
        if(union_set(x, y, 2)) {
            ans ++;
            vs[idx] = 1;
        }
    }
    
    vector<ll> a;

    FOR(i, 1, m) if(!vs[i]) {
        a.pb(i);
    }

    cout << a.size() << el;
    for(auto i : a) cout << i << el;
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