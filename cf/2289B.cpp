#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> a(n + 1);
    FOR(i ,1, n) cin >> a[i];

    int res = 0;
    vector<int> cnt(n + 1, 0);

    FOR(i, 1, k) {
        int j = i + n - k;
        if(i == 1) {
            FOR(kk, i, j) {
                cnt[a[kk]] ++;
            }
        } else {
            cnt[a[i - 1]] --;
            cnt[a[j]] ++;
        }

        if(cnt[a[i]] == n - k + 1) res ++;
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}