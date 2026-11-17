#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const ll N = 100;
ll n, m, d[N + 1];
struct EDGE {
    ll t;
    vector<ll> a;
};
vector<EDGE> edge[N + 1];

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        EDGE k, l;
        k.t = x;
        l.t = y;
        for(ll j = 1; j <= z; j ++) {
            ll c; cin >> c;
            k.a.pb(c);
            l.a.pb(c);
        }
        edge[x].pb(l);
        edge[y].pb(k);
    }

    for(ll i = 1; i <= n; i ++) {
        d[i] = 1e18;
    }
}

void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    d[1] = 0;

    while(!pq.empty()) {
        auto [dis, u] = pq.top();
        pq.pop();

        if(dis > d[u]) continue;

        for(auto eg : edge[u]) {
            ll min_d = 1e18;
            ll v = eg.t;
            auto &i = eg.a;
            for(ll j = 0; j < i.size(); j ++){
                ll k = ((dis - i[j] + 99) / 100) * 100 + i[j];
                min_d = min(min_d, k);
            }
            if(d[v] > min_d) {
                d[v] = min_d;
                pq.push({d[v], v});
            }
        }
    }
}

void write() {
    ll ans = -1e18;
    for(ll i = 1; i <= n; i++) {
        ans = max(ans, d[i]);
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    read();
    solve();
    write();
    return 0;
}
