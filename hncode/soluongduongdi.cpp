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
const ll N = 2e5, mod = 1e9 + 7;
ll n, m, cnt[N + 1];
struct NODE {
    ll dinh, kc;
};
struct cmp {
    bool operator() (NODE x, NODE y) {
        return x.kc > y.kc;
    }
};
vector<pair<ll, ll>> edge[N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}
void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    vector<ll> dis(n + 1, 1e18);
    pq.push({1, 0});
    dis[1] = 0; cnt[1] = 1;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.kc > dis[t.dinh]) continue;

        for(auto i : edge[t.dinh]) {
            if(dis[i.ft] == t.kc + i.sc) {
                cnt[i.ft] = (cnt[i.ft] + cnt[t.dinh]) % mod;
            } else if(dis[i.ft] > t.kc + i.sc) {
                cnt[i.ft] = cnt[t.dinh] % mod;
                dis[i.ft] = t.kc + i.sc;
                pq.push({i.ft, dis[i.ft]});
            }
        }
    }

    cout << cnt[n];
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