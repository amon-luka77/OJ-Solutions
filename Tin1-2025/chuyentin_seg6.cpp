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
ll n, m;
struct NODE1 {
    ll fi, se, wi;
};
struct NODE {
    ll val, lazy;
};
vector<NODE1> a;
bool cmp1(NODE1 x, NODE1 y) {
    return x.wi < y.wi; 
};
struct SegmentTree {
    vector<NODE> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }

    void push(ll id, ll l, ll r) {
        if(node[id].lazy == 0) return;
        ll k = node[id].lazy; node[id].lazy = 0;

        node[id * 2].val += k;
        node[id * 2].lazy += k;
        node[id * 2 + 1].val += k;
        node[id * 2 + 1].lazy += k;
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            node[id].val += val;
            node[id].lazy += val;
            return;
        }

        push(id, l, r);
        
        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, j, val);
        updated(id * 2 + 1, mid + 1, r, i, j, val);

        node[id].val = min(node[id * 2].val, node[id * 2 + 1].val);
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 1e18;
        if(i <= l && r <= j) return node[id].val;

        push(id, l, r);

        ll mid = (l + r) >> 1;
        return min(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
    }
};
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        ll x, y, w; cin >> x >> y >> w;
        a.pb({x, y, w});
    }
    sort(a.begin(), a.end(), cmp1);
}
void solve() {
    ll l = 0, ans = 1e18;
    SegmentTree node(m);
    for(ll r = 0; r < n; r ++) {
        node.updated(1, 1, m, a[r].fi, a[r].se - 1, 1);
        while(l <= r && node.get(1, 1, m, 1, m - 1) >= 1) {
            ans = min(ans, a[r].wi - a[l].wi);
            node.updated(1, 1, m, a[l].fi, a[l].se - 1, -1);
            l ++;
        }
    }
    cout << ans;
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