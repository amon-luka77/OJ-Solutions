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
ll k, m;

unordered_map<ll, ll> parent, sz, deg;

ll find_set(ll k) {
    if(parent.find(k) == parent.end()) {
        parent[k] = k;
        sz[k] = 1;
        return k;
    }

    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void read() {

    while(cin >> k >> m) {
        if(k == 0 && m == 0) break;

        parent.clear();
        sz.clear();
        deg.clear();

        bool ok = 1;

        FOR(i, 1, m) {
            ll x, y; cin >> x >> y;

            deg[x] ++; deg[y] ++;
            if(deg[x] > 2 || deg[y] > 2) {
                ok = 0;
                break;
            }

            ll rx = find_set(x), ry = find_set(y);

            if(rx == ry && i < m) {
                ok = 0;
                break;
            }

            if(sz[rx] < sz[ry]) swap(rx, ry);

            sz[rx] += sz[ry];
            parent[ry] = rx;
        }

        if(ok) cout << "Y" << el;
        else cout << "N" << el;
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