#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 0;
ll n, m;

unordered_map<ll, ll> parent, sz, deg;

ll find_set(ll k) {
    if(parent.find(k) == parent.end()) {
        parent[k] = k;
        sz[k] = 1;

        return k;
    }

    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void read() {
    while(cin >> n >> m) {
        if(n == 0 && m == 0) exit(0);
        set<pair<ll, ll>> st;

        parent.clear();
        sz.clear();
        deg.clear();
        bool ok = 1;

        FOR(i, 1, m) {
            ll x, y; cin >> x >> y;
            if(!ok) continue;

            if(st.find({min(x, y), max(x, y)})== st.end()) {
                deg[x] ++;
                deg[y] ++;

                if(deg[x] > 2 || deg[y] > 2) {
                    ok = 0;
                    continue;
                }                 
            } else {
                continue;
            }

            st.insert({min(x, y), max(x, y)});
 
            ll a = find_set(x), b = find_set(y);

            if(a == b && sz[a] != n) {
                ok = 0;
                continue;
            }

            if(a != b) {
                if(sz[a] < sz[b]) swap(a, b);
                parent[b] = a;
                sz[a] += sz[b];              
            }

        }

        if(ok) cout << "Y" << el;
        else cout << "N" << el;
    }
}

void solve() {

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