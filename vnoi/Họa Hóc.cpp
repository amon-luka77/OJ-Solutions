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
const ll N = 5e4;
ll n, m, s, parent[N + 1], sz[N + 1];

struct NODE {
    ll x, y, z, t;
};

vector<NODE> edge;

void read() {
    cin >> n >> m >> s;

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge.pb({x, y, z, i});
    }

    sort(all(edge), [](NODE &x, NODE &y) {
        return x.z > y.z;
    });
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    ll root = k;
    while(root != parent[root]) {
        root = parent[root];
    }

    while(k != root) {
        ll t = parent[k];
        parent[k] = root;
        k = t;
    }

    return root;
}

bool union_set(ll u, ll v) {
    u = find_set(u), v = find_set(v);
    
    if(u != v) {
        if(sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return 1;
    } else {
        return 0;
    }
}

void solve() {
    make_set();

    vector<pair<ll, ll>> ans;
    vector<ll> kq;
    ll totalWeights = 0;

    for(auto [x, y, z, t] : edge) {
        if(!union_set(x, y)) ans.pb({z, t});
    }

    reverse(all(ans));

    for(auto [i, j] : ans) {
        totalWeights += i;
        if(totalWeights > s) break;

        kq.pb(j);
    }

    sort(all(kq));

    cout << kq.size() << el;
    for(auto i : kq) cout << i << ' ';
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