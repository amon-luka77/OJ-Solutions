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

const ll N = 2e5;
ll n, a[N + 1],  ans = 0, treeSize[N + 1];
ll up = 0, down = 0;
bool vs[N + 1];

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

ll getSize(ll u, ll par) {
    treeSize[u] = 1;
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }
    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }

    return u;
}

void addUp(ll u, ll par, ll edgeValue) {
    up ++;
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i] && edgeValue > j) {
        addUp(i, u, j);
    }
}

void addDown(ll u, ll par, ll edgeValue) {
    down ++;
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i] && edgeValue < j) {
        addDown(i, u, j);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    up = 0, down = 0;

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        addUp(i, centroid, j);
        addDown(i, centroid, j);
    }

    ans += down * up + down + up;

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void solve() {
    solveCentroid(1);
    cout << ans;
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