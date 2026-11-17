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
const ll N = 1e4;
ll n, m, parent[N + 1], sz[N + 1];

struct EG {
    ll x, y, z, t;
};

vector<EG> edge;

void read() {
    cin >> n >> m;

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge.pb({x, y, z, i});
    }

    sort(all(edge), [](EG &x, EG &y) {
        return x.z < y.z;
    });
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
    vector<ll> ans; ll total = 0;

    for(auto [i, j, k, l] : edge) {
        if(ans.size() == n - 1) break;
        if(union_set(i, j)) {
            total += k;
            ans.pb(l);
        }
    }

    cout << total << el;
    for(auto i : ans) {
        cout << i << el;
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