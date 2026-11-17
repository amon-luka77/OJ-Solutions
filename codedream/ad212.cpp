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
ll n, m, k, cnt = 0, parent[N + 1], sz[N + 1], ans[N + 1];
map<pair<ll, ll>, ll> edge;

struct HS {
    ll x, y, z, t;
};

stack<HS> history;

vector<pair<ll, ll>> node[4 * N + 1];


void updated(ll id, ll l, ll r, ll i, ll j, pair<ll, ll> val) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {
        node[id].pb(val);
        return;
    }

    ll mid = (l + r) >> 1;
    updated(id * 2, l, mid, i, j, val);
    updated(id * 2 + 1, mid + 1, r, i, j, val);
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        history.push({x, sz[x], y, cnt});
        parent[y] = x;
        sz[x] += sz[y];
        cnt --;
    }
}

void rollback() {
    while(history.top().x != -1) {
        auto [u, sizeRoot, v, preCnt] = history.top();
        history.pop();
        sz[u] = sizeRoot;
        parent[v] = v;
        cnt ++;
    }

    history.pop();
}

void solveSegmentTree(ll id, ll l, ll r) {
    //  cout << cnt << el;
    history.push({-1, 0, 0, 0});

    for(auto &[x, y] : node[id]) {
        union_set(x, y);
    }

    if(l == r) {
        ans[l] = cnt;
    } else {
        ll mid = (l + r) >> 1;

        solveSegmentTree(id * 2, l, mid);
        solveSegmentTree(id * 2 + 1, mid + 1, r);        
    }

    rollback();
}

void read() {
    cin >> n >> m >> k; cnt = n;

    FOR(i, 1, n) {
        parent[i] = i;  sz[i] = 1;
    }
    history.push({-1, 0, 0, 0});

    FOR(i, 1, m) {
        ll x, y; cin >> x >> y; if(x > y) swap(x, y); 
        union_set(x, y);
        edge[{x, y}] = 1;
    }    

    cout << cnt << ' ';
    rollback();

}

void solve() {
    FOR(i, 1, k) {
        ll x, l, r; cin >> x >> l >> r; if(l > r) swap(l, r);
        if(x == 1) edge[{l, r}] = i;
        else {
            updated(1, 1, k, edge[{l, r}], i - 1, make_pair(l, r));
            edge.erase({l, r});
        }
    }

    for(auto t : edge) {
        updated(1, 1, k, t.sc, k, t.ft);
    }

    solveSegmentTree(1, 1, k);

    FOR(i, 1, k) cout << ans[i] << ' ';

    // cout << el;
    // FOR(i, 1, 4 * n) {
    //     cout << i << el;
    //     for(auto j : node[i]) {
    //         cout << "{" << j.ft << ", " << j.sc << "} ";
    //     }
    //     cout << el;
    // }
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