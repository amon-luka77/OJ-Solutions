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
ll n, m, parent[N + 1], sz[N + 1];
ll parent_go[N + 1], sz_go[N + 1];

void read() {
    cin >> n >> m;
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
        parent_go[i] = i;
        sz_go[i] = 1;
    }
}

ll find_set(ll k) {
    ll root = k;
    while(root != parent[root]) {
        root = parent[root];
    }

    while(k != root) {
        ll t = parent[k];
        parent[k] = root;
        k = t;
    }

    return root;
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

ll find_go(ll k) {
    ll root = k;
    while(root != parent_go[root]) {
        root = parent_go[root];
    }

    while(k != root) {
        ll t = parent_go[k];
        parent_go[k] = root;
        k = t;
    }

    return root;
}

void union_go(ll u, ll v) {
    ll x = find_go(u);
    ll y = find_go(v);
    
    parent_go[x] = y;
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        ll x, l, r; cin >> x >> l >> r;
        if(x == 1) {
            union_set(l, r);
        } else if(x == 2) {
            ll k = find_set(l);
            while(1) {
                if(l >= r) break;
                ll v = l;
                l = find_go(l + 1);
                ll t = find_set(l);
                if(t != k) {
                    union_set(t, k);
                }
                union_go(v, l);
            }
        } else {
            ll x = find_set(l);
            ll y = find_set(r);

            if(x != y) cout << "NO" << el;
            else cout << "YES" << el;
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
