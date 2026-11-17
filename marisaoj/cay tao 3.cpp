/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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
const ll maxNode = 20 * N;
ll n, q, a[N + 1], L[N + 1], R[N + 1], ans[N + 1];
struct QUERY{ll l, r, x, a;};
QUERY query[N + 1]; vector<ll> bucket[N + 1], lastPos[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) {
        cin >> query[i].l >> query[i].r >> query[i].x >> query[i].a; 
        lastPos[query[i].x - 1].pb(i);
        L[i] = 1; R[i] = n; ans[i] = -1;
    }
}

struct FenwickTree {
    ll bit[N + 1];

    void updated(ll i, ll val) {
        for(; i <= N; i += i & -i) bit[i] += val;
    }

    ll getSum(ll l, ll r) {
        ll res = 0; l --;
        for(; l; l -= l & -l) res -= bit[l];
        for(; r; r -= r & -r) res += bit[r];
        return res;
    }
};

FenwickTree bit;

void parallelBinarySearch() {
    // cerr << "strart\n";
    while(1) {
        bool ok = 0;
        FOR(i, 1, q) bucket[i].clear();
        FOR(i, 1, q) if(L[i] <= R[i]) {
            ok = 1; ll mid = (L[i] + R[i]) >> 1; bucket[mid].pb(i);
        } if(!ok) break;

        memset(bit.bit, 0, sizeof bit.bit);

        FOR(i, 1, n) {
            bit.updated(a[i], 1);
            for(auto id : bucket[i]) {
                auto [l, r, x, need] = query[id];
                if(bit.getSum(l, r) >= need) {
                    ans[id] = i; R[id] = i - 1;
                } else L[id] = i + 1;
            }
        }
    }
    // cerr << "end\n";
}

void solve() {
    // cerr << "1\n";
    // node.build();
    // cerr << "2\n";
    FOR(i, 1, n) {
        bit.updated(a[i], 1);
        for(auto i : lastPos[i]) {
            query[i].a += bit.getSum(query[i].l, query[i].r);
        }
    }
    FOR(i, 1, n) bit.updated(a[i], -1);
    parallelBinarySearch();
    
    FOR(i, 1, q) cout << ans[i] << ' ';
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