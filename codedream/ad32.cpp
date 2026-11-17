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
ll n, m, a[N + 1], b[N + 1];
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

    void updatedRange(ll l, ll r) {
        updated(l, -1);
        updated(r + 1, 1);
    }

    ll get(ll u) {
        ll ans = 0, idx = u;
        while(idx > 0) {
            ans += bit[idx];
            idx -= (idx & (-idx));
        }
        return ans;
    }

    ll getBinary(ll val) {
        ll l = 1, r = n, ans = -1;
        while(l <= r) {
            ll mid = l + (r - l) / 2;
            if(get(mid) >= val) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cin >> m;
    for(ll i = 1; i <= m; i ++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
}
void solve() {
    FenwickTree BIT(n + 1);
    for(ll i = 1; i <= n; i ++) {
        BIT.updated(i, a[i] - a[i - 1]);
    }
    for(ll i = 1; i <= m; i ++) {
        ll k = BIT.getBinary(b[i]);
        if(k == -1) cout << 0 << el;
        else {
            cout << n - k + 1 << el;
            BIT.updatedRange(k, n);
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