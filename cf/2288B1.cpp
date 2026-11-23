#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    int x, y, n; cin >> x >> y >> n;

    int res = x + y;
    int cur = res;

    FOR(i, 1, n) {
        char xx; cin >> xx;

        if(x + y == 0) continue;

        if(xx == '+') {
            if(y > 0) y ++;
            else x --, y ++;
            res = max(res, x + y);
        } else {
            if(y > 1) y --, x ++;
            else if(y == 1 && x == 0) y --, x ++;
            else x --;
        }

        // cout << x << ' ' << y << "\n";
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