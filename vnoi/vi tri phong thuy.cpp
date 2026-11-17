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

const ll N = 5e4;
ll n, ans = 0, treeSize[N + 1], a[N + 1];
bool vs[N + 1], check[N + 1];

vector<ll> b, snt;
vector<ll> edge[N + 1];

void sang() {
    fill(check + 1, check + n + 1, 1);
    check[1] = 0;
    for(ll i = 2; i * i <= n; i ++) if(check[i]) {
        for(ll j = i * i; j <= n; j += i) {
            check[j] = 0;
        }
    }

    FOR(i, 1, n) if(check[i]) {
        snt.pb(i);
    }
}

void read() {
    cin >> n;
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

void add(ll u, ll par, ll height) {
    if(height > n) return;
    b.pb(height);
    for(auto i : edge[u]) if(i != par && !vs[i]) {
        add(i, u, height + 1);
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    vector<ll> amon;
    a[0] = 1; amon.pb(0);

    for(auto i : edge[centroid]) if(!vs[i]) {
        b.clear();
        add(i, centroid, 1);
        
        for(auto j : b) for(auto k : snt) {
            if(k >= j) ans += a[k - j];
        }

        for(auto j : b) {
            if(a[j] == 0) mark.pb(j);
            a[j] ++;
        }
    }

    for(auto i : amon) a[i] = 0;

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void solve() {
    sang();
    solveCentroid(1);
    double k = n * (n - 1) / 2.0;
    cout << fixed << setprecision(9) << ans / k;
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