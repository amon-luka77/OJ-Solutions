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

const ll N = 0;
ll n, m;
vector<vector<char>> a;
vector<vector<bool>> vs;
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}};

void read() {
    cin >> n >> m;
    a.assign(n + 1, vector<char>(m + 1, '0'));
    vs.assign(n + 1, vector<bool>(m + 1, 0));

    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
    }
}

bool dfs(ll i, ll j) {
    if(i == n && j == m) return 1;
    for(auto &[x, y] : d) {
        ll newI = i + x;
        ll newJ = j + y;
        if(newI < 1 || newI > n || newJ < 1 || newJ > m || vs[newI][newJ] || a[newI][newJ] == '#') continue;
        if(dfs(newI, newJ)) {
            vs[newI][newJ] = 1;
            return 1;
        }
    }

    return 0;
}

void solve() {
    dfs(1, 1);
    ll ans = 1e18;

    FOR(i, 2, n - 1) {
        ll sum = 0;
        ll x = i, y = i;

        while(x >= 1 && x <= n && y >= 1 && y <= m) {
            sum += vs[x][y];
            x ++; y ++;
        }
        x = i, y = i;
        while(x >= 1 && x <= n && y >= 1 && y <= m) {
            x --; y --;
            if(x >= 1 && x <= n && y >= 1 && y <= m) sum += vs[x][y];
            else break;
        }

        ans = min(ans, sum);
    }

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