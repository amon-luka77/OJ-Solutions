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
const ll N = 1e5;
ll n, dp[N + 1][3];

bool vs[N + 1];

pair<ll, ll> a[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i].ft >> a[i].sc;
    }

    for(ll i = 1; i < n; i ++) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void dfs(ll u) {
    vs[u] = 1;

    for(auto i : edge[u]) {
        if(!vs[i]) {
            dfs(i);

            dp[u][0] += max(dp[i][0] + abs(a[u].ft - a[i].ft), dp[i][1] + abs(a[u].ft - a[i].sc));
            dp[u][1] += max(dp[i][0] + abs(a[u].sc - a[i].ft), dp[i][1] + abs(a[u].sc - a[i].sc));
        }
    }
}

void solve() {
    dfs(1);

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