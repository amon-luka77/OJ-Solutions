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

const ll N = 1e5;
ll n, m;

struct DSU {
    vector<ll> parent, sz;

    DSU(ll n) {
        parent.assign(n + 1, 0);
        sz.assign(n + 1, 0);
    }

    void make_sets(ll n) {
        for(ll i = 1; i <= n; i ++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    ll find_sets(ll k) {
        if(k == parent[k]) return k;
        return parent[k] = find_sets(parent[k]);
    }

    void union_sets(ll u, ll v) {
        ll x = find_sets(u);
        ll y = find_sets(v);

        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            parent[y] = x;
            sz[x] += sz[y];
        }
    }

    void check_sets(ll u, ll v) {
        if(find_sets(u) != find_sets(v)) cout << "NO" << el;
        else cout << "YES" << el;
    }
};

void read() {
    cin >> n >> m;
}

void solve() {
    DSU g(n);
    g.make_sets(n);

    for(ll i = 1; i <= m; i ++) {
        string s; ll u, v; cin >> s >> u >> v;
        if(s == "union") {
            g.union_sets(u, v);
        } else {
            g.check_sets(u, v);
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
