#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while(t --) {
        int n; cin >> n;
        vector<int> a, b;
        int max1 = 0, min1 = 1e9, cnt = 0;

        for(int i = 1; i <= n; i ++) {
            char x; cin >> x;
            if(x == '1') max1 = max(max1, i), min1 = min(min1, i), cnt ++;
        }

        if(cnt > n) cout << max1 - 1 << "\n";
        else if(cnt == 1) cout << 0 << "\n";
        else cout << max1 - min1 << "\n";
    }
}
