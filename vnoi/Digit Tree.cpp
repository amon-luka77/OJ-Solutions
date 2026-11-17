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

const ll N = 1e5;
ll n, m, ans = 0, mod, inv10;
ll treeSize[N + 1];
bool vs[N + 1];

vector<pair<ll, ll>> edge[N + 1];
vector<pair<ll, ll>> curUp, curDown;

map<ll, ll> up, down;

void read() {
    cin >> n >> m;
    mod = m;
    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        x ++; y ++;
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

ll power(ll x, ll y) {
    if(y == 0) return 1;
    ll t = power(x, y / 2);
    ll res = (t * t) % mod;
    if(y % 2) res = (res * x) % mod;
    return res;
}

void add(ll u, ll par, ll num, ll revNum, ll height) {
    curDown.pb({num, height});
    curUp.pb({revNum, height});
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        ll x = (num * 10 % mod + j) % mod;
        ll y = (power(10, height) * j % mod + revNum) % mod;
        add(i, u, x, y, height + 1);
    }
}

void cal() {
    for(auto &[x, y] : curUp) {
        ll X = (mod - (x % mod)) % mod;
        ans += down[X];
    }

    for(auto &[x, y] : curDown) {
        ll X = (mod - (x % mod)) % mod;
        ll Y = X * power(inv10, y) % mod;
        ans += up[Y]; 
    }
}

void updated() {
    for(auto &[x, y] : curUp) {
        up[x % mod] ++;
    }

    for(auto &[x, y] : curDown) {
        ll k = (x % mod) * power(inv10, y) % mod;
        down[k] ++;
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    up.clear(); down.clear();
    down[0] = 1; up[0] = 1;

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        curUp.clear(); curDown.clear();
        add(i, centroid, j, j, 1);
        cal();
        updated();
    }


    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - a / b * y1;

    return g;
}

ll inverse(ll a, ll mod) {
    ll x, y;
    exgcd(a, mod, x, y);

    x %= mod;
    if(x < 0) x += mod;

    return x;
}

void solve() {
    inv10 = inverse(10, m);
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