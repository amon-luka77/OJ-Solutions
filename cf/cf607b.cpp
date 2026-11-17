
#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 5e2;
int n;

int a[N + 1];

int dp[N + 1][N + 1];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    memset(dp, 0x3f, sizeof dp);

    FOR(i, 1, n) dp[i][i] = 1;
    FOR(i, 1, n - 1) dp[i][i + 1] = (a[i] == a[i + 1] ? 1 : 2);

    FOR(len, 3, n) FOR(i, 1, n - len + 1) {
        int j = i + len - 1;
        dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
        if(a[i] == a[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
        if(a[i] == a[i + 1]) dp[i][j] = min(dp[i][j], 1 + dp[i + 2][j]);
N
        FOR(k, i + 2, j - 1) if(a[i] == a[k]) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k + 1][j]);
    }

//    FOR(i, 1, n) FOR(j, i, n) cout << "DEBUG: " << "[" << i << ", " << j << "] so lan xoa it nhat la: " << dp[i][j] << "\n";

    cout << dp[1][n];
}
