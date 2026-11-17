/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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

const ll N = 3e5, LOG = 18;
ll n, k, high[N + 1], par[N + 1][LOG + 1], parCentroid[N + 1], treeSize[N + 1];
ll minDis[N + 1], a[N + 1], c[N + 1];
vector<ll> edge[N + 1];
pair<ll, ll> b[N + 1];
vector<ll> A[N + 1], subA[N + 1];
bool vs[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y); edge[y].pb(x);
    }
    FOR(i, 1, k) cin >> a[i];
    FOR(i, 1, n) {
        cin >> b[i].ft >> b[i].sc;
    }
}

void multiBfs() {
    queue<ll> q;
    fill(minDis + 1, minDis + n + 1, -1);
    FOR(i, 1, k) {
        q.push(a[i]);
        minDis[a[i]] = 0;
    }

    while(!q.empty()) {
        ll u = q.front();
        q.pop();

        for(auto i : edge[u]) if(minDis[i] == -1) {
            minDis[i] = minDis[u] + 1;
            q.push(i);
        }
    }
}

void dfsLca(ll u, ll parent) {
    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        par[i][0] = u;
        FOR(j, 1, LOG) par[i][j] = par[par[i][j - 1]][j - 1];
        dfsLca(i, u);
    }
}

ll lca(ll u, ll v) {
    if(high[u] < high[v]) swap(u, v);
    FORD(i, LOG, 0) if(high[par[u][i]] >= high[v]) u = par[u][i];
    if(u == v) return u;
    FORD(i, LOG, 0) if(par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
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

void solveCentroid(ll u, ll preCentroid) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1; parCentroid[centroid] = preCentroid;

    for(auto i : edge[centroid]) if(!vs[i]) {
        solveCentroid(i, centroid);
    }
}

ll getDis(ll u, ll v) {
    return high[u] + high[v] - 2 * high[lca(u, v)];
}

void updated(ll v) {
    ll u = v;
    ll pre = 0;
    while(u > 0) {
        ll t = c[v] - getDis(u, v);
        A[u].pb(t);
        if(pre > 0) subA[pre].pb(t);
        pre = u;
        u = parCentroid[u];
    }
} 

void solve() {
    multiBfs();
    dfsLca(1, -1);
    FOR(i, 1, n) {
        c[i] = min(getDis(b[i].ft, i) - b[i].sc - 1, minDis[i]);
    }
    solveCentroid(1, -1);

    FOR(i, 1, n) updated(i);
    FOR(i, 1, n) {
        sort(all(A[i]));
        sort(all(subA[i]));
    }

    FOR(i, 1, n) {
        ll x = i, pre = 0;
        ll ans = 0;
        while(x > 0) {
            ll k = getDis(i, x);
            ans += A[x].end() - lower_bound(all(A[x]), k);
            if(pre > 0) ans -= subA[pre].end() - lower_bound(all(subA[pre]), k);
            pre = x;
            x = parCentroid[x];
        }
        cout << ans << ' ';
    }
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