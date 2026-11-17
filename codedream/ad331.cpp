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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5;
ll n, q, a[N + 1], dp[N + 1][3];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 2, n) {
        ll x; cin >> x;
        edge[x].pb(i);
        edge[i].pb(x);
    } 
}

void dfs(ll u, ll par) {
    dp[u][1] = 1;
    for(auto i : edge[u]) if(i != par) {
        dfs(i, u);
        dp[u][1] += max(dp[i][0], dp[i][1] * (a[u] >= a[i]));
        dp[u][0] += max(dp[i][0], dp[i][1]);
    }
}

void solve() {
    dfs(1, -1);
    while(q --) {
        ll x; cin >> x;
        cout << max(dp[x][0], dp[x][1]) << el;
    }
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