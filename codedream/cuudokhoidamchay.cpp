#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

struct A {
    int x, y, z, i;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<A> a(n + 1);

    FOR(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].z, a[i].i = i;

    sort(a.begin() + 1, a.end(), [](const A &x, const A &y) {
       return x.y < y.y;
    });

    // d[i] diem nhan duoc tai thoi diem t
    // [x, y, z] = a[i]
    // voi moi i <= z -> dp[i] = max(dp[i], dp[i - z] + y]

    #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)
    #define ft first
    #define sc second

    vector<vector<int>> dp(n + 1, vector<int>(2001, -1e9));
    vector<vector<pair<int, int>>> trace(n + 1, vector<pair<int, int>>(2001, {0, 0}));
    dp[0][0] = 0;

    FOR(i, 1, n) FORD(j, 2000, 0) {
        dp[i][j] = dp[i - 1][j];
        if(j >= a[i].x && j < a[i].y && dp[i][j] < dp[i - 1][j - a[i].x] + a[i].z) {
            dp[i][j] = dp[i - 1][j - a[i].x] + a[i].z;
            trace[i][j] = {i, a[i].i};
        }
    }

    pair<int, int> res = {0, 0};
    FOR(i, 0, 2000) res = (dp[res.ft][res.sc] < dp[n][i] ? make_pair(n, i) : res);

    vector<int> path;

    int rr = dp[res.ft][res.sc];

//    cout << trace[2][2] << "\n";

    while(res.ft > 0) {
        auto[x, y] = trace[res.ft][res.sc];
//        cout << res.ft << ' ' << res.sc << "\n";
        if(x) {
            path.push_back(y);
            res.sc -= a[x].x;
        }
        res.ft --;
    }

    cout << rr << "\n";
    cout << path.size() << "\n";
    FORD(i, path.size() - 1, 0) cout << path[i] << ' ';
}
