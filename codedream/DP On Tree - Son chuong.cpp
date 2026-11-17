/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
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

const ll N = 1e5, mod = 1e9 + 7;
ll n, k, dp[N + 1][4], a[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    memset(a, -1, sizeof a);

    FOR(i, 1, k) {
        ll x, y; cin >> x >> y; y --;
        a[x] = y;
    }
}

void dfs(ll u, ll par) {
    if(a[u] != -1) dp[u][a[u]] = 1;
    else {
        FOR(i, 0, 2) dp[u][i] = 1;
    }
    bool ok = 0;
    for(auto i : edge[u]) if(i != par) {
        ok = 1;
        dfs(i, u);
        if(a[u] == -1) {
            FOR(j, 0, 2) {
                dp[u][j] = (dp[u][j] * (dp[i][(j + 1) % 3] + dp[i][(j + 2) % 3]) % mod) % mod;
            }
        } else {
            dp[u][a[u]] = (dp[u][a[u]] * (dp[i][(a[u] + 1) % 3] + dp[i][(a[u] + 2) % 3]) % mod) % mod;
        }
    }
}

void solve() {
    dfs(1, -1);
    cout << ((dp[1][0] + dp[1][1]) % mod + dp[1][2]) % mod;
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