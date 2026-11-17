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
ll n, m, s, t;
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
    cin >> n >> m >> s >> t;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}
void solve() {
    vector<ll> dis(n + 1, 1e18), path(n + 1, 0);
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({s, 0});
    dis[s] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;

        for(auto i : edge[t.dinh]) {
            if(dis[i.ft] > i.sc + t.kc) {
                dis[i.ft] = i.sc + t.kc;
                path[i.ft] = t.dinh;
                pq.push({i.ft, dis[i.ft]});
            }
        }
    }

    cout << dis[t] << el;
    vector<ll> trace;
    while(t > 0) {
        trace.pb(t);
        t = path[t];
    }
    for(ll i = trace.size() - 1; i >= 0; i --) {
        cout << trace[i] << ' ';
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