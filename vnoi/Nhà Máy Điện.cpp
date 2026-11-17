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
const ll N = 5e5;
ll n, m, k, dis[N + 1], mark[N + 1];
vector<ll> edge[N + 1];
pair<ll, ll> a[N + 1];
void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i ++) {
        ll u, v; cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    for(ll i = 1; i <= k; i ++) {
        ll p, r; cin >> p >> r;
        a[i] = {p, r};
    }
}

void dijkstra(ll i) {
    dis[a[i].ft] = a[i].sc;
    mark[a[i].ft] = 1;
    queue<pair<ll, ll>> q;
    q.push({a[i].ft, a[i].sc});
    
    while(!q.empty()) {
        auto x = q.front();
        q.pop();

        if(x.sc == 0) continue;

        for(auto i : edge[x.ft]) {
            if(dis[i] < x.sc) {
                mark[i] = 1;
                dis[i] = x.sc - 1;
                q.push({i, dis[i]});
            }
        }
    }
}

void solve() {
    for(ll i = 1; i <= k; i ++) {
        dijkstra(i);
    }
}
void write() {
    for(ll i = 1; i <= n; i ++) {
        cout << mark[i];
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}