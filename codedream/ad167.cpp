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
const ll N = 100;
ll n, m, ha, sa, hb, sb;
vector<pair<ll, ll>> edge[N + 1];
struct NODE {
    ll dinh, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> m >> ha >> sa >> hb >> sb;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

void dijkstra(ll u, vector<ll> &dis) {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({u, 0});
    dis[u] = 0;
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

    dijkstra(ha, dis1);
    dijkstra(hb, dis2);

    ll ans = 1e18;
    for(ll i = 1; i <= n; i ++) {
        vector<ll> dis(n + 1, 1e18);
        dijkstra(i, dis);
        if(dis[ha] + dis[sa] == dis1[sa] && dis[hb] + dis[sb] == dis1[sb] && dis[ha] == dis[hb]) {
            ans = min(ans, dis[ha]);
        }
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