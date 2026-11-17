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
ll n, k1, k2, ans = 0, maxHeight = 0;
ll bit[N + 1], sizeTree[N + 1];
bool vs[N + 1];

vector<ll> edge[N + 1], a;

void read() {
    cin >> n >> k1 >> k2;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

ll getSize(ll u, ll par) {
    sizeTree[u] = 1;

    for(auto i : edge[u]) if(i != par && !vs[i]) {
        sizeTree[u] += getSize(i, u);
    }

    return sizeTree[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        if(sizeTree[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }

    return u;
}

void updated(ll i, ll val) {
    i ++;

    for(; i <= n; i += i & -i) bit[i] += val;
}

ll getBit(ll l, ll r) {
    ll sum = 0; r ++;

    for(; l >= 1; l -= l & -l) sum -= bit[l];
    for(; r >= 1; r -= r & -r) sum += bit[r];

    return sum;
}

void countPairs(ll u, ll par, bool keep, ll height) {
    if(height > k2) return;
    maxHeight = max(maxHeight, height);
    if(keep) updated(height, 1);
    else ans += getBit(max(0LL, k1 - height), k2 - height);
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        countPairs(i, u, keep, height + 1);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    maxHeight = 0;

    for(auto i : edge[centroid]) if(!vs[i]) {
        countPairs(i, centroid, 0, 1);
        countPairs(i, centroid, 1, 1);
    }

    FOR(i, 1, maxHeight) updated(i, -getBit(i, i));

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void solve() {
    updated(0, 1);
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