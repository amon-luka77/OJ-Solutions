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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 1e5;
ll n, m, ans = 0, amon = 0, cnt = 0, cntBridge = 0, low[N + 1], num[N + 1];
ll comp[N + 1], Bridge[N + 1], vs[N + 1];
vector<pair<ll, ll>> edge[N + 1];
pair<ll, ll> canh[N + 1];
vector<ll> newEdge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        canh[i] = {x, y};
        edge[x].pb({y, i});
        edge[y].pb({x, i});
    }
}

void dfsBridge(ll u, ll id) {
    num[u] = low[u] = ++cnt;

    for(auto &[i, j] : edge[u]) if(id != j) {
        if(num[i]) low[u] = min(low[u], num[i]);
        else {
            dfsBridge(i, j);
            low[u] = min(low[u], low[i]);
            if(low[i] > num[u]) {Bridge[j] = 1; amon ++;}
        }
    }
} 

void dfs(ll u) {
    comp[u] = cntBridge;

    for(auto &[i, j] : edge[u]) if(!Bridge[j] && !comp[i]) {
        dfs(i);
    }
}

ll getAns(ll u, ll par) {
    ll mx1 = 0, mx2 = 0;
    vs[u] =  1;

    for(auto i : newEdge[u]) if(i != par && !vs[i]) {
        ll d = getAns(i, u) + 1;
        if(d > mx1) {
            mx2 = mx1;
            mx1 = d;
        } else {
            mx2 = max(mx2, d);
        }
    }

    ans = max(ans, mx1 + mx2);
    return mx1;
}

void solve() {
    FOR(i, 1, n) if(!num[i]) dfsBridge(i, 0);
    FOR(i, 1, n) if(!comp[i]) {
        cntBridge ++;
        dfs(i);
    }

    // cout << amon << el;

    // FOR(i, 1, m) if(!Bridge[i]) cout << i << el;
    // FOR(i, 1, n) cout << i << ' ' << comp[i] << el;

    FOR(i, 1, m) if(Bridge[i]) {
        if(comp[canh[i].ft] != comp[canh[i].sc]) {
            newEdge[comp[canh[i].ft]].pb(comp[canh[i].sc]);
            newEdge[comp[canh[i].sc]].pb(comp[canh[i].ft]);
        }
    }

    FOR(i, 1, n) if(!vs[i]) getAns(i, 0);

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