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
const ll N = 1000;
ll n, m, s, t, a[N + 1];
vector<pair<ll, ll>> edge[N + 1];
struct pll {
    ll dinh, kc;
};
struct cmp {

    bool operator() (pll x, pll y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> m >> s >> t;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z;
        cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}
void solve() {
    vector<ll> dis(n + 1, 1e18);
    priority_queue<pll, vector<pll>, cmp> pq;

    dis[s] = 0;
    pq.push({s, 0});
    while(!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        if(cur.kc > dis[cur.dinh]) continue;

        for(auto i : edge[cur.dinh]) {
            if(dis[i.ft] > i.sc + cur.kc && (a[i.ft] == 0 || a[i.ft] != 0 && cur.kc + i.sc < a[i.ft])) {
                dis[i.ft] = i.sc + cur.kc;
                pq.push({i.ft, dis[i.ft]});
            }
        }
    }
    
    if(dis[t] == 1e18) cout << -1;
    else cout << dis[t];
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