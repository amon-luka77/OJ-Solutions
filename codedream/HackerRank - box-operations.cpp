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
ll n, q;

ll a[N + 1];

struct Segtree {
    struct NODE {
        ll sum, minVal, maxVal, lazy;
    };

    NODE node[(N << 2) + 1];
    const ll MAX_VAL = 1e18;

    #define ls id << 1
    #define rs id << 1 | 1

    void pushUp(ll id) {
        node[id].sum = node[ls].sum + node[rs].sum;
        node[id].maxVal = max(node[ls].maxVal, node[rs].maxVal);
        node[id].minVal = min(node[ls].minVal, node[rs].minVal);
    }

    void pushDown(ll id, ll l, ll r) {
        if(!node[id].lazy) return;
        ll k = node[id].lazy; node[id].lazy = 0;
        ll mid = (l + r) >> 1;

        node[ls].maxVal += k; node[ls].minVal += k;
        node[ls].sum += k * (mid - l + 1);
        node[ls].lazy += k;

        node[rs].maxVal += k; node[rs].minVal += k;
        node[rs].sum += k * (r - mid);
        node[rs].lazy += k;
    }

    void build(ll id, ll l, ll r) {
        if(l == r) return node[id] = NODE{a[l], a[l], a[l], 0}, void();
        ll mid = (l + r) >> 1;

        build(ls, l, mid), build(rs, mid + 1, r);

        pushUp(id);
    }

    inline ll cal(ll num, ll d) {
        if(num >= 0) return num / d;
        else return -((-num + d - 1) / d);
    }

    void updated_div(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > r || i > j || l > j || r < i) return;
        if(l == i && r == j) {
            ll d1 = node[id].maxVal - cal(node[id].maxVal, val);
            ll d2 = node[id].minVal - cal(node[id].minVal, val);
            if(d1 == d2) {
                node[id].sum -= (r - l + 1) * d1;
                node[id].maxVal -= d1;
                node[id].minVal -= d1;
                node[id].lazy -= d1;
                return;
            }
        }

        ll mid = (l + r) >> 1;
        pushDown(id, l, r);

        if(j <= mid) updated_div(ls, l, mid, i, j, val);
        else if(i > mid) updated_div(rs, mid + 1, r, i, j, val);
        else updated_div(ls, l, mid, i, mid, val), updated_div(rs, mid + 1, r, mid + 1, j, val);

        pushUp(id);
    }

    void updated_add(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > r || i > j || l > j || r < i) return;
        if(l == i && r == j) {
            node[id].sum += val * (r - l + 1);
            node[id].maxVal += val;
            node[id].minVal += val;
            node[id].lazy += val;
            return;
        }

        ll mid = (l + r) >> 1;
        pushDown(id, l, r);

        if(j <= mid) updated_add(ls, l, mid, i, j, val);
        else if(i > mid) updated_add(rs, mid + 1, r, i, j, val);
        else updated_add(ls, l, mid, i, mid, val), updated_add(rs, mid + 1, r, mid + 1, j, val);

        pushUp(id);
    }

    ll getSum(ll id, ll l, ll r, ll i, ll j) {
        if(l > r || i > j || l > j || r < i) return 0;
        if(l == i && r == j) return node[id].sum;

        ll mid = (l + r) >> 1;
        pushDown(id, l, r);

        if(j <= mid) return getSum(ls, l, mid, i, j);
        else if(i > mid) return getSum(rs, mid + 1, r, i, j);
        else return getSum(ls, l, mid, i, mid) + getSum(rs, mid + 1, r, mid + 1, j);
    }

    ll getMin(ll id, ll l, ll r, ll i, ll j) {
        if(l > r || i > j || l > j || r < i) return (ll)1e18;
        if(l == i && r == j) return node[id].minVal;

        ll mid = (l + r) >> 1;
        pushDown(id, l, r);

        if(j <= mid) return getMin(ls, l, mid, i, j);
        else if(i > mid) return getMin(rs, mid + 1, r, i, j);
        else return min(getMin(ls, l, mid, i, mid), getMin(rs, mid + 1, r, mid + 1, j));
    }

    void printNum(ll id, ll l, ll r) {
        if(l == r) {cout << node[id].maxVal << ' '; return;}
        ll mid = (l + r) >> 1; pushDown(id, l, r);
        printNum(ls, l, mid); printNum(rs, mid + 1, r);
    }
} node;

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    node.build(1, 1, n);

}

void solve() {
    while(q --) {
        ll opt, l, r, x; cin >> opt;

        if(opt == 1) {
            cin >> l >> r >> x; l ++; r ++;
            node.updated_add(1, 1, n, l, r, x);
        } else if(opt == 2) {
            cin >> l >> r >> x; l ++; r ++;
            node.updated_div(1, 1, n, l, r, x);
        } else if(opt == 3) {
            cin >> l >> r; l ++; r ++;
            cout << node.getMin(1, 1, n, l, r) << el;
        } else {
            cin >> l >> r; l ++; r ++;
            cout << node.getSum(1, 1, n, l, r) << el;
        }

//        cout << el;
//        node.printNum(1, 1, n);
//        cout << el;
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
