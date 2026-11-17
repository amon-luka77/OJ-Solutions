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
ll n, m, a[N + 1][N + 1];
vector<pair<ll, ll>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
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
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    vector<vector<ll>> dis(n + 1, vector<ll> (m + 1, 1e18));
    vector<vector<pair<ll, ll>>> path(n + 1, vector<pair<ll, ll>> (m + 1, {0 ,0 }));
    dis[1][1] = a[1][1];
    pq.push({1, 1, a[1][1]});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.fi][t.se]) continue;

        for(auto i : d) {
            ll new_x = t.fi + i.ft, new_y = t.se + i.sc;
            if(new_x < 1 || new_x > n || new_y < 1 || new_y > m) continue;
            if(dis[new_x][new_y] > t.kc + a[new_x][new_y]) {
                dis[new_x][new_y] = t.kc + a[new_x][new_y];
                path[new_x][new_y] = {t.fi, t.se};
                pq.push({new_x, new_y, dis[new_x][new_y]});
            }   
        }
    }

    cout << dis[n][m] << el;
    vector<pair<ll, ll>> trace;
    while(!(n == 0 && m == 0)) {
        trace.pb({n, m});
        auto i = path[n][m];
        n = i.ft, m = i.sc;
    }

    cout << trace.size() << el;

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