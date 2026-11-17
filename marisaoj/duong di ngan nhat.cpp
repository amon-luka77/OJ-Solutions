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
ll n, k, ans = 0, treeSize[N + 1], vs[N + 1];

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n - 1) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
    // cout << 7; exit(0);
}

ll getSize(ll u, ll par) {
    treeSize[u] = 1;

    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        treeSize[u] += getSize(i, u);
    }

    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto &[i, j] : edge[u]) if(i != par & !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    }
    return u;
}

void add(ll u, ll par, ll height, vector<ll> &path) {
    path.pb(height);

    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        add(i, u, height + j, path);
    }
}

void cal(vector<ll> &a, ll keep) {
    sort(all(a));
    ll sum = 0;
    ll l = 0, r = a.size() - 1;
    while(l < r) {
        if(a[r] + a[l] <= k) {
            ans += (r - l) * keep;
            l ++;
        } else {
            r --;
        }
    }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    vector<ll> a; a.pb(0);

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        vector<ll> path;
        add(i, centroid, j, path);
        cal(path, -1);

        for(auto dis : path) {
            a.pb(dis);
        }
    }
    
    cal(a, 1);

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