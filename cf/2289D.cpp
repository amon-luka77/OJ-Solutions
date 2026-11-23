#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int _n) {
        n = _n; bit.assign(n + 1, 0);
    }

    void updated(int i) {for(; i <= n; i += i & -i) bit[i] ++;}
    int get(int i) {int res = 0; for(; i; i -= i & -i) res += bit[i]; return res;}
    int getSum(int l, int r) {return get(r) - get(l - 1);}
};

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    FOR(i, 1, n) cin >> a[i];

    // sum ko doi
    // bien doi i < n -> tong ko doi
    // i = n -> sum - a[i];

    // prefix[i] = prefix[i - 1] + a[i]

    // -> i: -> prefix[i] - 2 * a[i], prefix[i - 1] + a[i];

    // -> swap(prefix[i - 1], prefix[i])
    // -> mang ko am -> prefix[i] tang dan


    vector<ll> prefix(n + 1);

    bool ok = 0;
    FOR(i ,1 ,n) {
        prefix[i] = prefix[i - 1] + a[i];
        if(prefix[i] < 0) ok = 1;
    }

    if(ok) {cout << "-1\n"; return;}



    FenwickTree bit(n);
    vector<ll> b;

    int res = 0;

    FOR(i, 1, n) b.push_back(prefix[i]);
    sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());

    FOR(i, 1, n) {
        int x = lower_bound(b.begin(), b.end(),  prefix[i]) - b.begin() + 1;
        res += bit.getSum(x + 1, n);
        bit.updated(x);
    }

    cout << res << "\n";

}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}