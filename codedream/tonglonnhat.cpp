#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

vector<vector<ll>> prefix;
vector<vector<int>> a;

ll res = 0;

void dnc(int l, int r, vector<ll>dp, int k) {
    if(l > r) return;
    if(l == r) {
        FOR(i, 0, min(k, (int)a[l].size() - 1)) {
            res = max(res, dp[k - i] + prefix[l][i]);
        }
        return;
    }

    int mid = (l + r) >> 1;

    vector<ll> dpLeft = dp;
    FOR(i, mid + 1, r) FORD(j, k, a[i].size() - 1) {
        dpLeft[j] = max(dpLeft[j], dpLeft[j - (a[i].size() - 1)] + prefix[i][a[i].size() - 1]);
    }

    vector<ll> dpRight = dp;
    FOR(i, l, mid) FORD(j, k, a[i].size() - 1) {
        dpRight[j] = max(dpRight[j], dpRight[j - (a[i].size() - 1)] + prefix[i][a[i].size() - 1]);
    }

    dnc(l, mid, dpLeft, k);
    dnc(mid + 1, r, dpRight, k);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    a.resize(n + 1);
    prefix.resize(n + 1);

    FOR(i, 1, n) {
        int x; cin >> x; vector<int> b; b.push_back(0);
        vector<ll> c; c.push_back(0);
        FOR(j, 1, x) {int y; cin >> y; b.push_back(y); c.push_back(c.back() + y);}
        a[i] = b;
        prefix[i] = c;
    }

    vector<ll> dp(k + 1, -1e18);
    dp[0] = 0;

    dnc(1, n, dp, k);

    cout << res;
}
