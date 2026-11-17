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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5, block = 1800;
ll n, q, cnt = 0, blockId[N + 1], startBlock[N + 1], endBlock[N + 1], a[N + 1];

struct BIT {
    ll n;
    vector<ll> bit;

    void resize(ll _n) {
        n = _n; bit.assign(n + 1, 0);
    }

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getPrefix(ll i) {
        ll res = 0;
        for (; i > 0; i -= i & -i) res += bit[i];
        return res;
    }

    ll getSum(ll l, ll r) {
        if (l > r) return 0;
        return getPrefix(r) - getPrefix(l - 1);
    }
};

BIT bit[100];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) a[i] = i;

    FOR(i, 1, N / block + 1) {
        bit[i].resize(N);
    }

    ll pos = 0, numBlock = 0;
    while(pos < n) {
        numBlock ++;
        startBlock[numBlock] = pos + 1;
        endBlock[numBlock] = min(n, pos + block);
        pos += block;

        FOR(i, startBlock[numBlock], endBlock[numBlock]) {
            bit[numBlock].updated(a[i], 1);
            blockId[i] = numBlock;
        }
    }
}

ll getMin(ll l, ll r, ll val) {
    ll res = 0;
    if(blockId[l] == blockId[r]) {
        FOR(i, l, r) res += (a[i] < val);
        return res;
    }

    FOR(i, l, endBlock[blockId[l]]) res += (a[i] < val);
    FOR(i, startBlock[blockId[r]], r) res += (a[i] < val);
    FOR(i, blockId[l] + 1, blockId[r] - 1) res += bit[i].getSum(1, val - 1);

    return res;
}

ll getMax(ll l, ll r, ll val) {
    ll res = 0;
    if(blockId[l] == blockId[r]) {
        FOR(i, l, r) res += (a[i] > val);
        return res;
    }

    FOR(i, l, endBlock[blockId[l]]) res += (a[i] > val);
    FOR(i, startBlock[blockId[r]], r) res += (a[i] > val);
    FOR(i, blockId[l] + 1, blockId[r] - 1) res += bit[i].getSum(val + 1, N);

    return res;
}

void updatedQuery(ll u, ll v) {
    if(u == v) return; if(u > v) swap(u, v);
    cnt -= getMin(u + 1, v - 1, a[u]);
    cnt -= getMax(u + 1, v - 1, a[v]);
    cnt += getMax(u + 1, v - 1, a[u]);
    cnt += getMin(u + 1, v - 1, a[v]);
    cnt += (a[v] > a[u]); cnt -= (a[u] > a[v]);

    ll x = a[u], y = a[v];
    a[u] = y, a[v] = x;

    bit[blockId[u]].updated(x, -1);
    bit[blockId[u]].updated(y, 1);
    bit[blockId[v]].updated(y, -1);
    bit[blockId[v]].updated(x, 1);
}

void solve() {
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        updatedQuery(x, y);
        // FOR(i, 1, n) cout << a[i] << ' ';
        cout << cnt << el;
    }
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