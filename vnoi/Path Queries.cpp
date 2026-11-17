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
ll n, q, high[N + 1], par[N + 1], treeSize[N + 1];
ll head[N + 1], pos[N + 1], a[N + 1], heavy[N + 1], curPos = 0;
ll bit[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll getSum(ll l, ll r) {
    ll ans = 0; l --;
    for(; l >= 1; l -= l & -l) ans -= bit[l];
    for(; r >= 1; r -= r & -r) ans += bit[r];
    return ans;
}

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    par[u] = parent;
    ll maxSize = 0;

    for(auto i : edge[u]) if(i != parent) {
        dfs(i, u);
        high[i] = high[u] + 1;
        treeSize[u] += treeSize[i];
        if(treeSize[i] > maxSize) {
            maxSize = treeSize[i];
            heavy[u] = i; 
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++curPos;

    if(heavy[u]) hld(heavy[u], h);
    for(auto i : edge[u]) if(i != par[u] && i != heavy[u]) {
        hld(i, i);
    } 
}

void hldPath(ll u, ll v) {
    ll ans = 0;
    while(head[u] != head[v]) {
        if(high[head[u]] < high[head[v]]) swap(u, v);
        ans += getSum(pos[head[u]], pos[u]);
        u = par[head[u]];
    }

    if(high[u] > high[v]) swap(u, v);
    ans += getSum(pos[u], pos[v]);

    cout << ans << el;
}

void solve() {
    dfs(1, -1);
    hld(1, 1);

    FOR(i, 1, n) updated(pos[i], a[i]);

    FOR(i, 1, q) {
        ll x, l, r; cin >> x >> l;
        if(x == 1) {
            cin >> r;
            updated(pos[l], r - a[l]);
            a[l] = r;
        } else {
            hldPath(1, l);
        }
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