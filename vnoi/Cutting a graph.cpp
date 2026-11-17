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
const ll N = 5e4;
ll n, m, k, parent[N + 1], sz[N + 1];
vector<tuple<ll, ll, bool>> edge;
vector<tuple<string, ll, ll>> query;
map<pair<ll, ll>, ll> ts;

void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i ++) {
        ll x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        edge.pb({x, y, 1});
        ts[{x, y}] = edge.size() - 1;
    }
    for(ll i = 1; i <= k; i ++) {
        string s; ll x, y; cin >> s >> x >> y;
        if(x > y) swap(x, y);
        if(s == "cut") {
            get<2> (edge[ts[{x, y}]]) = 0;
        }

        query.pb({s, x, y});
    }
}

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

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        sz[x] += sz[y];
        parent[y] = x; 
    }
}

string check_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);
    if(x != y) return "NO";
    else return "YES";
}

void solve() {
    make_set();

    for(auto [x, y, z] : edge) {
        if(z) union_set(x, y);
    }

    vector<string> ans;

    for(ll i = query.size() - 1; i >= 0; i --) {
        auto [s, x, y] = query[i];
        if(s == "ask") {
            ans.pb(check_set(x, y));
        } else {
            union_set(x, y);
        }
    }

    for(ll i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i] << el;
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