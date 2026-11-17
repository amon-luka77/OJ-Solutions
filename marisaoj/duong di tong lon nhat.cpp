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
ll n, ans = -1e18, a[N + 1], dp[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i < n; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    dp[u] = a[u];
    pair<ll, ll> k;

    for(auto i : edge[u]) {
        if(i != par) {
            dfs(i, u);

            dp[u] = max(dp[u], a[u] + dp[i]);
            if(k.ft < dp[i]) {
                k.sc = k.ft;
                k.ft = dp[i];
            } else {
                k.sc = max(k.sc , dp[i]);
            }
        }
    }

    ans = max({ans, dp[u], k.ft + k.sc + a[u]});
}

void solve() {
    dfs(1, -1);
}

void write() {
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