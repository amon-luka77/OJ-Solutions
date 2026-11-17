#include<bits/stdc++.h>
#define int long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

pair<int, int> a[4], base[4];

#define ft first
#define sc second

bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
    return x.ft * y.sc < x.sc * y.ft;
}

int b[10001];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    base[1] = {0, 1};
    base[2] = {1, 1};
    base[3] = {1, 0};

    int n, mod; cin >> n >> mod;

    FOR(i, 1, 3) a[i] = base[i];
    // 16 = 00001

    FORD(i, __lg(n) - 1, 0) {
        // cout << num.ft << ' ' << num.sc << "\n";
        #define BIT(x, i) (((x) >> (i)) & 1LL)
        if(!BIT(n, i)) {
            pair<int, int> t = {(a[1].ft + a[2].ft) % mod, (a[2].sc + a[1].sc) % mod};
            a[3] = a[2];
            a[2] = t;
            
        } else {
            pair<int, int> t = {(a[3].ft + a[2].ft) % mod, (a[2].sc + a[3].sc) % mod};
            a[1] = a[2];
            a[2] = t;
        }
    }

    cout << a[2].ft << ' ' << a[2].sc;
}

/*
0, 1, 2, 3, 4
101
*/