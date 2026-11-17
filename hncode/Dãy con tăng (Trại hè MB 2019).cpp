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
ll n, a[N + 1], w[N + 1], dp[N + 1], path[N + 1];

struct SegmentTree {
    vector<pair<ll, ll>> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, {0, 0});
    }

    void updated(ll id, ll l, ll r, ll i, ll val, ll idx) {
        if(l > i || r < i) return;
        if(l == r) {
            if(node[id].ft < val) {
                node[id] = {val, idx};
            }
            return;
        }

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, val, idx);
        updated(id * 2 + 1, mid + 1, r, i, val, idx);

        if(node[id * 2].ft <= node[id * 2 + 1].ft) {
            node[id] = node[id * 2 + 1];
        } else {
            node[id] = node[id * 2];
        }
    }

    pair<ll, ll> get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return {0, 0};
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        auto get1 = get(id * 2, l, mid, i, j);
        auto get2 = get(id * 2 + 1, mid + 1, r, i, j);

        if(get1.ft < get2.ft) return get2;
        return get1;
    }
};

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i ++) {
        cin >> w[i];
    }
}   
void solve() {
    ll ans = 0, cur = 0;
    SegmentTree node(N);

    // dp[i] tong trong so lon nhat o dinh i

    for(ll i = 1; i <= n; i ++) {
        auto j = node.get(1, 1, N, 1, a[i] - 1);
        dp[i] = w[i] + j.ft;
        path[i] = j.sc;
        node.updated(1, 1, N, a[i], dp[i], i);
        if(ans < dp[i]) {
            ans = dp[i];
            cur = i;
        }
    }

    vector<ll> trace;
    while(cur > 0) {
        trace.pb(cur);
        cur = path[cur];
    }

    cout << trace.size() << el;
    for(ll i = trace.size() - 1; i >= 0; i --) {
        cout << trace[i] << ' ';
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