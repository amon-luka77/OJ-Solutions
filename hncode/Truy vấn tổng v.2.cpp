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
ll n, m, a[N + 1];

struct SegmentTree {
    struct NODE {
        ll val, gan, them;
    };

    vector<NODE> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, (ll)-1e18, 0});
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id].val = a[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id].val = node[id * 2].val + node[id * 2 + 1].val;
    }

    void push(ll id, ll l, ll r) {
        if(node[id].gan == -1e18 && node[id].them == 0) return;
        
        ll mid = (l + r) >> 1;

        if(node[id].them != 0) {
            ll k = node[id].them;
            node[id].them = 0;

            node[id * 2].val += k * (mid - l + 1);
            if(node[id * 2].gan == -1e18) node[id * 2].them += k;
            else {
                node[id * 2].gan += k;
                node[id * 2].them = 0;
            }

            node[id * 2 + 1].val += k * (r - mid);
            if(node[id * 2 + 1].gan == -1e18) node[id * 2 + 1].them += k;
            else {
                node[id * 2 + 1].gan += k;
                node[id * 2 + 1].them = 0;
            }
        }

        if(node[id].gan != -1e18) {
            ll k = node[id].gan;
            node[id].gan = -1e18;

            node[id * 2].val = k * (mid - l + 1);
            node[id * 2].gan = k;
            node[id * 2].them = 0;

            node[id * 2 + 1].val = k * (r - mid);
            node[id * 2 + 1].gan = k;
            node[id * 2 + 1].them = 0;
        }

        return;
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll val, ll type) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            if(type == 1) {
                node[id].val += val * (r - l + 1);
                if(node[id].gan == -1e18) {
                    node[id].them += val;
                } else {
                    node[id].gan += val;
                    node[id].them = 0;
                }
            } else {
                node[id].val = val * (r - l + 1);
                node[id].gan = val;
                node[id].them = 0;
            }
            return;
        }

        push(id, l, r);

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, j, val, type);
        updated(id * 2 + 1, mid + 1, r, i, j, val, type);

        node[id].val = node[id * 2].val + node[id * 2 + 1].val;
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id].val;

        push(id, l, r);

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);

    for(ll i = 1; i <= m; i ++) {
        ll x, l, r, k; cin >> x >> l >> r;

        if(x == 1 || x == 2) {
            cin >> k;
            node.updated(1, 1, n, l, r, k, x);
        } else {
            cout << node.get(1, 1, n, l, r) << el;
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