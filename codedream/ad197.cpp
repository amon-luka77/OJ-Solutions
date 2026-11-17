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
const ll N = 1e3;
ll n, m, k, parent[N + 1], sz[N + 1], cnt=  0, k_lv = 1e18;

void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i ++) {
        ll x; cin >> x;
        k_lv = min(k_lv, x);
    }
}

void make_set() {
    cnt = n;
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v, ll z) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
        cnt --;
    }
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        if(z < k_lv) continue;
        union_set(x, y, z);
    }

    cout << cnt;
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