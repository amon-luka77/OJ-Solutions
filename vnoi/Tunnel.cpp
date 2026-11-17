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
ll n, m, A, B, C, D, disA[N + 1], disC[N + 1], disB[N + 1];
struct kk {
    ll x, y, z;
};
struct NODE {
    ll dinh, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
map<pair<ll, ll>, ll> ts;
vector<ll> edge[N + 1];
vector<kk> a;
void read() {
    cin >> n >> m >> A >> B >> C >> D;
    for(ll i = 1; i <= m; i ++) {
        ll u, v, c;
        cin >> u >> v >> c;
        a.pb({u, v, c});
        edge[u].pb(v);
        edge[v].pb(u);
        ts[{u, v}] = c;
        ts[{v, u}] = c;
    }
    for(ll i = 1; i <= n; i ++) {
        disA[i] = 1e18;
        disB[i] = 1e18;
        disC[i] = 1e18;
    }
}

void dijkstra(ll u, ll dis[]) {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    dis[u] = 0;
    pq.push({u, 0});
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        if(x.kc > dis[x.dinh]) continue;

        for(auto i : edge[x.dinh]) {
            ll k = ts[{i, x.dinh}];
            if(dis[i] > x.kc + k) {
                dis[i] = x.kc + k;
                pq.push({i, dis[i]});
            }
        }
    }
}

void solve() {
    dijkstra(A, disA);
    dijkstra(B, disB);

    ll tg = disA[B];
    for(auto i : a) {
        if((tg == i.z + disA[i.x] + disB[i.y]) || (tg == i.z + disA[i.y] + disB[i.x])) {
            ts[{i.x, i.y}] = 0;
            ts[{i.y, i.x}] = 0;
        }
    }

    dijkstra(C, disC);

    cout << disC[D];
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