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

const ll N = 1e5;
ll n, k[N + 1], p[N + 1], w[N + 1], dp[N + 1][2];
vector<pair<ll ,ll>> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> k[i];
    FOR(i, 2, n) cin >> p[i];
    FOR(i, 2, n) cin >> w[i];
    FOR(i, 2, n) {
        edge[p[i] + 1].pb({i, w[i]});
    }
}

void dfs(ll u, ll par) {
    vector<ll> a; a.pb(0);

    for(const auto &[i, j] : edge[u]) if(i != par) {
        dfs(i, u);
        // dp[i][0] chon par, dp[i][1] khong chon par;
        a.pb(dp[i][0] + j - dp[i][1]);
        dp[u][0] += dp[i][1];
        dp[u][1] += dp[i][1];
    }

    sort(a.begin() + 1, a.end(), greater<ll>());
    FOR(i, 1, min((ll)a.size() - 1, k[u])) if(a[i] > 0) {
        if(i <= k[u]) dp[u][1] += a[i];
        if(i < k[u]) dp[u][0] += a[i];
    }

    if(k[u] == 0) dp[u][0] = -1e18;
}

void solve() {
    dfs(1, -1);
    cout << dp[1][1];
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