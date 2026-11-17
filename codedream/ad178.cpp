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
ll n, m, k, d[N + 1][20];
vector<pair<ll, ll>> edge[N + 1];

struct NODE {
    ll x, y, z;
};

struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.y > y.y;
    }
};

void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 0; j <= k; j ++) {
            d[i][j] = 1e18;
        }
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({1, 0, 0});
    d[1][0] = 0;
    while(!pq.empty()) {
        auto [u, dis, role] = pq.top();
        pq.pop();

        if(dis > d[u][role]) continue;

        for(auto [i, j] : edge[u]) {
            if(role < k && d[i][role + 1] > dis) {
                d[i][role + 1] = dis;
                pq.push({i, dis, role + 1});
            }

            if(d[i][role] > dis + j) {
                d[i][role] = dis + j;
                pq.push({i, d[i][role], role});
            }
        }
    }

    for(ll i = 1; i <= n; i ++) {
        ll ans = 1e18;
        for(ll j = 0; j <= k; j ++) {
            ans = min(ans, d[i][j]);
        }
        cout << ans << ' ';
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