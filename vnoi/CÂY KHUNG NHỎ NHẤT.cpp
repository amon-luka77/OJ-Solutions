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
ll n, m, parent[N + 1], totalPoints = 0;

struct NODE {
    ll x, y, z;
};

vector<NODE> edge;

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        edge.pb({x, y, z});
    }

    sort(all(edge), [](NODE &x, NODE &y) {
        return x.z < y.z;
    });  
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v, ll k) {
    u = find_set(u), v = find_set(v);
    if(u != v) {
        parent[u] = v;
        totalPoints += k;
    }
}

void solve() {
    make_set();
    
    for(auto [x, y, z] : edge) {
        union_set(x, y, z);
    }
}
void write() {
    cout << totalPoints;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}