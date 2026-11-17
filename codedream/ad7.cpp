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
ll n, m, a[N + 1];
struct FenwickTree {
    vector<ll> bit;

    FenwickTree(ll n) {
        bit.assign(n + 1, 0);
    }

    void updated(ll u, ll val) {
        ll idx = u;
        while(idx <= n) {
            bit[idx] += val;
            idx += (idx & (-idx));
        }
    }

    void updatedRange(ll l, ll r, ll val) {
        updated(l, val);
        updated(r + 1, -val);
    }

    ll getSum(ll u) {
        ll idx = u, ans = 0;
        while(idx > 0) {
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }
};
void read() {
    cin >> n >> m;
}
void solve() {
    FenwickTree BIT(n + 1);
    while(m--) {
        ll x, l, r, val;
        cin >> x >> l >> r;
        if(x == 1) {
            cin >> val;
            BIT.updatedRange(l, r, (r - l + 1) * val);
        } else {
            cout << BIT.getSum(r) - BIT.getSum(l - 1) << el;
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