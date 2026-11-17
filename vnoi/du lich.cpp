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

const ll N = 3e5;
ll n, k, a[N + 1], treeSize[N + 1], vs[N + 1], check[N + 1];
ll nextNode[N + 1];
vector<ll> edge[N + 1];
vector<pair<ll, ll>> path[N + 1], b[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

ll getSize(ll u, ll par) {
    treeSize[u] = 1;
    
    for(auto i  : edge[u]) if(i != par && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }

    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }
    return u;
}

void add(ll u, ll par, ll height, ll centroid) {
    b[centroid].pb({a[u] - height, u});
    path[u].pb({centroid, height});

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        add(i, u, height + 1, centroid);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    b[centroid].pb({0LL, centroid});
    path[centroid].pb({centroid, 0LL});

    for(auto i : edge[centroid]) if(!vs[i]) {
        add(i, centroid, 1, centroid);
    }

    sort(all(b[centroid]), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        if(x.ft != y.ft) return x.ft > y.ft;
        return x.sc < y.sc;
    });

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

ll findNext(ll u) {
    ll ans = 0, maxD = -1e18;
    for(auto &[centroid, dis] : path[u]) {
        for(auto &[val, v] : b[centroid]) if(v != u && ((maxD < val - dis) || (maxD == val - dis && v < ans))) {
            maxD = val - dis;
            ans = v;
        }
    }

    return ans;
}

void solve() {
    solveCentroid(1);
    FOR(i, 1, n) {
        nextNode[i] = findNext(i);
        cout << i << ' ' << nextNode[i] << el;
    }

    vector<ll> ans;
    ll u = 1;

    while(!check[u]) {
        ans.pb(u);
        check[u] = 1;
        u = nextNode[u];
    }

    for(auto i : ans) cout << i << ' ';
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