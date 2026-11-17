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
ll n, parent[N + 1], sz[N + 1];

void read() {
    cin >> n;
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

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y =find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        
        parent[y] = x;
        sz[x] += sz[y];
    }
}

void solve() {
    make_set();

    for(ll i = 1; i <= n; i ++) {
        ll x, l, r; cin >> l >> r >> x;
        
        if(x == 1) union_set(l, r);
        else {
            ll rx = find_set(l);
            ll ry = find_set(r);
            
            cout << (rx == ry) << el;
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