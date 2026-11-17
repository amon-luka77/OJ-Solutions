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
const ll N = 100;
ll n, m, parent[N + 1], sz[N + 1];

struct EG {
    ll x, y, z;
};

vector<EG> edge;

void read() {
    cin >> n >> m;
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

bool union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];

        return 1;
    }

    return 0;
}

void solve() {
    make_set();
    vector<pair<ll, ll>> ans;
    ll total = 0;

    for(ll i = 1; i <= m ; i++) {
        ll x, y; cin >> x >> y;
        union_set(x, y);
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            ll x; cin >> x;
            edge.pb({i, j, x});
        }
    }

    sort(all(edge), [](EG &x, EG &y) {
        return x.z < y.z;
    });

    for(auto [i, j, k] : edge) {
        if(union_set(i, j)) {
            total += k;
            ans.pb({i, j});
        }
    }

    cout << total << el;
    for(auto [i, j] : ans) {
        cout << i << ' ' << j << el;
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