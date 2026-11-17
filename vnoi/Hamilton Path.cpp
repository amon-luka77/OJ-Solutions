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
ll block = 0;
ll n, k = -1e18;

struct HL {
    ll fi, se, t;
};

vector<HL> hamilton;

void read() {
    cin >> n;

    for(ll i = 1; i <= n; i ++) {
        ll x, y; cin >> x >> y;
        // k = max(k, x);
        hamilton.pb({-- x, -- y, i});
    }

    block = sqrt(n) + 1;

    sort(all(hamilton), [](HL &x, HL &y) {
        ll rx = x.fi / block;
        ll ry = y.fi / block;

        if(rx != ry) return rx < ry;
        else {
            if(rx % 2) return x.se < y.se;
            return x.se > y.se;
        }
    });

    for(auto [i, j, z] : hamilton) {
        cout << z << ' ';
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