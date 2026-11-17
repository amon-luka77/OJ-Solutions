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
const ll N = 2e5;
ll n, m, parent[N + 1], sz[N + 1], add[N + 

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
    parent[k] = find_set(parent[k]);

    add[k] = (add[k] + add[t]) % 2;

    return parent[k];
}

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];

        add[y] = (add[u] + add[v] + 1) % 2;
    }
}

void get_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        cout << "Merry Christmas!" << el;
    } else {
        if(add[u] != add[v]) cout << "No" << el;
        else cout << "Yes" << el;
    }
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        if(x == 1) {
            union_set(y, z);
        } else {
            get_set(y, z);
        }
    }

    // for(ll i = 1; i <= n; i ++) {
    //     cout << add[i] << ' ';
    // }
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