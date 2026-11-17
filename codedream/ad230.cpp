#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 2e4;
ll n, m, s, f, root, dp[N + 1][3]; 
bool mark[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> m >> s >> f;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        mark[y] = 1;
    }

    FOR(i, 1, n) if(!mark[i]) {
        root = i;
        break;
    }
}

void dfs(ll u, ll par) {
    dp[u][1] = s; dp[u][0] = f;
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);

        dp[u][2] += min(dp[i][1], dp[i][0]);
        dp[u][1] += min(dp[i][1], dp[i][0]);
        dp[u][0] += min({dp[i][0], dp[i][1], dp[i][2]});
    }
}

void solve() {
    dfs(root, -1);

    // cout << root << el;
    // FOR(i, 1, n) FOR(j, 0, 1) cout << i << ' ' << j << ' ' << dp[i][j] << el;   

    cout << min(dp[root][0], dp[root][1]);
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
