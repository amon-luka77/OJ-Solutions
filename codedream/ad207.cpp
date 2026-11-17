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
ll n, m, a[N + 1], parent[N + 1], sz[N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

set<ll> k[N + 1];

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
}

void read() {
    cin >> n >> m;

    for(ll i = 1; i <= n * m; i ++) {
        parent[i] = i;
        sz[i] = 1;
        cin >> a[i];
    }

}

ll get(ll x, ll y) {
    return (x - 1) * m + y;
}

bool check(ll x, ll y, ll u, ll v) {
    ll cp1 = find_set(get(x, y));
    ll cp2 = find_set(get(u, v));

    if(cp1 == cp2) return true;

    if(a[get(x, y)] == a[get(u, v)]) {
        if(k[cp1].find(cp2) != k[cp1].end()) return true;
        if(k[cp2].find(cp1) != k[cp2].end()) return true;        
    }


    for(auto &[i, j] : d) {
        ll ri = i + x, rj = j + y;
        if(ri < 1 || ri > n || rj < 1 || rj > m) continue;

        if(find_set(get(ri, rj)) == cp2) return true;
    }

    for(auto &[i, j] : d) {
        ll ri = i + u, rj = j + v;
        if(ri < 1 || ri > n || rj < 1 || rj > m) continue;

        if(find_set(get(ri, rj)) == cp1) return true;
    }

    return false;
}

void solve() {    
    
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            for(auto &[x, y] : d) {
                ll ri = i + x, rj = j + y;
                if(ri < 1 || ri > n || rj < 1 || rj > m) continue;

                if(a[get(i, j)] == a[get(ri, rj)]) {
                    union_set(get(i, j), get(ri, rj));
                }
            }
        }
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            vector<ll> t;

            for(auto &[x, y] : d) {
                ll ri = i + x, rj = j + y;
                if(ri < 1 || ri > n || rj < 1 || rj > m) continue;

                t.pb(find_set(get(ri, rj)));
            }

            for(ll l = 0; l < t.size(); l ++) {
                for(ll u = l + 1; u < t.size(); u ++) {
                    k[t[l]].insert(t[u]);
                }
            }
        }
    }

    ll q, t = 4;
    cin >> q >> t;
    while(q --) {
        ll x, y, z, t; cin >> x >> y >> z >> t;
        if(check(++ x, ++ y, ++ z, ++ t)) {
            cout << "YES" << el;
        } else {
            cout << "NO" << el;
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