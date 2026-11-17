/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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

const ll N = 1e4, mod = 1e9 + 7;
ll n, k, treeSize[N + 1], high[N + 1], dp[N + 1];
vector<ll> edge[N + 1];
vector<ll> ans;

void read() {
    cin >> n >> k; k --;
    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y); edge[y].pb(x);
    }
}

void dfs(ll u, ll par) {
    treeSize[u] = 1;
    for(auto i : edge[u]) if(i != par) {
        high[i] = high[u] + 1;
        dfs(i, u);
        treeSize[u] += treeSize[i];
    }
}

void dfsAns(ll u, ll par) {
    if(high[u] > k) return;
    ll pre = k - high[u];
    if(dp[pre]) ans.pb(u);
    
    for(auto i : edge[u]) if(i != par) FORD(j, k, treeSize[i]) if(dp[j - treeSize[i]]) {
        dp[j] += dp[j - treeSize[i]];
        if(dp[j] >= mod) dp[j] -= mod;
    }

    for(auto i : edge[u]) if(i != par) {    
        FOR(j, treeSize[i], k) if(dp[j - treeSize[i]]) {
            dp[j] -= dp[j - treeSize[i]];
            dp[j] += mod; if(dp[j] >= mod) dp[j] -= mod;
        }

        dfsAns(i, u);
        
        FORD(j, k, treeSize[i]) if(dp[j - treeSize[i]]) {
            dp[j] += dp[j - treeSize[i]];
            if(dp[j] >= mod) dp[j] -= mod;
        }
    }

    for(auto i : edge[u]) if(i != par) FOR(j, treeSize[i], k) if(dp[j - treeSize[i]]) {
        dp[j] -= dp[j - treeSize[i]];
        dp[j] += mod; if(dp[j] >= mod) dp[j] -= mod;
    }
}

void solve() {
    dp[0] = 1;
    dfs(1, -1);
    dfsAns(1, -1);

    sort(all(ans));

    for(auto i : ans) cout << i << ' ';
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