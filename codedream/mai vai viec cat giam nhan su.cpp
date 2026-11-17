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
ll n, dp[N + 1], ans = 0;

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 2, n) {
        ll x; cin >> x;
        edge[x].pb(i);
        edge[i].pb(x);
    }
}

void dfs(ll u, ll par) {
    dp[u] = 1;
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        dp[u] = dp[u] * (dp[i] + 1) % mod;
    }
}

void solve() {
    dfs(1, -1);
    cout << dp[1];
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