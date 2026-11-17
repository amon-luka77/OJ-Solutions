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
ll n, k, treeSize[N + 1];
bool vs[N + 1];
ll a[N + 1];
vector<ll> edge[N + 1];
ll ans = 0;

void read() {
    cin >> n >> k;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

ll getSize(ll u, ll par) {
    treeSize[u] = 1;
    for(auto i : edge[u]) if(i != par && !vs[i]) {
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

void cal(ll u, ll par, ll height, vector<ll> &b) {
    if(height > k) return;
    ans += a[k - height];
    b.pb(height);

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        cal(i, u, height + 1, b);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, 0, getSize(u, 0));
    vs[centroid] = 1; 
    a[0] = 1; vector<ll> c;

    for(auto i : edge[centroid]) if(!vs[i]) {
        vector<ll> b;
        cal(i, centroid, 1, b);
        for(auto j : b) {a[j] ++; c.pb(j);}
    }

    for(auto i : c) a[i] --;

    for(auto i : edge[centroid]) if(!vs[i]) {
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