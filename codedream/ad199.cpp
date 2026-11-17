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
const ll N = 100, maxn = N * N;
ll n, m, cnt = 0, sum = 0, a[N + 1][N + 1], parent[maxn + 1], sz[maxn + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
}

ll tinh(ll i, ll j) {
    return (i - 1) * m  + j;
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v, ll t) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
        cnt += (t != 0);
        sum += t;  
    }
}

void solve() {
    for(ll i = 1; i <= n * m ; i ++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(a[i][j] == 0) {
                ll value = 1;
                for(auto &[k, l] : d) {
                    ll rx = i + k;
                    ll ry = j + l;
                    value = (value + 1) % 2;
                    if(rx < 1 || rx > n || ry < 1 || ry > m) continue;
                    query.pb({tinh(i, j), tinh(rx, ry), value % 2 + 1});
                }
            } else if(a[i][j] == 1) {
                if(i < n) union_set(tinh(i, j), tinh(i + 1, j), 0);
            } else if(a[i][j] == 2) {
                if(j < m) union_set(tinh(i, j), tinh(i, j + 1), 0);
            } else {
                if(i < n) union_set(tinh(i, j), tinh(i + 1, j), 0);
                if(j < m) union_set(tinh(i, j), tinh(i, j + 1), 0);
            }
        }
    }

    sort(all(query), [](QUERY &x, QUERY &y) {
        return x.z < y.z;
    });

    for(auto [i, j, k] : query) {
        union_set(i, j, k);
    }

    cout << cnt << ' ' << sum;
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