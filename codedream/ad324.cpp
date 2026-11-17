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

const ll N = 1e5;
ll n, k1, k2, ans = 0, treeSize[N + 1], bit[N + 1];
bool vs[N + 1];
vector<ll> edge[N + 1];
set<ll> a;

void read() {
    cin >> n >> k1 >> k2;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll getSum(ll l, ll r) {
    if(l > r) return 0;
    ll res = 0; l --;
    for(; l >= 1; l -= l & -l) res -= bit[l];
    for(; r >= 1; r -= r & -r) res += bit[r];
    return res;
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
    if(height > k2) return;
    ans += getSum(max(1LL, k1 - height + 1), k2 - height + 1);
    b.pb(height + 1);

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        cal(i, u, height + 1, b);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, 0, getSize(u, 0));
    vs[centroid] = 1;
    a.clear();

    for(auto i : edge[centroid]) if(!vs[i]) {
        vector<ll> b;
        cal(i, centroid, 1, b);
        for(auto j : b) {updated(j, 1); a.insert(j);}
    }

    for(auto i : a) updated(i, -getSum(i, i));

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void solve() {
    updated(1, 1);
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