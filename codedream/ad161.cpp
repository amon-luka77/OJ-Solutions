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
const ll N = 500;
ll n;
vector<pair<ll, ll>> edge[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            ll x; cin >> x;
            if(x > 0) edge[i].pb({j, x});
        }
    }
}
void solve() {
    pair<ll, ll> ans = {0, 1e18};
    vector<ll> kq;
    for(ll i = 1; i <= n; i ++) {
        vector<ll> path(n + 1, 0);
        vector<ll> dis(n + 1, 1e18);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, i});
        dis[i] = 0;
        while(!pq.empty()) {
            auto t = pq.top();
            pq.pop();

            if(t.ft > dis[t.sc]) continue;

            for(auto j : edge[t.sc]) {
                if(dis[j.ft] > t.ft + j.sc) {
                    dis[j.ft] = t.ft + j.sc;
                    path[j.ft] = t.sc;
                    pq.push({dis[j.ft], j.ft});
                }
            }
        }
        
        ll d1 = 0;
        for(ll j = 1; j <= n; j ++) {
            if(dis[j] != 1e18) d1 = max(d1, dis[j]);
        }

        if(d1 < ans.sc) {
            ans = {i, d1};
            kq = path;
        }
    }

    cout << ans.ft << ' ' << ans.sc << el;

    for(ll i = 1; i <= n; i ++) {
        if(i == ans.ft) continue;

        ll t = i;
        vector<ll> trace;
        while(t != 0) {
            trace.pb(t);
            t = kq[t];
        }
        for(auto j : trace) {
            cout << j << ' ';
        }
        cout << el;
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