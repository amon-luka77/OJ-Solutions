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
const ll block = sqrt(N);
const ll NUM_BLOCK = N / block;

ll n, q, a[N + 1];
ll blockId[N + 1], startBlock[N + 1], endBlock[N + 1], lazyBlock[NUM_BLOCK + 2][N + 1];

struct Segtree {
    ll node[NUM_BLOCK + 2][4 * N + 1];

    void updated(ll Block, ll id, ll l, ll r, ll i, ll val) {
        if(l == r) return node[Block][id] += val, void();
        ll mid = (l + r) >> 1;
        if(i <= mid) updated(Block, id << 1, l, mid, i, val);
        else updated(Block, id << 1 | 1, mid + 1, r, i, val);
        node[Block][id] = node[Block][id << 1] + node[Block][id << 1 | 1];
    }

    ll getCnt(ll Block, ll id, ll l, ll r, ll i) {
        if(l == r) return node[Block][id];
        ll mid = (l + r) >> 1;
        if(i <= mid) return getCnt(Block, id << 1, l, mid, i);
        else return getCnt(Block, id << 1 | 1, mid + 1, r, i);
    }

    ll getSum(ll Block, ll id, ll l, ll r, ll i, ll j) {
        if(l == i && r == j) return node[Block][id];
        ll mid = (l + r) >> 1;
        if(j <= mid) return getSum(Block, id << 1, l, mid, i, j);
        if(i > mid) return getSum(Block, id << 1 | 1, mid + 1, r, i, j);
        return getSum(Block, id << 1, l, mid, i, mid) + getSum(Block, id << 1 | 1, mid + 1, r, mid + 1, j);
    }
} st;

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    ll numBlock = 0, pos = 0;
    while(pos < n) {
        numBlock ++; startBlock[numBlock] = pos + 1;
        endBlock[numBlock] = min(n, pos + block); pos += block;
        FOR(i, startBlock[numBlock], endBlock[numBlock]) {
            st.updated(numBlock, 1, 1, N, a[i], 1); blockId[i] = numBlock;
            lazyBlock[numBlock][a[i]] = a[i];
        }
    }
}

void updatedQuery() {
    ll l, r, x, y; cin >> l >> r >> x >> y;
    if(blockId[l] == blockId[r]) {
        FOR(i, l, r) if(lazyBlock[blockId[l]][a[i]] == x) {
            st.updated(blockId[l], 1, 1, N, lazyBlock[blockId[l]][a[i]], -1); lazyBlock[blockId[l]][a[i]] = y;
            st.updated(blockId[l], 1, 1, N, lazyBlock[blockId[l]][a[i]], 1);
        } return;
    }

    FOR(i, l, endBlock[blockId[l]]) if(lazyBlock[blockId[l]][a[i]] == x) {
        st.updated(blockId[l], 1, 1, N, lazyBlock[blockId[l]][a[i]], -1); lazyBlock[blockId[l]][a[i]] = y;
        st.updated(blockId[l], 1, 1, N, lazyBlock[blockId[l]][a[i]], 1);
    }

    FOR(i, startBlock[blockId[r]], r) if(lazyBlock[blockId[r]][a[i]] == x) {
        st.updated(blockId[r], 1, 1, N, lazyBlock[blockId[r]][a[i]], -1);  lazyBlock[blockId[r]][a[i]] = y;
        st.updated(blockId[r], 1, 1, N, lazyBlock[blockId[r]][a[i]], 1);
    }

    FOR(i, blockId[l] + 1, blockId[r] - 1) {
        lazyBlock[i][x] = y; ll z = st.getCnt(i, 1, 1, N, x);
        if(z == 0) continue;
        st.updated(i, 1, 1, N, x, -z);
        st.updated(i, 1, 1, N, y, z);
    }
}

ll getCount(ll l, ll r, ll x) {
    ll res = 0;
    if(blockId[l] == blockId[r]) {
        FOR(i, l, r) res += (lazyBlock[blockId[l]][a[i]] <= x);
        return res;
    }

    FOR(i, l, endBlock[blockId[l]]) res += (lazyBlock[blockId[l]][a[i]] <= x);

    FOR(i, startBlock[blockId[r]], r) res += (lazyBlock[blockId[r]][a[i]] <= x);

    FOR(i, blockId[l] + 1, blockId[r] - 1) res += st.getSum(i, 1, 1, N, 1, x);

    return res;
}

void getQuery() {
    ll l, r, k; cin >> l >> r >> k;

    ll L = 1, R = N, ans = 0;
    while(L <= R) {
        ll mid = (L + R) >> 1;
        if(getCount(l, r, mid) <= k) {
            L = mid + 1; ans = mid;
        } else R = mid - 1;
    } cout << ans << el;
}

void solve() {
    FOR(i, 1, q) {
        ll opt; cin >> opt;
        if(opt == 1) updatedQuery();
        else getQuery();
    }
}

void write() {

}

int main() {
    boost;
//    file();
    read();
    solve();
    write();
    return 0;
}
