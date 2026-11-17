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
const ll N = 1000;
ll n, m, cnt = 0, val = 0, parent[N + 1], sz[N + 1];

struct KK {
    ll x, y, z;
};

vector<KK> a;

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        a.pb({x, y, z});
    }
    sort(all(a), [](KK &x, KK &y) {
        return x.z < y.z;
    });
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

bool union_set(ll u, ll v, ll t) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];

        return true;
    }

    return false;
}

void solve() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }

    ll min1 = 0;
    vector<ll> mst;

    for(ll l = 0; l < m; l ++) {
        auto &[i, j, k] = a[l];
        if(union_set(i, j, k)) {
            mst.pb(l);
            min1 += k;
        }
    }

    ll min2 = 1e18;

    for(auto i : mst) {
        ll min3 = 0;  
        cnt = 0;

        for(ll i = 1; i <= n; i ++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for(ll j = 0; j < m; j ++) {
            if(i == j) continue;

            auto &[x, y, z] = a[j];
            if(union_set(x, y, z)) {
                min3 += z;
                cnt ++;
            }
        }

        if(cnt == n - 1) min2 = min(min2, min3);
    }

    cout << min1 << ' ' << min2;
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