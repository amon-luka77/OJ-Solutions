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
ll n, m, d[N + 1], cnt[N + 1];
vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> m;
    
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }

    for(ll i = 1; i <= n; i ++) {
        d[i] = 1e18;
    }
}
void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    d[1] = 0;
    cnt[1] = 1;

    while(!pq.empty()) {
        auto [dis, u] = pq.top();
        pq.pop();

        if(dis > d[u]) continue;

        for(auto [i, j] : edge[u]) {
            if(d[i] > dis + j) {
                d[i] = dis + j;
                cnt[i] = cnt[u] % mod;
                pq.push({d[i], i});
            } else if(d[i] == dis + j) {
                cnt[i] = (cnt[i] + cnt[u]) % mod;
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