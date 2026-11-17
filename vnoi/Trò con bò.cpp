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
ll n, m, parent[N + 1], sz[N + 1], add[N + 1];
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
    ll t = find_set(parent[k]);
    return t;
}

void union_set(ll u, ll v) {
    ll a = find_set(u);
    ll b = find_set(v);

    if(a != b) {
        if(sz[a] < sz[b]) swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
        add[b] -= add[a];
    }
}

ll get(ll u) {
    ll total = 0;

    while(1) {
        total += add[u];
        if(u == parent[u]) break;
        u = parent[u];
    }

    return total;
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        string s; ll l, r; cin >> s >> l;
        if(s == "get") {
            cout << get(l) << el;
        } else if(s == "join") {
            cin >> r;
            union_set(l, r);
        } else {
            cin >> r;
            ll t = find_set(l);
            add[t] += r;
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
