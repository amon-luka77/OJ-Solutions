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
const ll N = 1e5, mod = 1e9 + 7;
ll n, ans = 0, dp[N + 1];
bool vs[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i < n; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u) {
    vs[u] = 1;
    dp[u] = 1;

    for(auto i : edge[u]) {
        if(!vs[i]) {
            dfs(i);

            dp[u] = (dp[u] * (dp[i] + 1)) % mod;
        }
    }
}

void solve() {
    dfs(1);
    ll ans = 0;
    for(ll i = 1; i <= n; i ++) {
        ans = (ans + dp[i]) % mod;
    }
    
    cout << ans;
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