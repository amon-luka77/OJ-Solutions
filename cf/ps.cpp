#include<bits/stdc++.h>
#define int long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

pair<int, int> a[4], base[4];

#define ft first
#define sc second

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
    return x.ft * y.sc < x.sc * y.ft;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int x, y;
    base[1] = {0, 1};
    base[2] = {1, 1};
    base[3] = {1, 0};

    while(cin >> x >> y) {
        if(x == 1 && y == 1) break;
        string ans = "";
        FOR(i, 1, 3) a[i] = base[i];
        bool ok = 0;
        if(x > y) ok = 1, swap(x, y);

        while(make_pair(x, y) != a[2]) {
            if(cmp(make_pair(x, y), a[2])) {
                ans.push_back('L');
                pair<int, int> t = {a[1].ft + a[2].ft, a[2].sc + a[1].sc};
                a[3] = a[2];
                a[2] = t;
            } else {
                ans.push_back('R');
                pair<int, int> t = {a[3].ft + a[2].ft, a[2].sc + a[3].sc};
                a[1] = a[2];
                a[2] = t;
            }
        }

        for(auto i : ans) {
            if(ok) cout << (i == 'L' ? 'R' : 'L');
            else cout << i;
        }
        cout << "\n";
    }
}