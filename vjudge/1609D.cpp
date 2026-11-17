/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e3;
ll n, d;

void read() {
    cin >> n >> d;
}

ll res = 0, parent[N + 1], sz[N + 1]; set<pair<ll, ll>> b;
ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(u, v);
        b.erase(b.find({sz[y], y})); b.erase(b.find({sz[x], x})); 
        parent[y] = x; sz[x] += sz[y];
        b.insert({sz[x], x});
    } else res ++;
}

inline void cal() {
    auto it = b.end(); it = prev(it); if(!res) return cout << it->ft - 1 << el, void();
    ll ans = 0;
    FOR(i, 0, res) {
        ans += it->ft;
        if(it == b.begin()) return cout << ans - 1 << el, void();
        it = prev(it);
    }

    // cerr << "so lan duoc chon"
    // for(auto &[i, j] : b) cerr << "[" << i << ", " << j << "]; ";

    cout << ans - 1 << el;
}

void solve() {
    FOR(i, 1, n) {parent[i] = i; sz[i] = 1; b.insert({sz[i], i});}
    FOR(i, 1, d) {ll x, y; cin >> x >> y; union_set(x, y); cal();}
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}