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
ll n, m, ans = 0, xanh = 0, vang = 0, color[N + 1];
bool mark[N + 1];
vector<ll> edge[N + 1];
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
        char x; cin >> x;
        vang += (x == 'Y');
        xanh += (x == 'G');
        color[i] = (x == 'Y') + 2 * (x == 'G');
    }
    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dijkstra(ll u) {
    vector<ll> dis(n + 1, 1e18);
    vector<bool> vs(n + 1, false);
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({u, 0});
    dis[u] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;
        for(auto i : edge[t.dinh]) {
            if(dis[i] > t.kc + 1 + 3 * (color[i] != color[u])) {
                dis[i] = t.kc + 1 + 3 * (color[i] != color[u]);
                pq.push({i, dis[i]});
            }

        }
    }

    for(ll i = 1; i <= n; i ++) {
        if(!mark[i] && color[u] == color[i]) ans += dis[i];
    }
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        mark[i] = true;
        dijkstra(i);
    }

    double sum = (1 + (vang - 1)) * (vang - 1) / 2 + (1 + (xanh - 1)) * (xanh - 1) / 2;
    cout << fixed << setprecision(9) << (double)ans / sum;
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