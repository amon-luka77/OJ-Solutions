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
const ll N = 1000;
ll m, n, parent[N * N + 1], sz[N * N + 1];

void read() {
    cin >> m >> n;
    n ++, m ++;
}

ll idx(ll u, ll v) {
    return (u - 1) * n + v;
}
ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void make_set() {
    for(ll i = 1; i <= n * m; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        
        parent[y] = x;
        sz[x] += sz[y];
    }
}

struct kk {
    ll x, y, z, t;
};

vector<kk> ans;

pair<ll, ll> bk(ll i) {
    ll t = (i + n - 1) / n;
    ll t2 = i - (t - 1) * n;
    return {t - 1, t2 - 1};
}

vector<pair<ll, ll>> go = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void solve() {
    make_set();

    ll x, y, u, v;
    while(cin >> x >> y >> u >> v) {
        x ++, y ++, u ++, v ++;
        union_set(idx(x, y), idx(u, v));
    }

    
    for(ll i = 1; i <= m; i++) {
        for(ll j = 1; j <= n; j++) {
            for(auto [x, y] : go) {
                ll new_x = i + x;
                ll new_y = j + y;
                if(new_x < 1 || new_x > m || new_y < 1 || new_y > n) continue;

                ll a = idx(i, j), b = idx(new_x, new_y);

                ll ra = find_set(a), rb = find_set(b);

                if(ra != rb) {
                    union_set(ra, rb);

                    ans.pb({i - 1, j - 1, new_x - 1, new_y - 1});
                }
            }
        }
    }

    cout << ans.size() << el;
    for(auto [x, y, z, t] : ans) {
        cout << x << ' ' << y << ' ' << z << ' ' << t << el;
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