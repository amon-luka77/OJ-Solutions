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
const ll N = 4e4;
ll t;

struct SegmentTree {
    struct NODE {
        ll val, lazy;
    };

    vector<NODE> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }

    void push(ll id, ll l, ll r) {
        if(l == r) return;
        if(node[id].lazy == 0) return;
        ll k = node[id].lazy; node[id].lazy = 0;

        node[id * 2].val = k;
        node[id * 2].lazy = k;
        node[id * 2 + 1].val = k;
        node[id * 2 + 1].lazy = k;

        return;
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            node[id].val = val;
            node[id].lazy = val;
            return;
        }

        push(id, l, r);

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, j, val);
        updated(id * 2 + 1, mid + 1, r, i, j, val);

        if(node[id * 2].val == node[id * 2 + 1].val) node[id].val = node[id * 2].val;
        else node[id].val = -1;
    }

    ll get(ll id, ll l, ll r, vector<bool> &k) {
        push(id, l, r);
        if(node[id].val != -1) {
            bool ans = !(k[node[id].val]);
            k[node[id].val] = 1;
            return ans;
        }

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, k) + get(id * 2 + 1, mid + 1, r, k);
    }

};

ll binary(ll tg, const vector<ll> &b) {
    ll l = 1, r = b.size() - 1, ans = 0;

    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] >= tg) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

void read() {
    cin >> t;
}
void solve() {
    while(t --) {
        ll n; cin >> n;
        vector<pair<ll, ll>> a(n + 1, {0, 0});
        vector<ll> b;

        b.pb(0);

        for(ll i = 1; i <= n; i ++) {
            cin >> a[i].ft >> a[i].sc;
            b.pb(a[i].ft);
            b.pb(a[i].sc);
        }

        sort(b.begin() + 1, b.end());
        b.erase(unique(b.begin() + 1, b.end()), b.end());

        for(ll i = 1; i <= n; i ++) {
            a[i].ft = binary(a[i].ft, b);
            a[i].sc = binary(a[i].sc, b);
        }

        ll m = b.size() - 1;
        SegmentTree node(m);
        vector<bool> k(m + 1, 0);

        for(ll i = 1; i <= n; i ++) {
            node.updated(1, 1, m, a[i].ft, a[i].sc, i);
        }

        cout << node.get(1, 1, m, k) << el;
        // node.print(1, 1, m);
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