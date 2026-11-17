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

const ll N = 300;
ll n, m;
char a[N][N];
bool vs[N][N];

void read() {
    cin >> n >> m;
}

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, -1, 1};
ll soi = 0, cuu = 0;
bool ok = 0;

void bfs (ll i, ll j) {
    queue <pair<ll, ll>> q;
    vs[i][j] = 1;
    q.push ({i, j});
    cuu += (a[i][j] == 'k');
    soi += (a[i][j] == 'v');
    while (!q.empty()) {
        ll x = q.front().ft;
        ll y = q.front().sc;
        if (x == n || x == 1 || y == m || y == 1) {
            ok = 1;
        }
        q.pop();
        for (ll k = 0; k < 4; k++) {
            ll newX = x + dx[k];
            ll newY = y + dy[k];
            if (a[newX][newY] == '#' || newX < 1 || newY < 1 || newX > n || newY > m || vs[newX][newY]) continue;
            q.push ({newX, newY});
            vs[newX][newY] = 1;
            if (a[newX][newY] == 'k') cuu++;
            else if (a[newX][newY] == 'v') soi++;
        }
    }
}

void solve() {
     ll cntSoi = 0, cntCuu = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> a[i][j];
            cntSoi += (a[i][j] == 'v');
            cntCuu += (a[i][j] == 'k');
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (vs[i][j] || a[i][j] == '#') continue;
            bfs (i, j);
            if (ok) {
                ok = 0;
                soi = 0;
                cuu = 0;
                continue;
            }
            if (soi >= cuu) cntCuu -= cuu;
            else cntSoi -= soi;
            cuu = 0;
            soi = 0;
        }
    }
    cout << cntCuu << " " << cntSoi;
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