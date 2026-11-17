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
#define file(name) freopen(name".inpk", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 2e5;
ll n, a[N + 1], treeSize[N + 1], head[N + 1], par[N + 1], heavy[N + 1], ans[N + 1];
bool vs[N + 1];
vector<ll> edge[N + 1], b;
vector<tuple<ll, ll, ll>> query; 
ll pos[N + 1], val[N + 1], last[N + 1], bit[N + 1], curPos = 0;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(all(b)); b.erase(unique(all(b)), b.end());
    FOR(i, 1, n) {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }
    
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    } 
}

void dfs(ll u, ll parent) {
    treeSize[u] = 1;
    par[u] = parent;
    ll maxSize = 0;
    for(auto i : edge[u]) if(i != parent) {
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
    pos[u] = ++curPos;
    val[curPos] = a[u];

    if(heavy[u]) hld(heavy[u], h);

    for(auto i : edge[u]) if(i != par[u] && i!= heavy[u]) {
        hld(i, i);
    }
}

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll getSum(ll l, ll r) {
    ll sum = 0;
    for(; l >= 1; l -= l & -l) sum -= bit[l];
    for(; r >= 1; r -= r & -r) sum += bit[r];
    return sum;
}

void solve() {
    dfs(1, -1);
    hld(1, 1);

    FOR(i, 1, n) {
        query.pb({pos[i] + treeSize[i] - 1, pos[i], i});
    }

    sort(all(query));
    ll cur = 1;

    FOR(i, 0, query.size() - 1) {
        auto [r, l, u] = query[i];
        FOR(j, cur, r) {
            if(last[val[j]] != 0) updated(last[val[j]], -1);

            updated(j, 1);
            last[val[j]] = j;
        }

        ans[u] += getSum(l - 1, r);
        cur = r + 1;

    }
}

void write() {
    FOR(i, 1, n) cout << ans[i] << " ";
}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}