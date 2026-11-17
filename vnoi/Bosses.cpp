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
ll n, m, parent[N + 1], sz[N + 1];
void read() {
    cin >> n >> m;
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 0;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    ll t = find_set(parent[k]);
    return t;
}

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    parent[x] = y;
    sz[x] ++;
}

ll get(ll k) {
    ll total = 0;
    while(1) {
        total += sz[k];
        if(k == parent[k]) break;
        k = parent[k];
    }

    return total;
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        ll x, l, r; cin >> x >> l;

        if(x == 1) {
            cin >> r;
            union_set(l, r);
        } else {
            cout << get(l) << el;
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