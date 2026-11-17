#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
using namespace std;
const ll N = 1e5, mod = 1e9 + 7;
ll n, f[N + 1][3];
vector<ll> edge[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i < n; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
    memset(f, -1, sizeof(f));
}

ll dp(ll u, ll color, ll parent) {
    if(f[u][color] != -1) return f[u][color];

    ll res = 1;
    for(auto i : edge[u]) {
        if(i != parent) {
            res = (res * (dp(i, (color + 1) % 2, u) + (color == 0) * dp(i, color, u)) % mod) % mod;
        }
    }

    return f[u][color] = res;
}

void solve() {
    cout << (dp(1, 0, 0) + dp(1, 1, 0)) % mod;
}

void write() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    read();
    solve();
    write();
    return 0;
}
