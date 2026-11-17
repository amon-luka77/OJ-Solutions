#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

char a[131073];
int prefix[131073][26];

int getSum(int l, int r, int c) {
    int x = prefix[r][c] - prefix[l - 1][c];
    return r - l + 1 - x;
}

int dnc(int l, int r, int c) {
    if(l == r) return (a[l] - 'a' != c ? 1 : 0);
    if(c == 26) return getSum(l, r, c - 1);

    int mid = (l + r) >> 1;
    int cntLeft = getSum(l, mid, c) + dnc(mid + 1, r, c + 1);
    int cntRight = dnc(l, mid, c + 1) + getSum(mid + 1, r, c);

    return min(cntLeft, cntRight);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while(t --) {
        int n; cin >> n;

        FOR(i, 1, n) {
            cin >> a[i];
            FOR(j, 0, 25) prefix[i][j] = prefix[i - 1][j] + (a[i] - 'a' == j);
        }

        cout << dnc(1, n, 0) << "\n";
    }
}
