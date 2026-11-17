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
const ll N = 4e4;

ll w, h, n, S = 0, cel[N + 1], col[N + 1];

vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void read() {
    cin >> w >> h >> n;

    FOR(i, 1, w) cel[i] = 1;
    FOR(i, 1, h) col[i] = 1;

    FOR(i, 1, n) {
        ll x, y; cin >> x >> y;
        cel[x] = 0;
        col[y] = 0;
    }
}

void solve() {
    ll x = 0, y = 0;
    ll X = 0, Y = 0;

    FOR(i, 1, w) {
        if(cel[i] == 1) x ++;
        else x = 0;

        X = max(X, x);
    }

    FOR(i, 1, h) {
        if(col[i] == 1) y ++;
        else y = 0;

        Y = max(Y, y);
    }

    cout << X * Y;
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