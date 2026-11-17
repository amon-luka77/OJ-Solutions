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
ll n, m, a[N + 1], dis[N + 1], ans[N + 1];

struct NODE {
    ll dinh, kc, min_n, max_n;
};

struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};

struct goc {
    ll u, w, c;
};

vector<goc> edge[N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll u, v, w, c;
        cin >> u >> v >> w >> c;
        edge[u].pb({v, w, c});
        edge[v].pb({u, w, c});
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({1, 0, (ll)1e18, (ll)-1e18});

    for(ll i = 1; i <= n; i ++) {
        dis[i] = 1e18;
    }

    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        if(x.kc > dis[x.dinh]) continue;

        for(auto i : edge[x.dinh]) {
            ll min_i = min(i.c, x.min_n), max_i = max(i.c, x.max_n);
            if(dis[i.u] > i.w + x.kc) {
                dis[i.u] = i.w + x.kc;
                ans[i.u] = max_i - min_i;
                pq.push({i.u, dis[i.u], min_i, max_i});
            } else if(dis[i.u] == i.w + x.kc && ans[i.u] < max_i - min_i) {
                ans[i.u] = max_i - min_i;
                pq.push({i.u, dis[i.u], min_i, max_i});
            }
        }
    }
}
void write() {
    cout << ans[n];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}
