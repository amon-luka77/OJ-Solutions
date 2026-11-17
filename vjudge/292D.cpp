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

const ll N = 500;
ll n, m, q;

struct Dsu {
    int cntUnion, sz[N + 1], parent[N + 1];

    Dsu() {
        FOR(i, 1, N) {parent[i] = i; sz[i] = 1;}
    }

    ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

    void union_set(ll u, ll v) {
        ll x = find_set(u), y = find_set(v);
        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            parent[y] = x; sz[x] += sz[y]; cntUnion ++;
        }
    }
} dsuLeft[(ll)2e4 + 1], dsuRight[(ll)2e4 + 1];

pair<ll, ll> canh[(ll)2e4 + 1];
void read() {
    cin >> n >> m;
    FOR(i, 1, m) cin >> canh[i].ft >> canh[i].sc;
}

void solve() {
    FOR(i, 1, m) {if(i > 1) dsuLeft[i] = dsuLeft[i - 1]; dsuLeft[i].union_set(canh[i].ft, canh[i].sc);}
    FORD(i, m, 1) {if(i < m) dsuRight[i] = dsuRight[i + 1]; dsuRight[i].union_set(canh[i].ft, canh[i].sc);}
    
    cin >> q;
    FOR(i, 1, q) {
        int x, y; cin >> x >> y;
        Dsu tmp = dsuLeft[x - 1];
        FOR(i, 1, n) tmp.union_set(dsuLeft[x - 1].parent[i], dsuRight[y + 1].parent[i]);
        cout << n - tmp.cntUnion << el;
    }
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