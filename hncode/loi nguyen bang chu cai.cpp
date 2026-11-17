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

const ll N = 2e3;
ll n, m, l, f[N + 1][N + 1];

vector<pair<ll, char>> edge[N + 1];

void read() {
    cin >> n >> m >> l;
    FOR(i, 1, m) {
        ll x, y; char z; cin >> x >> y >> z;
        edge[x].pb({y, z});
    }
}
void dfs(ll u) {
    for(auto &[i, amon] : edge[u]) {
        dfs(i);
        FOR(j, 1, l) {
            if(f[i][l - 1]) f[u][l] = 1;
        }
    }
} 

string dp(ll u, ll l, string s) {
    if(u == n) return s;
    for(auto &[i, j] : edge[u]) {
        if(f[i][l + 1]) return (i, l + 1, s + j);
    }

    string t = "-1";
    return t;
} 

void solve() {
    f[n][0] = 1;
    dfs(1);

    FOR(i, 1, n) {
        cout << i << el;
        FOR(j, 1, l) {
            cout << "{" << j << ", " << dp[i][j] << "}, ";
        }
        cout << el;
    }

    FOR(i, 1, n) {
        sort(all(edge[i]), [](const pair<ll, char> &x, const pair<ll, char> &y) {
            return x.sc < y.sc;
        });
    }

    cout << dp(1, 0, "");
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