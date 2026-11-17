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

const ll N = 2e5;
ll n, q, heavy[N + 1], pos[N + 1], par[N + 1], a[N + 1];
ll treeSize[N + 1], head[N + 1], high[N + 1], cnt = 0;
vector<ll> edge[N + 1];
const int SZ = 1 << 18;
int st[SZ << 1];
void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void updated(int p,int val){
    p += SZ;
    st[p]=val;
    for(p>>=1;p;p>>=1)
        st[p]=max(st[p<<1],st[p<<1|1]);
}

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    ll maxSize = 0;
    par[u] = parent;

    for(auto i : edge[u]) if(i != parent) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
        if(treeSize[i] > maxSize) {
            maxSize = treeSize[i];
            heavy[u] = i;
        }
    }
}

void hld(ll u, ll h) {
    head[u] = h;
    pos[u] = ++cnt;
    updated( pos[u], a[u]);

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != par[u] && i != heavy[u]) {
        hld(i, i);
    }
}

void updatedQuery(ll u, ll val) {
    updated(pos[u], val);
}

int query(int l,int r){
    int res=-1e9;
    for(l+=SZ,r+=SZ;l<=r;l>>=1,r>>=1){
        if(l&1) res=max(res,st[l++]);
        if(!(r&1)) res=max(res,st[r--]);
    }
    return res;
}

int queryPath(int u, int v){
    int ans = -1e9;
    while(head[u] != head[v]){
        if(high[head[u]] < high[head[v]]) swap(u,v);
        ans = max(ans, query(pos[head[u]], pos[u]));
        u = par[head[u]];
    }
    if(high[u] > high[v]) swap(u,v);
    ans = max(ans, query(pos[u], pos[v]));
    return ans;
}

void solve() {
    dfs(1, -1);
    hld(1, 1);

    FOR(i, 1, q) {
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1) {
            updatedQuery(l, r);
        } else {
            cout << queryPath(l, r) << ' ';
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