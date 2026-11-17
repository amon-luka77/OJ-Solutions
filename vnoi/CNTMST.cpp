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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5, mod = 998244353;
ll n, m, parent[N + 1], sz[N + 1], tempPar[N + 1], tempSz[N + 1];
set<ll> c;

struct CANH {
    ll x, y, z;
};

vector<CANH> canh;

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        canh.pb({x, y, z});
    }

    sort(all(canh), [](const CANH &x, const CANH &y) {
        return x.z < y.z;
    });

    FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}
}

ll find_set(ll k, ll parent[], ll sz[]) {
    return parent[k] == k ? k : parent[k] = find_set(parent[k], parent, sz);
}

bool check(ll u, ll v, ll parent[], ll sz[]) {
    return find_set(u, parent, sz) != find_set(v, parent, sz);
}

bool union_set(ll u, ll v, ll parent[], ll sz[]) {
    ll x = find_set(u, parent, sz), y = find_set(v, parent, sz);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return 1;
    }

    return 0;
}

vector<pair<ll, ll>> b;

ll cal() {
    ll sizeMask = b.size(), cnt = 0;
    ll need = 0;
    for(auto k : c) {tempPar[k] = k; tempSz[k] = 1;}
    for(auto &[i, j] : b) {
        need += (union_set(i, j, tempPar, tempSz));
    }

    FOR(mask, 0, MASK(sizeMask) - 1) {
        for(auto k : c) {tempPar[k] = k; tempSz[k] = 1;}
        bool ok = 1; ll sl = 0;
        for(ll i = mask; i; i ^= (i & -i)) {
            ll pos = __lg(i & -i);
            if(!union_set(b[pos].ft, b[pos].sc, tempPar, tempSz)) ok = 0;
            else sl ++;
        }

        cnt += (ok && sl == need);
    }

    return cnt;
}

void solve() {
    ll res = 1;

    FOR(i, 0, m - 1) {
        ll j = i, cnt = 0;
        while(j <= m - 1 && canh[i].z == canh[j].z) {
            ll x = find_set(canh[j].x, parent, sz), y = find_set(canh[j].y, parent, sz);
            
            if(x != y) {
                b.pb({x, y});
                c.insert(x);
                c.insert(y);
            }

            j ++;
        }

        ll x = cal();
        if(x > 0) {res *= x; res %= mod;}

        FOR(k, i, j - 1) union_set(canh[k].x, canh[k].y, parent, sz);
        for(auto k : c) {tempPar[k] = k; tempSz[k] = 1;}
        c.clear(); b.clear();

        i = j - 1;
    }

    cout << res;
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