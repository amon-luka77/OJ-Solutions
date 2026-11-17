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
ll n, m, dp[N + 1];
vector<ll> edge[N + 1];
bool vs[N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
    }
}

void dfs(ll u) {
    vs[u] = true;

    for(auto i : edge[u]) {
        if(!vs[i]) {
            dfs(i);
            dp[u] = max(dp[u], dp[i] + 1);
        } else {
            dp[u] = max(dp[u], dp[i] + 1);
        }
    }
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        if(!vs[i]) dfs(i);
    }
}
void write() {
    ll ans = 0;
    for(ll i = 1; i <= n; i ++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}