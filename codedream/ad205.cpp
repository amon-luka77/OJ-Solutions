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
ll n, m, parent[N + 1], sz[N + 1], a[N + 1];

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;
vector<ll> b;

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
    bool ok = 1;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        if(a[i] != i) b.pb(i);
        if(ok && a[i] != i) ok = 0;
    }

    if(ok) {
        cout << -1;
        exit(0);
    }

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        query.pb({x, y, z});
    }

}

bool check(ll mid) {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for(auto &[i, j, k] : query) {
        if(k >= mid) {
            union_set(i, j);
        }
    }

    for(ll i = 0; i < b.size(); i ++) {
        if(find_set(i) != find_set(a[i])) return 0;
    }
    
    return 1;
}

void solve() {
    ll l = 1, r = 1e9, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
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