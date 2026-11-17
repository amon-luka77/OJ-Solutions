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

const ll N = 1e5;
ll n, parent[N + 1], sz[N + 1];

struct CANH {
    ll x, y, z, id;
};

vector<CANH> canh;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y, z; cin >> x >> y >> z;
        canh.pb({x, y, z, i});
    }

    FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}
}

ll find_set(ll k) {
    return k == parent[k] ? k : parent[k] = find_set(parent[k]);
}

bool union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x;
        sz[x] += sz[y];
        return 1;
    }
    return 0;
}

struct A {
    ll x, y, z;
};

vector<A> a;

void solve() {
    sort(all(canh), [](const CANH &x, const CANH &y) {
        return x.x < y.x;
    });

    FOR(i, 0, n - 2) {
        a.pb({canh[i].id, canh[i + 1].id, canh[i + 1].x - canh[i].x});
    }

    sort(all(canh), [](const CANH &x, const CANH &y) {
        return x.y < y.y;
    });

    FOR(i, 0, n - 2) {
        a.pb({canh[i].id, canh[i + 1].id, canh[i + 1].y - canh[i].y});
    }

    sort(all(canh), [](const CANH &x, const CANH &y) {
        return x.z < y.z;
    });

    FOR(i, 0, n - 2) {
        a.pb({canh[i].id, canh[i + 1].id, canh[i + 1].z - canh[i].z});
    }

    sort(all(a), [](const A &x, const A &y) {
        return x.z < y.z;
    });

    ll sumEdge = 0;

    for(auto &[i, j, z] : a) {
        if(union_set(i, j)) sumEdge += z;
    }

    cout << sumEdge;
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