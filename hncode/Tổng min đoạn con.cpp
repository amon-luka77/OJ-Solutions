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
ll n, a[N + 5];
struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 5, 0);
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            node[id] = a[l];
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
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);
    node.build(1, 1, n);
    ll sum = 0;

    for(ll i = 1; i <= n; i ++) {
        ll left = node.get_left(1, 1, n, 1, i - 1, a[i]);
        ll right = node.get_right(1, 1, n, i + 1, n, a[i]);

        if(left == 0) left = 1;
        else left ++;
        if(right == 0) right = n;
        else right --;

        left = i - left + 1;
        right = right - i + 1;

        sum = (sum + ((left % mod * right % mod) % mod * a[i] % mod) % mod) % mod;
    }

    cout << sum % mod;
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
