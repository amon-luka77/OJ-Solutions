#include<bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el "\n"
#define pb push_back
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, q, a[N + 1];

struct Segtree {
    struct NODE {
        ll pref, valLeft;
        ll suf, valRight;
        ll len, maxLen;
    }; NODE node[4 * N + 1];

    NODE merge (const NODE &x, const NODE &y) {
        NODE res;

        // phai la tang
        // trai la giam

        res.pref = max(x.pref, (x.pref == x.len && x.valRight - 1 == y.valLeft) * (x.pref + y.pref));
        res.valLeft = x.valLeft;

        res.suf = max(y.suf, (y.suf == y.len && x.valRight + 1 == y.valLeft) * (x.suf + y.suf));
        res.valRight = y.valRight;

        res.len = x.len + y.len;
        res.maxLen = max(x.maxLen, y.maxLen);
        // 4567 6543
        // 4567 87654
        if(x.valRight + 1 == y.valLeft) res.maxLen = max(res.maxLen, 1 + 2 * min(x.suf, y.pref - 1));
        if(x.valRight - 1 == y.valLeft) res.maxLen = max(res.maxLen, 1 + 2 * min(x.suf - 1, y.pref));

        return res;
    }

    void build(ll id, ll l, ll r) {
        if(l == r) return node[id] = {1, a[l], 1, a[l], 1, 1}, void();
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid); build(id << 1 | 1, mid + 1, r);
        node[id] = merge(node[id << 1], node[id << 1 | 1]);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l == r) return node[id] = {1, val, 1, val, 1, 1}, void();
        ll mid = (l + r) >> 1;
        if(i <= mid) updated(id << 1, l, mid, i, val);
        else updated(id << 1 | 1, mid + 1, r, i, val);
        node[id] = merge(node[id << 1], node[id << 1 | 1]);
    }
} st;

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    st.build(1, 1, n);
}

void solve() {
    cin >> q; cout << st.node[1].maxLen << el;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        st.updated(1, 1, n, x, y);
        cout << st.node[1].maxLen << el;
    }
}

void write() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
//    file();
    read();
    solve();
    write();
    return 0;
}
