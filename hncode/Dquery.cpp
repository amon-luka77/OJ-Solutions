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
ll n, q, a[N + 1], ans[N + 1];

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i) {
        if(l > i || r < i) return;
        if(l == r) {
            if(node[id] < 2) node[id] ++;
            return;
        }

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i);
        updated(id * 2 + 1, mid + 1, r, i);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

struct QUERY {
    ll x, y, z;
};

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(N);
    vector<QUERY> query;
    
    cin >> q;
    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        query.pb({l - 1, i, -1LL});
        query.pb({r, i, 1LL});
    }

    for(ll i = 0; i < query.size(); i ++) {
        auto [last, type, t] = query[i];
        if(i == 0) {
            for(ll j = 1; j <= last; j ++) {
                node.updated(1, 1, N, a[j]);
            }

            ans[type] += node.get(1, 1, N, 1, N) * t;
        } else {

            for(ll j = query[i - 1].x + 1; j <= last; j ++) {
                node.updated(1, 1, N, a[j]);
            }

            ans[type] += node.get(1, 1, N, 1, N) * t;

        }
    }

    for(ll i = 1; i <= q; i ++) {
        cout << ans << el;
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