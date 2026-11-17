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
const ll N = 2e5;
ll n, m, k, dis[N + 1][101];
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
            dis[i][j] = 1e18;
        }
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({1, 0});
    dis[1][0] = 0;

    while(!pq.empty()) {
        auto [x, y, z] = pq.top();
        pq.pop();

        if(dis[x][z] > y) continue;

        for(auto [i, j] : edge[x]) {
            if(dis[i][z + 1] > y) {
                dis[i][z + 1] = y;
                pq.push({i, y, z + 1});

            }
            if(dis[i][z] > y + j) {
                dis[i][z] = y + j;
                pq.push({i, y + j, z});
            }
        }
    }
}
void write() {
    ll ans = 1e18;

    for(ll i = 0; i <= k; i ++) {
        ans = min(dis[n][i], ans);
    }

    if(ans == 1e18) cout << -1;
    else cout << ans;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}