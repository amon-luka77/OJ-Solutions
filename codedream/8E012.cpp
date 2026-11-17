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
#define NAME "8E012"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 5e5;
ll n, q, a[N + 1];
vector<ll> pos[5];
vector<long long> prefix[5];

void read() {
    cin >> n >> q;
    FOR(i, 0, 4) prefix[i].pb(0);
    FOR(i, 1, n) {
        cin >> a[i];
        pos[i % 5].pb(i); prefix[i % 5].pb(prefix[i % 5].back() + a[i]);
    }
}

struct Segtree {
    struct NODE {long long val; ll lazy, minLazy;};
    ll idx;

    vector<NODE> node;
    void resize(ll _n, ll _idx) {node.assign(4 * _n + 1, NODE{0, 0, 0}); idx = _idx;}

    void build(ll id, ll l, ll r) {
        if(l == r) return node[id].val = a[pos[idx][l]], void();
        ll mid = (l + r) >> 1; build(id << 1, l, mid), build(id << 1 | 1, mid + 1, r);
        merge(id);
    }

    void merge(ll id) {
        node[id].minLazy = min(node[id << 1].minLazy, node[id << 1 | 1].minLazy);
        node[id].val = 0;
        if(node[id].minLazy == node[id << 1].minLazy) node[id].val += node[id << 1].val;
        if(node[id].minLazy == node[id << 1 | 1].minLazy) node[id].val += node[id << 1 | 1].val;
    }

    void updatedNode(ll id, ll v) {
        node[id].lazy += v; node[id].minLazy += v;
    }

    void push(ll id) {
        ll &k = node[id].lazy; if(!k) return;
        updatedNode(id << 1, k); updatedNode(id << 1 | 1, k);
        k = 0;
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > r || i > j) return;
        if(l == i && r == j) {updatedNode(id, val); return;}

        ll mid = (l + r) >> 1; push(id);
        if(j <= mid) updated(id << 1, l, mid, i, j, val);
        else if(i > mid) updated(id << 1 | 1, mid + 1, r, i, j, val);
        else updated(id << 1, l, mid, i, mid, val), updated(id << 1 | 1, mid + 1, r, mid + 1, j, val);
        merge(id);
    }

    long long getSum(ll id, ll l, ll r, ll i, ll j) {
        if(l > r || i > j) return 0;
        if(l == i && r == j) return (node[id].minLazy <= 0 ? node[id].val : 0);
        ll mid = (l + r) >> 1; push(id);
        if(j <= mid) return getSum(id << 1, l, mid, i, j);
        else if(i > mid) return getSum(id << 1 | 1, mid + 1, r, i, j);
        else return getSum(id << 1, l, mid, i, mid) + getSum(id << 1 | 1, mid + 1, r, mid + 1, j);
    }
};

Segtree st[5];

ll getL(ll i, ll idx) {return (idx <= pos[i][0] ? 0 : (idx - pos[i][0] + 4) / 5);}
ll getR(ll i, ll idx) {return (idx < pos[i][0] ? -1 : (idx - pos[i][0]) / 5);}

ll posSize[5];

void updated(ll val) {
    ll x, y; cin >> x >> y;


    ll L = lower_bound(all(pos[x % 5]), x) - pos[x % 5].begin();
    ll R = upper_bound(all(pos[x % 5]), y) - pos[x % 5].begin() - 1;
    if(L <= R) st[x % 5].updated(1, 0, posSize[x % 5] - 1, L, R, val);

    L = lower_bound(all(pos[(x + 2) % 5]), x) - pos[(x + 2) % 5].begin();
    R = upper_bound(all(pos[(x + 2) % 5]), y) - pos[(x + 2) % 5].begin() - 1;
    if(L <= R) st[(x + 2) % 5].updated(1, 0, posSize[(x + 2) % 5] - 1, L, R, val);
}

void getAns() {
    ll l, r; cin >> l >> r;
    long long res = 0;

    FOR(i, 0, 4) {
        ll L = lower_bound(all(pos[i]), l) - pos[i].begin();
        ll R = upper_bound(all(pos[i]), r) - pos[i].begin() - 1;
        if(L <= R) res += (prefix[i][R + 1] - prefix[i][L]) - st[i].getSum(1, 0, posSize[i] - 1, L, R);
    } cout << res << el;
}

void solve() {
    FOR(i, 0, 4) {
        posSize[i] = pos[i].size();
        st[i].resize(posSize[i], i);
        st[i].build(1, 0, posSize[i] - 1);
    }

    while(q --) {
        char opt; cin >> opt;
        if(opt == '+') updated(1);
        else if(opt == '-') updated(-1);
        else getAns();
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
