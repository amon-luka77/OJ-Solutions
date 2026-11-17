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

const ll N = 5e2;
ll n, m, q, d[N + 1][N + 1], a[N + 1], ans[N + 1];

struct Query {
    ll x, y, z, t;
};

vector<Query> query;

void read() {
    cin >> n >> m;

    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) FOR(j, 1, n) {
        d[i][j] = 1e15;
        if(i == j) d[i][j] = 0;
    }

    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;

        d[x][y] = min(d[x][y], z);
        d[y][x] = min(d[y][x], z);
    }

    cin >> q;

    FOR(i, 1, q) {
        ll x, y, t; cin >> x >> y >> t;

        query.pb({x, y, t, i});
    }

    sort(all(query), [](const Query &x, const Query &y) {
        return x.z < y.z;
    });
}

void solve() {
    ll curPos = 1;

    for(auto &[u, v, Time, idx] : query) {

        while(curPos <= n && a[curPos] <= Time) {
            FOR(i, 1, n) FOR(j, 1, n) {
                if(d[i][curPos] != 1e15 && d[curPos][j] != 1e15) {
                    if(d[i][j] > d[i][curPos] + d[curPos][j]) {
                        d[i][j] = d[i][curPos] + d[curPos][j];
                    }  
                    d[j][i] = d[i][j];
                }
            }

            curPos ++;
        }

        if(a[u] > Time || a[v] > Time || d[u][v] == 1e15) ans[idx] = -1;
        else ans[idx] = d[u][v];
    }
}

void write() {
    FOR(i, 1, q) cout << ans[i] << el;
}

int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}