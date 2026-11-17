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
ll n, m;
vector<pair<ll, ll>> edge1[N + 1], edge2[N + 1];
struct NODE {
    ll dinh, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge1[x].pb({y, z});
        edge2[y].pb({x, z});
    }
}

void dijkstra(ll u, vector<ll> &dis, const vector<pair<ll, ll>> edge[]) {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    dis[u] = 0;
    pq.push({u, 0});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;

        for(auto i : edge[t.dinh]) {
            if(dis[i.ft] > i.sc + t.kc) {
                dis[i.ft] = i.sc + t.kc;
                pq.push({i.ft, dis[i.ft]});
            }
        }
    }
}

void solve() {
    vector<ll> dis1(n + 1, 1e18), dis2(n + 1, 1e18);
    dijkstra(1, dis1, edge1);
    dijkstra(1, dis2, edge2);
    for(ll i = 2; i <= n; i ++) {
        if(dis1[i] != 1e18 && dis2[i] != 1e18) {
            cout << dis1[i] + dis2[i] << el;
        } else {
            cout << -1 << el;
        }
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