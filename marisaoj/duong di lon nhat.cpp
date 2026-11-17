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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 1e5;
ll n, m, dp[N + 1][26], vs[N + 1];
string s;
vector<ll> edge[N + 1];

void read() {
    cin >> n >> m;
    cin >> s; s = ' ' + s;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
    }
}

void dfs(ll u) {
    vs[u] = 1;

    for(auto v : edge[u]) {
        if(!vs[v]) dfs(v);

        FOR(i, 0, 25) dp[u][i] = max(dp[u][i], dp[v][i]);
    } 

    dp[u][s[u] - 'a'] ++;
}

void solve() {
    FOR(i, 1, n) if(!vs[i]) dfs(i);

    ll ans = 0;
    FOR(i, 1, n) ans = max(ans, *max_element(dp[i], dp[i] + 26));
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