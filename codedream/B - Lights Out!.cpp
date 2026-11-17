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

const ll N = 5;
ll n, m, ans = 1e18, a[N + 1][N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void add(ll x, ll y) {
    a[x][y] = !a[x][y];
    for(auto &[i, j] : d) {
        ll newI = i + x;
        ll newJ = j + y;
        if(newI < 1 || newI > n || newJ < 1 || newJ > m) continue;

        a[newI][newJ] = !a[newI][newJ];
    }
}

void backtrack(ll x, ll y, ll cnt) {
    if(x > n) {
        bool ok = 1;
        FOR(i, 1, n) FOR(j, 1, m) {
            if(a[i][j]) {
                ok = 0;
                break;
            }
        }

        if(ok) ans = min(ans, cnt);
        return;
    }

    if(y > m) {
        backtrack(x + 1, 1, cnt);
        return;
    }

    backtrack(x, y + 1, cnt);
    add(x, y);
    backtrack(x, y + 1, cnt + 1);
    add(x, y);
}

void read() {
    FOR(t, 1, 5) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        ans = 1e18;

        FOR(i, 1, n) FOR(j, 1, m) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }

        backtrack(1, 1, 0);

        if(ans == 1e18) cout << -1 << el;
        else cout << ans << el;
    }
}

void solve() {

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