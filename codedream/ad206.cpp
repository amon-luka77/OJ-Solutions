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
ll n, m, parent[N + 1], sz[N + 1];
double d = 0;
pair<ll, ll> a[N + 1];

struct KK {
    ll x, y; double z;
};

vector<KK> b;

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v, double dis) {
    ll rx = find_set(u);
    ll ry = find_set(v);

    if(rx != ry) {
        if(sz[rx] < sz[ry]) swap(rx, ry);

        parent[ry] = rx;
        sz[rx] += sz[ry];

        d += dis;
    }
} 

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i].ft >> a[i].sc;
    }

    cin >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        union_set(x, y, 0);
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = i + 1; j <= n; j ++) {
            double kc = sqrt((a[i].ft - a[j].ft) * (a[i].ft - a[j].ft) 
                                + (a[i].sc - a[j].sc) * (a[i].sc - a[j].sc));
            b.pb({i, j, kc});
        }
    }
}

void solve() {
    sort(all(b), [](KK &x, KK &y) {
        return x.z < y.z;
    });

    for(auto [i, j, k] : b) {
        union_set(i, j, k);
    }

    cout << fixed << setprecision(5) << d;
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