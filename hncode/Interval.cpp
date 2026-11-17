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
ll n, m, dp[N + 1];

struct kk {
    ll x, y, z;
};

struct SegmentTree {
    vector<ll> node;

    void resize(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] += val;
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

SegmentTree node;

vector<kk> a;

void read() {
    cin >> n >> m;
    node.resize(n);

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z; cin >> x >> y >> z;
        node.updated(1, 1, n, x, z);
        node.updated(1, 1, n, y + 1, -z);
    }
}

void solve() {
    ll ans = -1e9;

    for(ll i = 1; i <= n; i ++) {
        dp[i] = dp[i - 1];
        for(ll j = i; j >= 1; j --) {
            dp[i] = max({dp[i], dp[j - 1] + node.get(1, 1, n, j, i)});
        }

        ans = max(ans, dp[i]);
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