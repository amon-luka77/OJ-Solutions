#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).last()
using namespace std;
const ll N = 100;
ll n, m, b[N + 1];
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
    for(ll i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            ll x; cin >> x;
            if(x != -1) {
                edge[i].pb({j, x});
            } 
        }
    }
}

void dijkstra(ll start, ll last) {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    vector<ll> dis(n + 1, 1e18);
    vector<ll> path(n + 1, 0);

    pq.push({start, 0});
    dis[start] = 0;

    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;
        if(t.dinh == last) break;

        for(auto i : edge[t.dinh]) {
            if(dis[i.ft] > t.kc + i.sc + b[i.ft]) {
                dis[i.ft] = t.kc + i.sc + b[i.ft];
                path[i.ft] = t.dinh;
                pq.push({i.ft, dis[i.ft]});
            }
        }
    }

    vector<ll> trace;
    ll ans = dis[last] - b[last];
    while(last > 0) {
        trace.pb(last);
        last = path[last];
    }

    for(ll i = trace.size() - 1; i >= 0; i --) {
        cout << trace[i] << ' ';
    }
    cout << el << ans << el;
}

void solve() {
    while(m--) {
        ll l, r; cin >> l >> r;
        dijkstra(l, r);
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