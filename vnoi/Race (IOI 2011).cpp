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
ll n, k, ans = 1e18, treeSize[N + 5];
map<ll, ll> a;
vector<pair<ll, ll>> edge[N + 5];
bool vs[N + 5];

void read() {
    cin >> n >> k;

    FOR(i, 1, n - 1)  {
        ll x, y, z; cin >> x >> y >> z;
        x ++, y ++;
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

void cal(ll u, ll par, ll dis, ll height, bool keep) {
    if(dis > k) return;
    if(keep) {
        if(a.find(dis) != a.end()) a[dis] = min(a[dis], height);
        else a[dis] = height;
    } else {
        if(a.find(k - dis) != a.end()) ans = min(ans, a[k - dis] + height);
    }

    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        cal(i, u, dis + j, height + 1, keep);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    a[0] = 0;

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        cal(i, centroid, j, 1, 0);
        cal(i, centroid, j, 1, 1);
    }

    a.clear();

    for(auto &[i, j] : edge[centroid]) if (!vs[i]) {
        solveCentroid(i);
    }
}

void solve() {
    solveCentroid(1);
    if(ans == 1e18) cout << -1;
    else cout << ans;
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