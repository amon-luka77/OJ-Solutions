#include<bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define MASK(i) (1LL << (i))

using namespace std;

const int N = 1e5;
int n, k, A, B;
int a[N + 1];

ll dnc(int l, int r) {
    ll Left = lower_bound(a + 1, a + k + 1, l) - a;
    ll Right = upper_bound(a + 1, a + k + 1, r) - a - 1;

    ll res = (Left <= Right ? B * (Right - Left + 1) * (r - l + 1) : A);

    if(l == r) return res;

    ll mid = (l + r) >> 1;

    return min(res, dnc(l, mid) + dnc(mid + 1, r));
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> A >> B;

    FOR(i, 1, k) cin >> a[i];
    sort(a + 1, a + k + 1);

    cout << dnc(1, MASK(n));
}
