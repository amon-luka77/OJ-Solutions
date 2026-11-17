#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, r; cin >> n >> r;
    vector<pair<int, int>> a, b;
    b.push_back({0, 0});

    FOR(i, 1, n) {
        int x, y; cin >> x >> y;
        if(y >= 0) a.push_back({x, y});
        else b.push_back({x, -y});
    }

    #define all(x) (x).begin(), (x).end()
    #define ft first
    #define sc second

    sort(all(a));
    int res = 0;

    for(auto &[x, y] : a) {
        if(r >= x) r += y, res ++;
    }

    sort(b.begin() + 1, b.end(), [](const pair<int, int> &x, const pair<int, int> &y) {
        return x.ft - x.sc > y.ft - y.sc;
    });

    // dp[i][j]: 1->i co limit = j
    // -> if(j + b[i].ft <= r) dp[i][j] = max(dp[i][j], dp[i][j + b[i].sc] + 1);
    // j >= b[i].ft; dp[i][j] = dp[i - 1][j + b[i].sc] + 1;

//    cout << r << "\n";

    vector<vector<int>> dp(b.size() + 1, vector<int>(r + 1, -1e9));
    dp[0][r] = 0;

    FOR(i, 1, b.size() - 1) FOR(j, 0, r) {
        dp[i][j] = dp[i - 1][j];
        if(j + b[i].sc >= b[i].ft && j + b[i].sc <= r) dp[i][j] = max(dp[i][j], dp[i - 1][j + b[i].sc] + 1);
    }

    int res2 = 0;
    FOR(i, 0, r) res2 = max(res2, dp[b.size() - 1][i]);

//    FOR(i, 1, b.size() - 1) FOR(j, 0, r) cout << "[" << i << ", " << j << "] co max la: " << dp[i][j] << "\n";

    cout << res + res2;
}
