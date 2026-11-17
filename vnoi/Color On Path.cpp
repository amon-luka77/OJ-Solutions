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
ll n, q, a[N + 1], heavy[N + 1], pos[N + 1], cnt = 0, head[N + 1], bit[N + 1];
ll treeSize[N + 1], high[N + 1], parTree[N + 1], ans[N + 1];

vector<ll> edge[N + 1], color[N + 1];

struct QUERY {
    ll x, y, z, t;
};

vector<QUERY> query;

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        color[a[i]].pb(i);
    }

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y >> z;
        query.pb({z, x, y, i});
    }

    sort(all(query), [](const QUERY &x, const QUERY &y) {
        return x.x < y.x;
    });
}

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll getSum(ll l, ll r) {
    ll sum = 0; l --;
    for(; l >= 1; l -= l & -l) sum -= bit[l];
    for(; r >= 1; r -= r & -r) sum += bit[r];
    return sum;
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    parTree[u] = par;
    ll maxSize = 0;

    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(maxSize < treeSize[i]) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++cnt;

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != parTree[u] && i != heavy[u]) {
        hld(i, i);
    }
}

bool getQuery(ll u, ll v, ll c) {
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        if(getSum(pos[head[u]], pos[u]) > 0) return 1;
        u = parTree[head[u]];
    }

    if(high[u] > high[v]) swap(u, v);
    if(getSum(pos[u], pos[v]) > 0) return 1;
    return 0;
}

void solve() {
    dfs(1, -1);
    hld(1, 1);

    FOR(i, 0, q - 1) {
        auto [c, u, v, idx] = query[i];
        if(i == 0) {
            for(auto j : color[c]) updated(pos[j], 1);
        } else if(c != query[i - 1].x) {
            for(auto j : color[query[i - 1].x]) updated(pos[j], -1);
            for(auto j : color[c]) updated(pos[j], 1);
        }

        ans[idx] = getQuery(u, v, c);
    }

    FOR(i, 1, q) cout << ans[i];
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