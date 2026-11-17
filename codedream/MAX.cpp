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

const ll N = 5e5;
ll n, m, q;
ll a[N + 1], b[N + 1], s[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, m) cin >> s[i];
    cin >> q;
}

namespace Sub1 {
    bool check() {return 1;}

    ll sumVal[N + 1];
    ll preVal[N + 1];

    void solve() {
        FOR(i, 1, n) sumVal[b[i]] += a[i];
        while(q --) {
            ll opt; cin >> opt;
            if(opt == 1) {
                ll l, r, x; cin >> l >> r >> x;
                FOR(i, l, r) preVal[b[i]] = sumVal[b[i]];
                FOR(i, l, r) if(preVal[b[i]] < s[b[i]]) {
                    a[i] += x; sumVal[b[i]] += x;
                }
            } else {
                ll l, r; cin >> l >> r;
                ll maxVal = a[l], minVal = a[l];
                FOR(i, l, r) {
                    maxVal = max(maxVal, a[i]);
                    minVal = min(minVal, a[i]);
                } cout << maxVal << ' ' << minVal << el;
            }
//            FOR(i, 1, n) cout << a[i] << ' ';
//            cout << el;
        }
    }
}

namespace Sub2 {
    bool check() {
        return m == 1;
    }

    ll minVal[4 * N + 1], maxVal[4 * N + 1];
    ll lazy[4 * N + 1];

    void build(ll id, ll l, ll r) {
        if(l == r) return maxVal[id] = a[l], minVal[id] = a[l], void();
        ll mid = (l + r) >> 1;
        build(id << 1, l, mid); build(id << 1 | 1, mid + 1, r);
        maxVal[id] = max(maxVal[id << 1], maxVal[id << 1 | 1]);
        minVal[id] = min(minVal[id << 1], minVal[id << 1 | 1]);
    }

    void push(ll id) {
        ll &k = lazy[id]; if(!k) return;
        lazy[id << 1] += k; lazy[id << 1 | 1] += k;
        minVal[id << 1] += k; maxVal[id << 1 | 1] += k;
        k = 0;
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll x) {
        if(l == i && r == j) {
            maxVal[id] += x; minVal[id] += x;
            lazy[id] += x; return;
        } ll mid = (l + r) >> 1; push(id);
        if(j <= mid) updated(id << 1, l, mid, i, j, x);
        else if(i > mid) updated(id << 1 | 1, mid + 1, r, i, j, x);
        else updated(id << 1, l, mid, i, mid, x), updated(id << 1 | 1, mid + 1, r, mid + 1, j, x);
        maxVal[id] = max(maxVal[id << 1], maxVal[id << 1 | 1]);
        minVal[id] = min(minVal[id << 1], minVal[id << 1 | 1]);
    }

    pair<ll, ll> get(ll id, ll l, ll r, ll i, ll j) {
        if(l == i && r == j) return make_pair(maxVal[id], minVal[id]);
        ll mid = (l + r) >> 1; push(id);
        if(j <= mid) return get(id << 1, l, mid, i, j);
        else if(i > mid) return get(id << 1 | 1, mid + 1, r, i, j);
        else {
            auto x = get(id << 1, l, mid, i, mid);
            auto y = get(id << 1 | 1, mid + 1, r, mid + 1, j);
            return make_pair(max(x.ft, y.ft), min(x.sc, y.sc));
        }
    }

    void solve() {
        ll limit = s[1], sum = 0; build(1, 1, n);
        FOR(i, 1, n) sum += a[i];
        while(q --) {
            ll opt; cin >> opt;
            if(opt == 1) {
                ll l, r, x; cin >> l >> r >> x;
                if(limit >= sum) continue;
                else {
                    ll cnt = min(r - l + 1, (limit - sum) % x - ((limit - sum) % x == 0));
                    updated(1, 1, n, l, l + cnt - 1, x);
                }
            } else {
                ll l, r; cin >> l >> r;
                auto x = get(1, 1, n, l, r);
                cout << x.ft << ' ' << x.sc << el;
            }
        }
    }
}

void solve() {
    if(Sub2::check()) return Sub2::solve(), void();
    if(Sub1::check()) return Sub1::solve(), void();
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
