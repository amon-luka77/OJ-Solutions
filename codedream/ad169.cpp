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
ll n, m, dis[N + 1][N + 1], a[N + 1][N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
pair<ll, ll> path[N + 1][N + 1];
struct NODE {
    ll fi, se, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
void read() {
    cin >> n >> m;
    for(ll i= 1 ; i <= n; i ++) {
        for(ll j = 1; j <= m;j ++) {
            dis[i][j] = 1e18;
            cin >> a[i][j];
        }
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    for(ll i = 1; i <= n; i ++) {
        pq.push({i, 1, a[i][1]});
        dis[i][1] = a[i][1];
    }

    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.fi][t.se] || t.se == m) continue;

        for(auto j : d) {
            ll new_i = t.fi + j.ft, new_j = t.se + j.sc;
            if(new_i < 1 || new_i > n || new_j < 1 || new_j > m) continue;
            if(dis[new_i][new_j] > a[new_i][new_j] + t.kc) {
                dis[new_i][new_j] = a[new_i][new_j] + t.kc;
                path[new_i][new_j] = {t.fi, t.se};
                pq.push({new_i, new_j, dis[new_i][new_j]});
            }
        }
    }

    ll ans = 1e18;
    pair<ll, ll> tc;
    vector<pair<ll, ll>> trace;
    for(ll i = 1; i <= n; i ++) {
        if(dis[i][m] != 1e18 && ans > dis[i][m]) {
            ans = dis[i][m];
            tc = {i, m};
        }
    }

    cout << ans << el;
    while(tc.ft > 0 && tc.sc > 0) {
        trace.pb(tc);
        tc = path[tc.ft][tc.sc];
    }

    for(ll i = trace.size() - 1; i >= 0; i --) {
        cout << trace[i].ft << ' ' << trace[i].sc << el;
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