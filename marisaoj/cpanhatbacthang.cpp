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
const ll N = 1e5, mod = 1e9 + 7;
ll n, m;
struct st {
    ll val, x, y;
};
struct SegmentTree {
    vector<st> node;

    SegmnetTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }
    
    void push(ll id, ll l, ll r) {
        if(node[id].x == 0 && node[id].y == 0) return 0;
        ll x = node[id].x, y = node[id].y;
        node[id].x = 0, node[id].y = 0;
        ll mid = (l + r) >> 1;

        node[id * 2].val = (node[id * 2].val + (y * (mid - l + 1) % mod + (x * (mid + l) * (mid - l + 1) / 2) % mod ) % mod) % mod;
        node[id * 2 + 1].val = (node[id * 2 + 1].val + (y * (r - mid) % mod + (x * (mid + r + 2) * (r - mid) / 2) % mod ) % mod) % mod;
        node[id * 2].y += y;
        node[id * 2 + 1] += y;
        node[id * 2] += 
    }

    void udpated(ll id, ll l, ll r, ll i, ll j, ll x_start, ll plus_y) {
        if(l > i || r < i) return;
        if(i <= l && r <= j) {
            node[id].val = (node[id].val + (plus_y * (r - l + 1) % mod + (x_start * (r - l + 1) * (r - l) / 2) % mod) % mod) % mod;
            node[id].y += plus_y;
            node[id].x += x_start;
            return;
        }          
        
        push(id, l, r);

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, j, x_start, plus_y);
        updated(id * 2, mid + 1, r, i, j, x_start, plus_y);

        node[id].val = (node[id * 2].val * node[id * 2 + 1].val) % mod;
        node[id].x = node[id * 2].x + node[id * 2 + 1].x;
        node[id].y = node[id * 2].y + node[id * 2 + 1].y;
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > i || r < j) return 0;
        if(i <= l && r <= j) return node[id].val;

        push(id, l , r);

        ll mid = (l + r) >> 1;

        return (get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j)) % mod;
    }
}

void read() {
    cin >> n >> m;
}
void solve() {
    SegmentTree node(n);

    while(m --) {
        ll x, l, r, i, j;
        cin >> x >> l >> r;
        if(x == 1) {
            cin >> i >> j;
            node.updated(1, 1, n, l, r, i, j);
        } else {
            cout << node.get(1, 1 ,n, l, r) << el;
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