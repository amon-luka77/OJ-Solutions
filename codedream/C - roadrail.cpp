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

const ll N = 200000;
ll n, m, l, parent[N + 1][3], sz[N + 1][3], ans[N + 1];

ll find_set(ll k, ll t) {
    if(k == parent[k][t]) return k;
    return parent[k][t] = find_set(parent[k][t], t);
}

void union_set(ll u, ll v, ll t) {
    ll x = find_set(u, t), y = find_set(v, t);

    if(x != y) {
        if(sz[x][t] < sz[y][t]) swap(x, y);
        parent[y][t] = x;
        sz[x][t] += sz[y][t];
    }
}

void read() {
    cin >> n >> m >> l;

    FOR(i, 1, n) FOR(j, 1, 2) {
        parent[i][j] = i;
        sz[i][j] = 1;
    }

    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        union_set(x, y, 1);
    }

    vector<pair<ll, ll>> a;

    FOR(i, 1, l) {
        ll x, y; cin >> x >> y;
        a.pb({x, y});
        union_set(x, y, 2);
    }

    // dem so cap i, j sao cho i1 = j1 && i2 = j2

    map<pair<ll, ll>, ll> ts;

    FOR(i, 1, n) {
        ts[{find_set(i, 1), find_set(i, 2)}] ++;
    }

    FOR(i, 1, n) cout << ts[{find_set(i, 1), find_set(i, 2)}] << ' ';
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