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
const ll N = 1e6;
ll n, m, k, ans = 1e18;
bool vs[N + 1];
vector<pair<ll, ll>> query;
pair<ll, ll> a[N + 1];

void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= k; i ++) {
        cin >> a[i].ft >> a[i].sc;
    }
    
    ll q; cin >> q;
    for(ll i = 1; i <= q; i ++) {
        ll x, y; cin >> x >> y;
        query.pb({x, y});
    }
}

void dfs(ll u, ll end_node, ll dis) {
    vs[u] = 1;
    if(u == end_node) {
        ans = min(ans, dis - 2);
        return;
    }

    for(ll i = 1; i <= k; i ++) {
        if(!vs[i]) {
            dfs(i, end_node, dis + 1);
        }
    }
}

void solve() {
        for(auto &[i, j] : query) {
            ans = 1e18;
            memset(vs, 0, sizeof(vs));
            dfs(query[0].ft, query[0].sc, 0);
            if(ans == 1e18) cout << -1 << el;
            else cout << ans << el;
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