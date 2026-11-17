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

const ll N = 2e5;
ll n, dp[N + 1][2]; 

vector<ll> edge[N + 1];

void read() {
    cin >> n;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        dp[u][0] += max(dp[i][0], dp[i][1]);
    }

    for(auto i : edge[u]) if(i != par) {
        dp[u][1] = max({dp[u][1], dp[u][0] - max(dp[i][0], dp[i][1]) + dp[i][0] + 1});
    }
        
}

void solve() {
    dfs(1, -1);
    
    cout << max(dp[1][0], dp[1][1]);
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