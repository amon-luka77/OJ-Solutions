#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    int n;
    cin >> n;

    // max = (1 + c) + c + .. + 1 = (c + 1) * (c + 2) / 2 <= n;

    FOR(i, 1, n) {
        int dmg = 0;
        FOR(k, 1, (i + 1) / 2) {
            int x = i - k;
            dmg = max(dmg, k * (x + 1) - k * (k - 1) / 2);
        }

        if(dmg >= n) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}