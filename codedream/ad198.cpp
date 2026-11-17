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
ll n, m, q, a[(ll)1e3 + 1][(ll)1e3 + 1], parent[N + 1], sz[N + 1], ans = 1;
vector<pair<ll, ll>> go = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void read() {
    cin >> n >> m;
}

ll idx(ll x, ll y) {
    return (x - 1) * m + y;
}

void make_set() {
    for(ll i = 1; i <= n * m; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
    }

    ans = max({ans, sz[x], sz[y]});
}

void solve() {
    make_set();

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            char x5; cin >> x5;
            a[i][j] = x5 - '0';
            if(x5 == '1') {
                for(auto [x, y] : go) {
                    ll new_i = i + x;
                    ll new_j = j + y;
                    if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || a[new_i][new_j] == 0) continue;
                    union_set(idx(i, j), idx(new_i, new_j));
                }
            }
        }
    }

    cin >> q;

    for(ll i = 1; i <= q; i ++) {
        ll x, y; cin >> x >> y;
        a[x][y] = 1;
        for(auto [k, l] : go) {
            ll new_i = x + k;
            ll new_j = y + l;
            if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || a[new_i][new_j] == 0) continue;
            union_set(idx(x, y), idx(new_i, new_j));
        }

        cout << ans << el;
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