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
ll n, m, k, dis[N + 1];
vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> m >> k;

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }

    for(ll i = 1; i <= n; i ++) {
        dis[i] = 1e18;
    }
}

void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dis[u]) continue;

        for(auto [i, j] : edge[u]) {
            if(dis[i] > j + d) {
                dis[i] = j + d;
                pq.push({dis[i], i});
            }
        }
    }

    ll cnt = 0;

    for(ll i = 1; i <= k; i ++) {
        ll x, y; cin >> x >> y;
        if(dis[x] <= y) cnt ++;
    }

    cout << cnt;
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