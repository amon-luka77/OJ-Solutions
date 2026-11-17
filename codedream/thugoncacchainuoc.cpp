#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<ll> a(n + 1, 0);
    vector<pair<int, int>> pos(n + 1, {0, 0});
    FOR(i, 1, n) cin >> a[i];

    #define ft first
    #define sc second

    int x = 0;

    FOR(i, 1, n) {
        int cnt = 0;
        while(a[i] > 0 && a[i] % 2 == 0) {a[i] /= 2; cnt ++;}
        pos[i].ft = cnt; cnt = 0;
        while(a[i] > 0 && a[i] % 5 == 0) {a[i] /= 5; cnt ++;}
        pos[i].sc = cnt; x += cnt;
    }

    vector<vector<int>> dp(k + 1, vector<int>(x + 1, -1e9));

    dp[0][0] = 0;
    FOR(i, 1, n) FORD(j, k, 1) FORD(l, x, 0) if(l >= pos[i].sc) {
        dp[j][l] = max(dp[j][l], dp[j - 1][l - pos[i].sc] + pos[i].ft);
    }

    int res = 0;
    FOR(l, 0, x) res = max(res, min(l, dp[k][l]));

    cout << res;
}
