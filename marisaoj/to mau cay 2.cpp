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
ll n, dp[N + 1][5];
vector<ll> edge[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i < n; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    dp[u][0] = 1, dp[u][1] = 1, dp[u][2] = 1;

    for(auto i : edge[u]) {
        if(i != par) {
            dfs(i, u);
        }
    }

    
    for(ll i = 0; i <= 2; i ++) {
        ll t = 1;
        for(auto j : edge[u]) {
            if(j == par) continue;
            t = (t * (dp[j][(i + 1) % 3] + dp[j][(i + 2) % 3]) % mod) % mod;
        }

        dp[u][i] = t;
    }
}

void solve() {
    dfs(1, -1);

    cout << (dp[1][0] + (dp[1][1] + dp[1][2]) % mod) % mod;
}

void write() {
    // for(ll i = 1; i <= n; i ++) {
    //     for(ll j = 0; j <= 2; j ++) {
    //         cout << "dinh " << i << " co mau " << j << " so cach to la " << dp[i][j] << el;
    //     }
    // }
}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}