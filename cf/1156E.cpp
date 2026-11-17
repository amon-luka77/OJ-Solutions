#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 3e5;

int n, a[N + 1];
int pos[N + 1];
int maxLeft[N + 1], maxRight[N + 1];

int dnc(int l, int r) {
    if(l == r) return 0;

    ll res = 0;
    int mid = (l + r) >> 1;

    maxLeft[mid] = a[mid];
    FOR(i, 1, mid - 1) maxLeft[i] = max(maxLeft[i + 1], a[i]);
    maxRight[mid + 1] = a[mid + 1];
    FOR(i, mid + 1, r) maxRight[i] = max(maxRight[i - 1], a[i]);

    FOR(i, l, r) {
        if(i <= mid) {
            int cur = maxLeft[i] - a[i];
            if(pos[cur] >= mid + 1 && pos[cur] <= r) res ++;
        } else {
            int cur = maxRight[i] - a[i];
            if(pos[cur] >= l && pos[cur] <= mid) res ++;
        }
    }

    return res + dnc(l, mid) + dnc(mid + 1, r);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i], pos[a[i]] = i;

    cout << dnc(1, n);
}
