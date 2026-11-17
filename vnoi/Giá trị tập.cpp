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
ll n, m, parent[N + 1], sz[N + 1], min_n[N + 1], max_n[N + 1];

void read() {
    cin >> n >> m;
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        sz[i] = 1;
        parent[i] = i;
        min_n[i] = i;
        max_n[i] = i;
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
        min_n[x] = min(min_n[x], min_n[y]);
        max_n[x] = max(max_n[x], max_n[y]);
    }
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        string s; ll l, r; cin >> s >> l;
        if(s == "union") {
            cin >> r;
            union_set(l, r);
        } else {
            ll t = find_set(l);
            cout << min_n[t] << ' ' << max_n[t] << ' ' << sz[t] << el;
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