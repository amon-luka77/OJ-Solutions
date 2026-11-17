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
ll n, m;
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
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll u, v, t; cin >> u >> v >> t;
        edge[u].pb({v, t});
        edge[v].pb({u, t});
    }
}

void dijkstra(ll u, vector<ll> &dis, vector<ll> &cnt, vector<ll> &path, bool ok1, bool ok2) {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({u, 0});
    dis[u] = 0;
    if(ok1) cnt[u] = 1;
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();

        if(x.kc > dis[x.dinh]) continue;

        for(auto i : edge[x.dinh]) {
            if(dis[i.ft] > i.sc + x.kc) {
                dis[i.ft] = i.sc + x.kc;
                if(ok1) cnt[i.ft] = cnt[x.dinh];
                if(ok2) path[i.ft] = x.dinh;
                pq.push({i.ft, dis[i.ft]});
            } else if(ok1 && dis[i.ft] == i.sc + x.kc) {
                cnt[i.ft] += cnt[x.dinh];
            }
        }
    }

    return;
}

void solve() {
    vector<ll> dis1(n + 1, 1e18), disn(n + 1, 1e18), cnt(n + 1, 0), path(n + 1, 0);
    dijkstra(1, dis1, cnt, path, false, true);
    dijkstra(n, disn, cnt, path, true, false);

    ll ans = 0;
    ll k = n;
    vector<ll> trace;
    while(k > 0) {
        trace.pb(k);
        k = path[k];
    }

    for(ll i = 1; i < trace.size(); i ++) {
        if(cnt[trace[i]] == cnt[trace[i - 1]]) ans ++;
        if(cnt[trace[i]] > cnt[trace[i - 1]]) ans = 0;
    }

    cout << ans;
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