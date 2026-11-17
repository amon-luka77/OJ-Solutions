#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ft first
#define sd second
const ll siu = 505;
ll a[siu][siu];
ll n;
vector <pair <ll, ll>> adj[siu];
const ll inf = 1e18;
ll vandijk (ll s) {
    vector <ll> d(n + 1, inf);
    ll length = -inf;
    d[s] = 0;
    priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair<ll, ll>>> q;
    q.push({0, s});
    while (!q.empty()) {
        pair <ll, ll> top = q.top();
        q.pop();
        ll u = top.sd;
        ll kc = top.ft;
        if (kc > d[u]) continue;
        for (auto it : adj[u]) {
            ll v = it.ft;
            ll w = it.sd;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        length = max(length, d[i]);
    }
    return length;
}
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i != j && a[i][j] != 0) {
                adj[i].push_back({j, a[i][j]});
            }
        }
    }
    ll ans = inf;
    ll start;
    for (ll i = 1; i <= n; i++) {
        ll cur = vandijk(i);
        if (ans > cur) {
            start = i;
            ans = cur;
        }
    }
    cout << start << " " << ans;

}