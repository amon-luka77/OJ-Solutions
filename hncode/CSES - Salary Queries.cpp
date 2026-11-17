#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e6;
ll n, q, a[N + 1];
vector<ll> b;

struct KK {
    char x; ll y, z;
};

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void xoa(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] -= val;
            return;
        }

        ll mid = (l + r) >> 1;

        xoa(id * 2, l, mid, i, val);
        xoa(id * 2 + 1, mid + 1, r, i, val);

        node[id] = node[id * 2] + node[id * 2 + 1];

    }

    void them(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] += val;
            return;
        }

        ll mid = (l + r) >> 1;

        them(id * 2, l, mid, i, val);
        them(id * 2 + 1, mid + 1, r, i, val);

        node[id] = node[id * 2] + node[id * 2 + 1];

    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

ll binary(ll k) {
    ll l = 1, r = b.size() - 1, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] >= k) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}
void read() {
    cin >> n >> q;
    b.pb(0);
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }
}
void solve() {
    vector<KK> query;
    vector<pair<ll, ll>> change;

    while(q --) {
        char x; ll l, r;
        cin >> x >> l >> r;
        if(x == '!') {
            b.pb(r);
        } else {
            b.pb(l);
            b.pb(r);
        }
        query.pb({x, l, r});
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    ll k = b.size();
    SegmentTree node(k);

    for(ll i = 1; i <= n; i ++) {
        a[i] = binary(a[i]);
        node.them(1, 1, k, a[i], 1);
    }

    for(auto i : query) {
        if(i.x == '!') {
            ll t = binary(i.z);
            node.xoa(1, 1, k, a[i.y], 1);
            node.them(1, 1, k, t, 1);
            a[i.y] = t;
        } else {
            cout << node.get(1, 1, k, binary(i.y), binary(i.z)) << el;
        }
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