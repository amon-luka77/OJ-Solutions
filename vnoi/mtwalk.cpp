#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    const int N = 100;
    const int maxN = 110;

    static int a[N + 1][N + 1];

    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];


    static bool vs[N + 1][N + 1];
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    auto check = [&](int mid) {

        auto bfs = [&](int l, int r) {
            queue<pair<int, int>> q; q.push({1, 1});
            vs[1][1] = 1;

            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();

                for(auto &[i, j] : d) {
                    int newI = i + x, newJ = j + y;
                    if(newI < 1 || newI > n || newJ < 1 || newJ > n ||
                        a[newI][newJ] > r || a[newI][newJ] < l || vs[newI][newJ]) continue;
                    vs[newI][newJ] = 1; q.push({newI, newJ});
                }
            };

            return vs[n][n];
        };
        
        FOR(start, 0, maxN - mid) if(a[1][1] >= start && a[1][1] <= start + mid) {
            FOR(i, 1, n) FOR(j, 1, n) vs[i][j] = 0;
            if(bfs(start, start + mid)) return 1;
        }

        return 0;
    };

    int l = 0, r = 110, ans = 0;

    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }

    cout << ans;
}