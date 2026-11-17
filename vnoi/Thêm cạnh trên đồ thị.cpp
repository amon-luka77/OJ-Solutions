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
const ll N = 3e5;
ll n, m, parent[N + 1], sz[N + 1], d[N + 1];
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
    ll t = parent[k];
    ll root = find_set(parent[k]);

    d[k] = (d[k] + d[t]) % 2;

    return parent[k] = root;
}

bool union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x == y) {
        return d[u] != d[v];
    } else {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        d[y] = (d[u] + d[v] + 1) % 2;

        return true;
    }
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        if(!union_set(x, y)) {
            cout << i;
            exit(0);
        }
    }

    cout << -1;
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