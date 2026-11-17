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
ll n, dp[N + 1][3];
pair<ll, ll> a[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y; cin >> x >> y;
        a[i] = {x, y};
    }

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y; 
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        dp[u][0] += max(abs(a[u].ft - a[i].sc) + dp[i][1], abs(a[u].ft - a[i].ft) + dp[i][0]);
        dp[u][1] += max(abs(a[u].sc - a[i].ft) + dp[i][0], abs(a[u].sc - a[i].sc) + dp[i][1]);
    }
}

void solve() {
    dfs(1, -1);
    cout << max(dp[1][1], dp[1][0]);
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