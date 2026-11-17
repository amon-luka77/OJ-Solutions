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
ll n, m, parent[N + 1], sz[N + 1], dis = 0, sl = 0;

struct NODE {
    ll x, y, z;
};

vector<NODE> a;

bool cmp(NODE x, NODE y) {
    return x.z < y.z;
};

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

void union_sets(ll u, ll v, ll k) {
    ll x = find_set(u);
    ll y = find_set(v);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        parent[y] = x;
        dis += k;
        sl ++;
    }
}

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        a.pb({x, y, z});
    }
}
void solve() {
    sort(all(a), cmp);
    make_set();
    for(ll i = 0; i < m; i ++) {
        auto [x, y, z] = a[i];
        union_sets(x, y, z);
    }
}
void write() {
    cout << sl << ' ' << dis;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}