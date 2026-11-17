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

const ll N = 1e5, mode = 998244353;
ll n, treeSize[N + 1], ans[N + 1];
vector<pair<ll, ll>> edge[N + 1];

bool vs[N + 1];
vector<tuple<ll, ll, ll>> a;

struct PF {
    ll sum_y;
    ll sum_x;
    ll sum_yy;
    ll sum_xy;
    ll sum_xyy;
};

PF prefix[N + 1];

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

void add(ll u, ll par, ll height, ll dis) {
    a.pb({dis, height, u});
    ans[u] = (ans[u] + (dis * (height * height) % mode) % mode) % mode;
    ans[0] = (ans[0] + (dis * (height * height) % mode) % mode) % mode;
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        add(i, u, height + 1, min(dis, j));
    }
}

void cal(vector<tuple<ll, ll, ll>> &node, ll keep) {
    ll m = node.size() - 1; sort(node.begin() + 1, node.end());
    prefix[0] = {0, 0, 0, 0, 0}; prefix[m + 1] = {0, 0, 0, 0, 0};

    FOR(i, 1, m) {
        auto [x, y, z] = node[i];
        prefix[i].sum_x = (prefix[i - 1].sum_x + x) % mode;
        prefix[i].sum_y = (prefix[i - 1].sum_y + y) % mode;
        prefix[i].sum_xy = (prefix[i - 1].sum_xy + (x * y) % mode) % mode;
        prefix[i].sum_yy = (prefix[i - 1].sum_yy + (y * y) % mode) % mode;
        prefix[i].sum_xyy = (prefix[i - 1].sum_xyy + ((x * y) % mode * y) % mode) % mode;
    }

    FOR(i, 1, m) {
        auto [x, y, z] = node[i];
        ll sum = 0;
        ll temp1 = prefix[i - 1].sum_xyy;
        ll temp2 = ((2 * y) % mode * prefix[i - 1].sum_xy) % mode;
        ll temp3 = ((y * y) % mode * prefix[i - 1].sum_x) % mode;
        sum = (((sum + temp1) % mode + temp2) % mode + temp3) % mode;
        
        temp1 = (x * ((prefix[m].sum_yy - prefix[i].sum_yy) % mode + mode) % mode) % mode;
        temp2 = (((m - i) * x) % mode * (y * y) % mode) % mode;
        temp3 = (((2 * y % mode) * x) % mode * ((prefix[m].sum_y - prefix[i].sum_y) % mode + mode) % mode) % mode;
        sum = (((sum + temp1) % mode + temp2) % mode + temp3) % mode;

        ans[z] = (ans[z] + (sum % mode * keep) % mode + mode) % mode;
    }

}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1;
    ans[0] = 0;
    vector<tuple<ll, ll, ll>> root; root.pb({0, 0, 0});

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        a.clear(); a.pb({0, 0, 0});
        add(i, centroid, 1, j);
        cal(a, -1);

        FOR(i, 1, a.size() - 1) root.pb(a[i]);
    }

    cal(root, 1);
    ans[centroid] = (ans[centroid] + ans[0]) % mode;

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        solveCentroid(i);
    }
}

void solve() {
    solveCentroid(1);
    FOR(i, 1, n) cout << ans[i] << el;
}

void write() {

}

int main() {
    boost;
    file("netw");
    read();
    solve();
    write();
    return 0;
}