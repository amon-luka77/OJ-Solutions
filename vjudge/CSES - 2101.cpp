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

const ll N = 2e5;
ll n, m, q;
ll L[N + 1], R[N + 1], ans[N + 1];
ll parent[N + 1], sz[N + 1];
pair<ll, ll> canh[N + 1], query[N + 1];
vector<ll> bucket[N + 1];

void read() {
    cin >> n >> m >> q;
    FOR(i, 1, m) cin >> canh[i].ft >> canh[i].sc;
    FOR(i, 1, q) {
        cin >> query[i].ft >> query[i].sc;
        L[i] = 1, R[i] = m, ans[i] = -1;
        if(query[i].ft == query[i].sc) {R[i] = 0; ans[i] = 0;}
    }
}

ll find_set(ll k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

void union_set(ll u, ll v) {
    ll x = find_set(u), y = find_set(v);
    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x; sz[x] += sz[y];
    }
}

void parallelBinarySearch() {
    while(1) {
        bool ok = 0;
        FOR(i, 1, m) bucket[i].clear();
        FOR(i, 1, q) if(L[i] <= R[i]) {
            ll mid = (L[i] + R[i]) >> 1;
            ok = 1; bucket[mid].pb(i);
        } if(!ok) break;

        FOR(i, 1, n) {parent[i] = i; sz[i] = 1;}

        FOR(i, 1, m) {
            union_set(canh[i].ft, canh[i].sc);
            for(auto id : bucket[i]) {
                if(find_set(query[id].ft) == find_set(query[id].sc)) {
                    ans[id] = i; R[id] = i - 1;
                }  else L[id] = i + 1;
            }
        }
    }
}

void solve() {
    parallelBinarySearch();
    FOR(i, 1, q) cout << ans[i] << el;
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