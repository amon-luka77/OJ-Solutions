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

int b[10001];

int power(int a, int b, int mod) {
    int res = 0;
    a %= mod;
    while(b) {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    base[1] = {0, 1};
    base[2] = {1, 1};
    base[3] = {1, 0};

    int n, mod; cin >> n >> mod;
    FOR(i, 1, n) cin >> b[i];

    FOR(i, 1, 3) a[i] = base[i];

    FOR(i, 1, n) {
        // cout << num.ft << ' ' << num.sc << "\n";

        if(i % 2 == 0) {
            pair<int, int> t1 = {(power(a[1].ft, b[i], mod) + a[2].ft) % mod, (power(a[1].sc, b[i], mod) + a[2].sc) % mod};
            pair<int, int> t2 = {(power(a[1].ft, b[i] - 1, mod) + a[2].ft) % mod, (power(a[1].sc, b[i] - 1, mod) + a[2].sc) % mod};
            a[2] = t1, a[3] = t2;
            
        } else {
            pair<int, int> t1 = {(power(a[3].ft, b[i], mod) + a[2].ft) % mod, (power(a[3].sc, b[i], mod) + a[2].sc) % mod};
            pair<int, int> t2 = {(power(a[3].ft, b[i] - 1, mod) + a[2].ft) % mod, (power(a[3].sc, b[i] - 1, mod) + a[2].sc) % mod};
            a[2] = t1, a[1] = t2;
        }
    }

    cout << a[2].ft << ' ' << a[2].sc;
}

/*
x, y
0, 1; 1, 1
x + y
x + x + y
x + x + x + y


*/