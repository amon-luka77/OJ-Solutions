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
const ll N = 1e4;
ll n, m, cnt = 0, ans = 1e18;
ll parent[N + 1], sz[N + 1];

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

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

bool union_set(ll u, ll v, ll k) {
    ll x = find_set(u);
    ll y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);

        parent[y] = x;
        sz[x] += sz[y];
        return true;
    } else {
        return false;
    }
}

void solve() {
    
    for(ll i = 0; i < edge.size(); i ++) {

        for(ll j = 1; j <= n; j ++) {
            parent[j] = j;
            sz[j] = 1;
        }

        ll cnt = 0;

        for(ll j = i; j < edge.size(); j ++) {
            if(union_set(edge[j].x, edge[j].y, edge[j].z)) {
                cnt ++;
            }
            if(cnt == n - 1) {
                ans = min(ans, edge[j].z - edge[i].z);
                break;
            }
        }

    }

    if(ans != 1e18) cout << ans;
    else cout << "NOT FOUND";
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