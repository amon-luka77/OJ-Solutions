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
ll n, m, parent[N + 1], vs[N + 1];
vector<ll> sz[N + 1];
pair<ll, ll> a[N + 1];
vector<pair<ll, ll>> query;

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i].ft >> a[i].sc;
    }
    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        query.pb({x, (y == 1) * a[x].ft + (y == 2) * a[x].sc});
        if(y == 1) a[x].ft = -1;
        else a[x].sc = -1;
    }
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
        sz[i].pb(i);
        vs[i] = -2;
    }
    vs[1] = -1;
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void real_time(ll u, ll time) {
    for(auto i : sz[u]) {
        if(vs[i] == -2) {
            vs[i] = time;
        }
    }
}

void union_set(ll u, ll v, ll time) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        ll k = find_set(1);

        if(x == k) real_time(y, time);
        else if(y == k) real_time(x, time);

        if(sz[x].size() < sz[y].size()) swap(x, y);

        for(auto i : sz[y]) {
            sz[x].pb(i);
        }

        sz[y].clear();
        parent[y] = x;
    }
}



void solve() {
    make_set();

    for(ll i = 1; i <= n; i ++) {
        if(a[i].ft != -1) union_set(i, a[i].ft, -1);
        if(a[i].sc != -1) union_set(i, a[i].sc, -1);
    }

    for(ll i = query.size() - 1; i >= 0; i --) {
        auto [x, y] = query[i];
        union_set(x, y, i);
    }
}
void write() {
    for(ll i = 1; i <= n; i ++) {
        cout << vs[i] << el;
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}