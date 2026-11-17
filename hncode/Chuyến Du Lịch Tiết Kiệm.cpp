#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e5;
ll n, m, dis1[N + 1], disn[N + 1];
vector<pair<ll, ll>> edge[N + 1];
vector<pair<ll, ll>> a;

void read() {
    cin >> n >> m;

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
        a.pb({x, y});
    }

    for(ll i = 1; i <= n; i ++) {
        dis1[i] = 1e18;
        disn[i] = 1e18;
    }
}   

void dijstra(ll u, ll dis[]) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, u});
    dis[u] = 0;

    while(!pq.empty()) {
        auto [d, t] = pq.top();
        pq.pop();

        if(d > dis[t]) continue;

        for(auto [i, j] : edge[t]) {
            if(dis[i] > j + d) {
                dis[i] = j + d;
                pq.push({dis[i], i});
            }
        }
    }
}

void solve() {
    dijstra(1, dis1);
    dijstra(n, disn);

    ll ans = 1e18;

    for(auto [i, j] : a) {
        if(dis1[i] != 1e18 && disn[j] != 1e18) ans = min(ans, dis1[i] + disn[j]);
        if(dis1[j] != 1e18 && disn[i] != 1e18) ans = min(ans, dis1[j] + disn[i]);
    }

    if(ans == 1e18) cout << -1;
    else cout << ans;
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