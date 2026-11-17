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
const ll N = 5e3;
ll n, l, p[N  + 1], S[N + 1], L[N + 1][N + 1], dp[N + 1][N + 1];

vector<ll> edge[N + 1];

bool vs[N + 1];

void read() {
    cin >> n >> l;
    for(ll i = 2; i <= n; i ++) {
        cin >> p[i];
        ll x = i, y = p[i];

        edge[x].pb(y);
        edge[y].pb(x);
    } 

    for(ll i = 1; i <= n; i ++) {
        cin >> S[i];
    }
    
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 0; j <= l; j ++) {
            cin >> L[i][j];
            dp[i][j] = L[i][j];
        }
    }
}

void dfs(ll u) {
    vs[u] = 1;

    for(auto i : edge[u]) {
        if(!vs[i]) {
            dfs(i);

            for(ll k = S[u]; k >= 0; k --) {
                for(ll j = 0; j <= k; j ++) {
                    dp[u][k] = max(dp[u][k], dp[i][j] + dp[u][k - j]);
                }
            }
        }
    }
}

void solve() {
    dfs(1);

    ll ans = 0;
    for(ll i = 0; i <= min(S[1], l); i ++) {
        ans = max(ans, dp[1][i]);
    }

    cout << ans << el;

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