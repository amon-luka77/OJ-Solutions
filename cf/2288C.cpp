#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n + 1), b(n + 1);

    FOR(i, 1, n) cin >> a[i], b[i] = (a[i] + x - 1) / x;

    sort(b.begin() + 1, b.end());

    int ans = 0;

    FOR(i, 1, n - 1) {
        ans = max(ans, b[i] - i);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}