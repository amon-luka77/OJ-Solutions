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
struct kk {
    ll x, y, z;
};
struct NODE {
    ll dinh, kc, bt;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
vector<kk> edge[N + 5];

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll u, v, l, i1;
        cin >> u >> v >> l >> i1;
        edge[u].pb({v, l, i1});
        edge[v].pb({u, l, i1});
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    vector<ll> dis(N + 5, 1e18), dep(N + 5, 0);
    dis[1] = 0;
    dep[1] = 0;
    pq.push({1, 0, 0});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;

        for(auto i : edge[t.dinh]) {
            if(dis[i.x] >= i.y + t.kc) {
                if(dis[i.x] > i.y + t.kc) dep[i.x] = t.bt + i.z;
                else dep[i.x] = max(dep[i.x], t.bt + i.z);
                if(dis[i.x] > i.y + t.kc) pq.push({i.x, i.y + t.kc, dep[i.x]});
                dis[i.x] = i.y + t.kc;
            }
        }
    }

    if(dis[n] == 1e18) cout << -1;
    else cout << dis[n] << ' ' << dep[n];
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
