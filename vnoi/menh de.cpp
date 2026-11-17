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
ll n, q, parent[N + 1], sz[N + 1], dis[N + 1];
void read() {
    cin >> n >> q;
}

void make_set() {
    for(ll i = 0; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    ll t = parent[k];
    parent[k] = find_set(parent[k]);

    dis[k] = (dis[k] + dis[t]) % 2;
    return parent[k];
}

bool union_set(ll u, ll v, ll k) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x == y) {
        if(dis[u] != dis[v] && k == 0 || dis[u] == dis[v] && k == 1) {
            return false;
        } else {
            return true;
        }
    } else {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];

        dis[y] = (dis[u] + dis[v] + k) % 2;

        return true;
    }
}

void solve() {
    make_set();

    for(ll i = 1; i <= q; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        if(!union_set(x - 1, y, z)) {
            cout << i - 1;
            exit(0);
        }
    }

    cout << q;
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