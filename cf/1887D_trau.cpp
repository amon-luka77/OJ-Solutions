#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b ; i ++)

using namespace std;

const int N = 3e5, LOG = 20;

#define MASK(i) (1LL << (i))

int n, a[N + 1], minVal[N + 1][LOG + 1], maxVal[N + 1][LOG + 1];

int getMin(int l, int r) {
    int k = __lg(r - l + 1);
    return min(minVal[l][k], minVal[r - MASK(k) + 1][k]);
}


int getMax(int l, int r) {
    int k = __lg(r - l + 1);
    return max(maxVal[l][k], maxVal[r - MASK(k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("1887D.inp", "r", stdin);
    freopen("1887D.ans", "w", stdout);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    FOR(i, 1, n) minVal[i][0] = a[i], maxVal[i][0] = a[i];

    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) {
        minVal[i][j] = min(minVal[i][j - 1], minVal[i + MASK(j - 1)][j - 1]);
        maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + MASK(j - 1)][j - 1]);
    }

    int q; cin >> q;
    while(q --) {
        int x, y; cin >> x >> y;
        bool ok = 0;
        FOR(i, x, y - 1) {
            if(getMax(x, i) < getMin(i + 1, y)) {ok = 1; break;}
        } cout << (ok ? "Yes\n" : "No\n");cerr << (ok ? "Yes\n" : "No\n");
    }
}
