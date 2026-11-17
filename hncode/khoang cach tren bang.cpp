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
vector<vector<ll>> a;
ll n, m, k, q;

struct QUERY {
    ll x, y, z, t;
};

vector<QUERY> query;

void read() {
    cin >> n >> m >> k;
    a.assign(n + 1, vector<ll>(m + 1, 0));

    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
    }

    cin >> q;
    FOR(i, 1, q) {
        ll x, y, z, t;
        cin >> x >> y >> z;
        if(x == 1) {
            cin >> t;
            query.pb({x, y, z, t});
        } else {
            query.pb({x, y, z, 0});
        }
    }
}

void solve() {
    if(q == 1) {
        if(query[0].x == 2) {
            ll x = query[0].y;
            ll y = query[0].z;
            vector<pair<ll, ll>> b, c;

            ll ans = 0;

            FOR(i, 1, n) FOR(j, 1, m) {
                if(a[i][j] == x) b.pb({i, j});
                if(a[i][j] == y) c.pb({i, j});
            }

            for(auto [i, j] : b) {
                for(auto [x, y] : c) {
                    ans =  max(ans, abs(i - x) + abs(j - y));
                }
            }

            cout << ans;
        }
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