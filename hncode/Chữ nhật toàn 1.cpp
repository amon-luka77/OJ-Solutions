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
const ll N = 1000;
ll n, m, a[N + 1][N + 1], prefix[N + 1][N + 1], b[N + 1];
struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id] = b[l];
            return;
        }

        ll mid = (l + r) >> 1;

        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id] = min(node[id * 2], node[id * 2 + 1]);
    }

    ll get_left(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i || node[id] >= val) return 0;
        if(l == r) return l;

        ll mid = (l + r) >> 1;

        auto get1 = get_left(id * 2 + 1, mid + 1, r, i, j, val);

        if(get1 > 0) return get1;
        else return get_left(id * 2, l, mid, i, j, val); 
    }

    ll get_right(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i || node[id] > val) return 0;
        if(l == r) return l;

        ll mid = (l + r) >> 1;

        auto get1 = get_right(id * 2, l, mid, i, j, val);
        if(get1 > 0) return get1;
        else return get_right(id * 2 + 1, mid + 1, r, i, j, val);
    }
};
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m;  j++) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }
    
    for(ll i = 1; i <= m; i ++) {
        // 1 i // n i
        b[i] = prefix[n][i] - prefix[n][i - 1];
    }

    SegmentTree node(m);
    node.build(1, 1, m);
    ll ans = 0;

    for(ll i = 1; i <= m; i ++) {
        
        ll left = node.get_left(1, 1, m, 1, i - 1, b[i]);
        ll right = node.get_right(1, 1, m, i + 1, m, b[i]);

        if(left == 0) left = 1;
        else left ++;
        if(right == 0) right = m;
        else right --;

        ans = max(ans, left * right * b[i]);
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