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

const ll N = 250;
ll n, m, s t;

void read() {
    cin >> n >> m >> s >> t;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
    }
}

void bfs(ll u) {
    queue<pair<ll, ll>> q;
    q.push({u, 0});
    dis[u][0] = 0;

    while(!q.empty()) {
        auto [v, y] = q.front();
        q.pop();

        for(auto i : edge[i]) {
            ll d = d[v] + 1;
            if(dis[i][1 - y] > d) {
                dis[i][1 - y] = d;
                q.push({i, 1- y});
            }
        }
    }
}

void solve() {
    FOR(i, 1, n) FOR(j, 0, 1) dis[i][j] = 1e18;
    bfs(s); bfs(t);

    ll ans = 1e18;
    FOR(i, 1, n) FOR(j, 0, 1) {
        ans = min(ans, dis[i][j]);
    }

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