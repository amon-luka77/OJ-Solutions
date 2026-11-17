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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, L, W, ans = 0;
vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> L >> W;
    FOR(i, 2, n) {
        ll x, y; cin >> x >> y;
        edge[x].pb({i, y}); edge[i].pb({x, y});
    }
}

/*-------------------------------start Bit---------------------*/
ll bit[N + 1];

void updated(ll i, ll val) {for(i ++; i <= n; i += i & -i) bit[i] += val;}

ll getPairs(ll i) {
    ll res = 0; for(i ++; i > 0; i -= i & -i) res += bit[i]; return res;
}

/*-------------------------------start Centroid-------------------------*/
ll treeSize[N + 1]; bool vs[N + 1];
vector<pair<ll, ll>> a, b, c; vector<ll> rollback;

ll getSize(ll u, ll par) {
    treeSize[u] = 1;
    for(auto &[i, j] : edge[u]) if(i != par && ! vs[i]) treeSize[u] += getSize(i, u);
    return treeSize[u];
}

ll findCentroid(ll u, ll par, ll curSize) {
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        if(treeSize[i] > (curSize >> 1)) return findCentroid(i, u, curSize);
    } return u;
}

void add(ll u, ll par, ll dis, ll high, vector<pair<ll, ll>> &b) {
    b.pb({high, dis});
    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) add(i, u, dis + j, high + 1, b);
}

ll binaryPos(ll Left, ll Right, const vector<pair<ll, ll>> &b, ll tg) {
    ll l = Left, r = Right, ansPos = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid].sc <= tg) {
            ansPos = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ansPos;
}

void cal(vector<pair<ll, ll>> &b, ll keep) {
    sort(all(b), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.sc < y.sc;
    });

    ll l = b.size() - 1; c.clear();
    FOR(r, 0, b.size() - 1) {
        ll pos = binaryPos(0, r - 1, b, W - b[r].sc);
        if(pos != -1) c.pb({pos, L - b[r].ft});
    }

    sort(all(c), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.ft < y.ft;
    });

    ll Left = 0, res = 0; rollback.clear();
    for(auto &[pos, target] : c) {
        while(Left <= pos) {rollback.pb(b[Left].ft), updated(b[Left].ft, 1); Left ++;}
        res += getPairs(target);
    }   

    for(auto i : rollback) updated(i, -1);

    ans += res * keep;

    // if(keep) {
    //     cerr << res << el;
    //     for(auto &[i, j] : b) cerr << "[" << i << ", " << j << "], ";
    //     cerr << el;
    // }
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, 0, getSize(u, 0));
    vs[centroid] = 1; a.clear(); a.pb({0, 0});

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        b.clear(); add(i, centroid, j, 1, b); cal(b, -1);
        for(auto k : b) a.pb(k);
    }

    cal(a, 1);

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) solveCentroid(i);
}

/*-------------------------------end Centroid------------------------------*/

void solve() {
    solveCentroid(1);
    cout << ans;
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}