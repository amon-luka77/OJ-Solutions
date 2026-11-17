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
const ll N = 101;
ll e1, w1, e2, w2, s, x, y;
void read() {
    cin >> e1 >> w1 >> e2 >> w2 >> s >> x >> y;
}
void solve() {
    vector<ll> dis(N + 1, 1e18);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, x});
    dis[x] = 0;
    while(!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        if(t.ft > dis[t.sc]) continue;
        for(ll j = 1; j <= N; j ++) {
            ll kc = min({s * abs(j - t.sc), w1 + e1 * abs(j - t.sc)});
            if(t.sc % 10 == 0 && j % 10 == 0) {
                kc = min(kc, w2 + e2 * abs(j - t.sc) / 10);
            }
            if(dis[j] > kc + t.ft) {
                dis[j] = kc + t.ft;
                pq.push({dis[j], j});
            }
        }
    }
    
    cout << dis[y];
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