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
ll n, q, a[N + 1], bit[N + 1], L[N + 1], R[N + 1], ans[N + 1];
vector<ll> bucket[N + 1];

void updated(ll i, ll val) {
    for(; i <= n; i += i & -i) bit[i] += val;
}

ll get(ll i) {
    ll res = 0;
    for(; i > 0; i -= i & -i) res += bit[i];
    return res;
}

struct QUERY {ll l, r, w;};
QUERY query[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {cin >> a[i]; L[i] = 1; R[i] = q; ans[i] = -1;}
    FOR(i, 1, q) cin >> query[i].l >> query[i].r >> query[i].w;
    cerr << -1;
}

void solve() {
    // cerr << "begin\n";
    while(1) {
        bool ok = 0;
        FOR(i, 1, q) bucket[i].clear();
        FOR(i, 1, n) if(L[i] <= R[i]) {
            ok = 1;
            ll mid = (L[i] + R[i]) >> 1;
            bucket[mid].pb(i);
        }

        if(!ok) break;
        memset(bit, 0, sizeof bit);

        FOR(i, 1, q) {
            updated(query[i].l, query[i].w);
            if(query[i].r < n) updated(query[i].r + 1, -query[i].w);
            for(auto id : bucket[i]) {
                if(get(id) >= a[id]) {
                    ans[id] = i;
                    R[id] = i - 1;
                } else L[id] = i + 1;
            }
        }
    }
// cerr << "end\n";
    FOR(i, 1, n) cout << ans[i] << ' ';
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