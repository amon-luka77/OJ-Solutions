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

const ll N = 1e2;
ll n, m, d[N + 1][N + 1];
vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

void dijkstra(ll u) {
    d[u][u] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, u});

    while(!pq.empty()) {
        auto [dis, x] = pq.top();
        pq.pop();

        if(dis > d[u][x]) continue;

        for(auto &[i, j] : edge[x]) {
            if(d[u][i] > dis + j) {
                d[u][i] = dis + j;
                pq.push({d[u][i], i});
            }
        }
    }
}

void solve() {
    ll ans = 1e18;

    FOR(i, 1, n) FOR(j, 1, n) {
        d[i][j] = 1e18;
    }

    FOR(i, 1, n) {
        dijkstra(i);
    }

    FOR(i, 1, n) FOR(j, i + 1, n) {
        ll cur = 0;

        FOR(newI, 1, n) FOR(newJ, newI + 1, n) {
            cur += min({d[newI][newJ], 
                        d[newI][i] + d[newJ][j], 
                        d[newI][j] + d[newJ][i]});
        }

        ans = min(ans, cur);
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