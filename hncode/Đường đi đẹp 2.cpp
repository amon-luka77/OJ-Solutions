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
vector<pair<ll, ll>> edge[N + 1];
struct NODE {
    ll dinh, kc, min_n, max_n;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll u, v, c;
        cin >> u >> v >> c;
        edge[u].pb({v, c});
        edge[v].pb({u, c});
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    vector<ll> dis(n + 1, 1e18), dep(n + 1, -1e18);
    pq.push({1, 0, (ll)1e18, (ll)-1e18});
    dis[1] = 0;
    dep[1] = 0;
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        if(x.kc > dis[x.dinh]) continue;

        for(auto i : edge[x.dinh]) {
            ll max_i = max(x.max_n, i.sc);
            ll min_i = min(x.min_n, i.sc);
            if(dis[i.ft] > 1 + x.kc) {
                dis[i.ft] = 1 + x.kc;
                dep[i.ft] = max_i - min_i;
                pq.push({i.ft, dis[i.ft], min_i, max_i});
            } else if(dis[i.ft] == 1 + x.kc && dep[i.ft] < max_i - min_i) {
                dep[i.ft] = max_i - min_i;
                pq.push({i.ft, dis[i.ft], min_i, max_i});
            }
        }
    }

    cout << dep[n];
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