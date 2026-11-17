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

const ll N = 1e5;
ll n, m;

struct CANH {ll u, v, w;} canh[N + 1];
void read() {
    cin >> n >> m;
    FOR(i, 1, m) cin >> canh[i].u >> canh[i].v >> canh[i].w;
    sort(canh + 1, canh + m + 1, [](const CANH &x, const CANH &y) {
        return x.w > y.w;
    });
}

const ll mod = 1e9;
ll parent[N + 1], sz[N + 1], res = 0, ans = 0;
ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

inline ll cal(ll x) {return x * (x - 1) / 2;}

void union_set(ll u, ll v, ll w) {
    ll x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(u, v);
        res = (mod + (res - cal(sz[x])) % mod) % mod;
        res = (mod + (res - cal(sz[y])) % mod) % mod;
        res = (res + cal(sz[x] + sz[y])) % mod;
        ans = (ans + res * w % mod) % mod;
        parent[y] = x; sz[x] += sz[y];
    } else ans = (ans + res * w % mod) % mod;
}

void solve() {
    FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}

    FOR(i, 1, m) {auto [x, y, z] = canh[i]; union_set(x, y, z);}

    cout << ans;
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