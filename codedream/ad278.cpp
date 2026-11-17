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

const ll N = 2e5;
ll n, m, cnt = 0, low[N + 1], num[N + 1];
vector<ll> edge[N + 1];
vector<pair<ll, ll>> ans;
bool bridge = 0;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    num[u] = low[u] = ++cnt;

    for(auto i : edge[u]) if(i != par) {
        if(num[i]) {
            low[u] = min(low[u], num[i]);
            if(num[i] < num[u]) ans.pb({u, i});
        } else {
            dfs(i, u);
            low[u] = min(low[u], low[i]);
            ans.pb({u, i});
            if(low[i] > num[u]) bridge = 1; 
        }
    }
}

bool check() {
    FOR(i, 1, n) if(!num[i]) return 0;
    return 1;
}

void solve() {
    dfs(1, 0);

    if(bridge || !check()) cout << "IMPOSSIBLE";
    else {
        for(auto &[i, j] : ans) cout << i << ' ' << j << el;
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