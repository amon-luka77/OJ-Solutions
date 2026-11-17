#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 5e3;
int a[N + 1];
int n;

ll dnc(int l, int r, int h) {
    int min_h = 1e9;
    FOR(i, l, r) min_h = min(min_h, a[i]);

    ll res = min_h - h;
//    int x = min_h - h;

    FOR(i, l, r) if(a[i] > min_h) {
        int j = i;
        while(j <= r && a[j] > min_h) j++;
        res += dnc(i, j - 1, min_h);
        i = j - 1;
    }

//    if(l == 1 && r == n) cout << res << "\n";

    return min(res, (ll)r - l + 1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    cout << dnc(1, n, 0);
}
