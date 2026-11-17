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
ll n, L, W, ans = 0, treeSize[N + 1], bit[N + 1];
bool vs[N + 1];
vector<pair<ll, ll>> edge[N + 1];
vector<pair<ll, ll>> c; 
vector<ll> roll;
vector<pair<ll, ll>> a;
vector<pair<ll, ll>> b;

void updated(ll i, ll val) {
    i ++;
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll get(ll i) {
    ll res = 0; i ++;
    for(; i >= 1; i -= i & -i) res += bit[i];
    return res;
}

void read() {
    cin >> n >> L >> W;
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

void add(ll u, ll par, ll height, ll dis, vector<pair<ll, ll>> &b) {
    if(height > L || dis > W) return;
    b.pb({height, dis});

    for(auto &[i, j] : edge[u]) if(i != par && !vs[i]) {
        add(i, u, height + 1, dis + j, b);
    }
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

void cal(vector<pair<ll, ll>> &b, ll keep, ll plus) {
    sort(all(b), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.sc < y.sc;
    });

    ll cnt = 0; c.clear(); roll.clear();

    c.pb({-1, 0});

    FOR(r, 0, b.size() - 1) {
        // cout << "{" << b[r].ft << ' ' << b[r].sc << "}, ";
        if(plus) cnt += (b[r].ft <= L && b[r].sc <= W);
        ll pos = binaryPos(0, r - 1, b, W - b[r].sc);
        if(pos != -1) c.pb({pos, L - b[r].ft});
    }

    sort(c.begin() + 1, c.end(), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.ft < y.ft;
    });

    FOR(i, 1, c.size() - 1) {
        FOR(j, c[i - 1].ft + 1, c[i].ft) {updated(b[j].ft, 1); roll.pb(b[j].ft);}
        cnt += get(c[i].sc);
    }

    for(auto i : roll) updated(i, -1);
    ans += cnt * keep;
    // cout << el << cnt << el;
}

void solveCentroid(ll u) {
    ll centroid = findCentroid(u, -1, getSize(u, -1));
    vs[centroid] = 1; a.clear();

    for(auto &[i, j] : edge[centroid]) if(!vs[i]) {
        b.clear();
        add(i, centroid, 1, j, b);
        cal(b, -1, 0);
        for(auto k : b) a.pb(k);
    }

    cal(a, 1, 1);

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