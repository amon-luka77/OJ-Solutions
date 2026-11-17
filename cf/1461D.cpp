#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

set<ll> ans;
int a[100001];
ll prefix[100001];

void dnc(int l, int r) {
    if(l == r) return ans.insert(a[l]), void();

    ll sum = prefix[r] - prefix[l - 1];
    if(sum <= 1e9) ans.insert(sum);

    int L = l, R = r, x = 0;
    int m = (a[l] + a[r]) >> 1;

    while(L <= R) {
        int mid = (L + R) >> 1;
        if(a[mid] <= m) {
            L = mid + 1, x = mid;
        } else R = mid - 1;
    }

    if(x == r || !x) return;

    dnc(l, x), dnc(x + 1, r);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;

    while(t --) {
        int n, q; cin >> n >> q;
        ans.clear();

        FOR(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        FOR(i, 1, n) prefix[i] = prefix[i - 1] + a[i];

        dnc(1, n);

        while(q --) {
            int s; cin >> s;

            cout << (ans.find(s) != ans.end() ? "Yes\n" : "No\n");
        }
    }
}
