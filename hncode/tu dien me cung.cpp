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
ll n, m, k, f[N + 1];
vector<pair<ll, char>> edge[N + 1];
vector<ll> subEdge[N + 1];

void read() {
    cin >> n >> m >> k;
    FOR(i, 1, m) {
        ll x, y; char z; cin >> x >> y >> z;
        edge[x].pb({y, z});
    }
}

void dfs(ll u) {
    if(f[u] > 0) return;
    for(auto &[i, j] : edge[u])  {
        dfs(i);
        f[u] = min(f[u] + f[i], (ll)1e18 + 1);
    }
}

string dp(ll u, ll cnt, string s) {
    if(u == n) return s;
    for(auto &[i, j] : edge[u]) {
        if(f[i] >= cnt) {
            return dp(i, cnt, s + j);
        } else {
            cnt -= f[i];
        }
    }

    string t = "-1";
    return t;
}

void solve() {
    f[n] = 1;
    dfs(1);

    // FOR(i, 1, n) cout << i << ' ' << f[i] << el;

    FOR(i, 1, n) {
        sort(all(edge[i]), [](const pair<ll, char> &x, const pair<ll, char> &y) {
            return x.sc < y.sc;
        });
    }

    cout << dp(1, k, "");
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
