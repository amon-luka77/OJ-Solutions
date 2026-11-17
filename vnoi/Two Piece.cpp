/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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

const ll N = 2e5;
ll n, q, treeSize[N + 1], par[N + 1];
bool vs[N + 1];

struct AA {
    ll u1 = 0; ll type1 = 0;
    ll u2 = 0; ll type2 = 0;
};

vector<AA> A[N + 1];
vector<tuple<ll, ll, ll>> path[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

ll getSize(ll u, ll parent) {
    treeSize[u] = 1;
    par[u] = parent;

    for(auto i : edge[u]) if(i != parent && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }

    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(const auto &i : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }
    return u;
}

void add(ll u, ll par, ll height, ll type, ll centroid) {
    if (height >= A[centroid].size()) {
        A[centroid].resize(height + 1);
    }

    auto &k = A[centroid][height];
    path[u].pb({centroid, height, type});

    if(k.u1 == 0) {
        k.u1 = u; k.type1 = type;
    } else if(k.u2 == 0 && k.type1 != type) {
        k.u2 = u; k.type2 = type;
    }

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        add(i, u, height + 1, type, centroid);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    ll pos = 1;
    A[centroid].resize(treeSize[u] + 1);
    path[centroid].pb({centroid, 0, -1});
    A[centroid][0] = {centroid, -1, 0, 0};

    for(auto i : edge[centroid]) if(!vs[i]) {
        add(i, centroid, 1, pos ++, centroid);
    }

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void query(ll u, ll k) {
    for(const auto &[centroid, height, type] : path[u]) {
        ll dis = k - height;
        if(dis < 0 || A[centroid].size() <= dis) continue;
        if(A[centroid][dis].type1 != 0 && A[centroid][dis].type1 != type) {
            cout << A[centroid][dis].u1 << el;
            return;
        } 
        if(A[centroid][dis].type2 != 0 && A[centroid][dis].type2 != type) {
            cout << A[centroid][dis].u2 << el;
            return;
        }
    }
    cout << -1 << el;
}

void solve() {
    solveCentroid(1);

    cin >> q;
    while(q --) {
        ll x, y; cin >> x >> y;
        query(x, y);
    }
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
