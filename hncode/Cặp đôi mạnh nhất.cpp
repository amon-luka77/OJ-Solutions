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
const ll N = 2e5;
ll n, q, a[N + 1];

struct SegmentTree {
    vector<pair<ll, ll>> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {-1e18, -1e18});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id].ft = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        vector<ll> k;
        k.pb(node[id * 2].ft);
        k.pb(node[id * 2].sc);
        k.pb(node[id * 2 + 1].ft);
        k.pb(node[id * 2 + 1].sc);
        sort(all(k));

        node[id].ft = k[3];
        node[id].sc = k[2];
    }

    pair<ll, ll> get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return {(ll)-1e18, (ll)-1e18};
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        auto get1 = get(id * 2, l, mid, i, j);
        auto get2 = get(id * 2 + 1, mid + 1, r, i, j);

        vector<ll> k;
        k.pb(get1.ft);
        k.pb(get1.sc);
        k.pb(get2.ft);
        k.pb(get2.sc);
        sort(all(k));

        return {k[3], k[2]};
    }

    ll find_num(ll id, ll l, ll r, ll i) {
        if(l == r) return node[id].ft;

        ll mid = (l + r) >> 1;

        if(mid >= i) return find_num(id * 2, l, mid, i);
        return find_num(id * 2 + 1, mid + 1, r, i);
    }
};

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    cin >> q;
    while(q --) {
        ll l, r; cin >> l >> r;
        if(l == r) {
            cout << node.find_num(1, 1, n, l) << el;
        } else {
            auto k = node.get(1, 1, n, l, r);
            cout << k.ft + k.sc << el;
        }
    }
}
void write() {

}
int main() {
    boost;
    file("cdmn");
    read();
    solve();
    write();
    return 0;
}
