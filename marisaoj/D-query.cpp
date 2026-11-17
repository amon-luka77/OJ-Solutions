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
const ll N = 1e5;
ll n, q, a[N + 1], pos[N + 1], ans[N + 1];

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] = val;
            return;
        }

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, val);
        updated(id * 2 + 1, mid + 1, r, i, val);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;
        
        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

struct KK {
    ll fi, last, type;
};

bool cmp(const KK& x, const KK& y) {
    return x.last < y.last;
}

void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i ++) {
        pos[i] = -1;
    }
}
void solve() {
    SegmentTree node(n);
    vector<KK> query;

    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;

        query.pb({l, r, i});
    }

    sort(all(query), cmp);

    for(ll i = 0; i < query.size(); i ++) {
        if(i == 0) {
            for(ll j = 1; j  <= query[i].last; j ++) {
                if(pos[a[j]] == -1) {
                    node.updated(1, 1, n, j, 1);
                } else {
                    node.updated(1, 1, n, pos[a[j]], 0);
                    node.updated(1, 1, n, j, 1);
                }
                pos[a[j]] = j;
            }
        } else {
            for(ll j = query[i - 1].last + 1; j  <= query[i].last; j ++) {
                if(pos[a[j]] == -1) {
                    node.updated(1, 1, n, j, 1);
                } else {
                    node.updated(1, 1, n, pos[a[j]], 0);
                    node.updated(1, 1, n, j, 1);
                }
                pos[a[j]] = j;
            }
        }

        ans[query[i].type] = node.get(1, 1, n, query[i].fi, query[i].last);
    }

    for(ll i = 1; i <= q; i ++) {
        cout << ans[i] << el;
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