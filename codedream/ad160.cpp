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
ll dis[N + 1];
bool vs[N + 1];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z;
        cin >> x >> y >> z;
        edge[x].pb({y, z});
    }
    for(ll i = 1; i <= n; i ++) {
        dis[i] = 1e18;
    }
}
void solve() {
    dis[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(vs[t.sc]) continue;
        vs[t.sc] = true;

        for(auto i : edge[t.sc]) {
            if(dis[i.ft] > t.ft + i.sc) {
                dis[i.ft] = t.ft + i.sc;
                pq.push({dis[i.ft], i.ft});
            }
        }
    }
}
void write() {
    for(ll i = 1; i <= n; i ++) {
        cout << dis[i] << ' ';
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}