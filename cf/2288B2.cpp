#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

int B(int x, int y, int n, string &s) {

    int res = x + y, pos = 0;
    int cur = res;

    FOR(i, 0, s.size() - 1) {
        char xx = s[i];
        if(x + y == 0) continue;

        if(xx == '+') {
            if(y > 0) y ++;
            else x --, y ++;
            if(res < x + y) {
                res = x + y; pos = i + 1;
            }
        } else {
            if(y > 1) y --, x ++;
            else if(y == 1 && x == 0) y --, x ++;
            else x --;
        }

        // cout << x << ' ' << y << "\n";
    }

    return pos;
}

void solve() {
    int n; cin >> n;

    auto ask = [&] (string s) {
        cout << s << endl;
        int pos; cin >> pos;
        return pos;
    };

    string k = "+++";
    FOR(i, 1, n + 5) k += "--+";

    int pos = ask(k);

    FOR(i, 0, n) {
        int y = n - i;
        if(B(i, y, n, k) == pos) {
            cout << i + y * 2 << endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}