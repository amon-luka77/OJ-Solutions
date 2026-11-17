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

const ll N = 1e5, mod = 1e9 + 7;
ll n, m, a[N + 1], deg[N + 1], dp[N + 1], cnt[N + 1];
vector<ll> edge[N + 1], rev[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        rev[y].pb(x);
        deg[y] ++;
    }
}

void solve() {
    queue<ll> q; vector<ll> topo; topo.pb(77);
    FOR(i, 1, n) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        ll v = q.front(); q.pop();
        topo.pb(v);
        for(auto i : edge[v]) {
            deg[i] --;
            if(deg[i] == 0) q.push(i);
        } 
    }

    if(topo.size() - 1 != n) cout << -1;
    else {
        ll res = 0;
        FOR(i, 1, n) {
            ll u = topo[i];
            dp[u] = a[u];
            cnt[u] = 1;
            for(auto j : rev[u]) {
                dp[u] = (dp[u] + dp[j] + a[u] * cnt[j] % mod) % mod;
                cnt[u] = (cnt[u] + cnt[j]) % mod;
            }
            res = (res + dp[u]) % mod;
        }
        cout << res << el;
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