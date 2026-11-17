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
const ll N = 1e6;
ll n, m, q, dis[N + 1];
vector<vector<ll>> a;
deque<pair<ll, ll>> edge[N + 1];
unordered_map<ll, bool> used;
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
struct NODE {
    ll fi, se, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> m >> q;
    a.assign(n + 1, vector<ll> (m + 1, 0));
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            edge[i * j].push_back({i, j});
            cin >> a[i][j];
        }
    }
}

ll tinh(ll x, ll y) {
    return (x - 1) * m + y;
}

ll dijkstra(ll sx, ll sy, ll tx, ll ty) {
    for(ll i = 1; i <= n * m; i++) dis[i] = 1e18;

    unordered_map<ll, bool> used;

    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({sx, sy, 0});
    dis[tinh(sx, sy)] = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();

        if(cur.kc > dis[tinh(cur.fi, cur.se)]) continue;
        if(cur.fi == tx && cur.se == ty) return cur.kc;

        // đi thường
        for(auto dir : d) {
            ll ni = cur.fi + dir.ft;
            ll nj = cur.se + dir.sc;
            if(ni < 1 || ni > n || nj < 1 || nj > m) continue;

            if(dis[tinh(ni, nj)] > cur.kc + 1) {
                dis[tinh(ni, nj)] = cur.kc + 1;
                pq.push({ni, nj, dis[tinh(ni, nj)]});
            }
        }

        // teleport
        ll val = a[cur.fi][cur.se];
        if(!used[val]) {
            used[val] = true;
            for(auto p : edge[val]) {
                if(dis[tinh(p.ft, p.sc)] > cur.kc + 3) {
                    dis[tinh(p.ft, p.sc)] = cur.kc + 3;
                    pq.push({p.ft, p.sc, dis[tinh(p.ft, p.sc)]});
                }
            }
        }
    }

    return -1;
}

void solve() {
    while(q --) {
        ll x, y, z, t;
        cin >> x >> y >> z >> t;
        cout << dijkstra(x, y, z, t) << el;
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
