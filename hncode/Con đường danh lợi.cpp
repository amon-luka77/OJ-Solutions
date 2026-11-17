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
ll n, m, k;
struct kk {
    ll x, y, z;
};
struct NODE {
    ll dinh, kc, val;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
vector<kk> edge[N + 1];
void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i ++) {
        ll u, v, l, t;
        cin >> u >> v >> l >> t;
        edge[u].pb({v, l, t});
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp>  pq;
    vector<ll> dis(n + 1, 1e18);
    dis[1] = 0;
    pq.push({1, 0, 0});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;

        for(auto i : edge[t.dinh]) {
            if(dis[i.x] > t.kc + i.y && k >= t.val + i.z) {
                dis[i.x] = t.kc + i.y;
                ll mn = t.val + i.z;
                pq.push({i.x, dis[i.x], mn});
            }
        }
    }

    if(dis[n] == 1e18) cout << -1;
    else cout << dis[n];
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