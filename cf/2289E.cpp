#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    int n, d; cin >> n >> d;

    vector<vector<int>> edge(2 * n + 1, vector<int>());

    FOR(i, 1, n - 1) {
        int x, y; cin >> x >> y;
        edge[i + n].push_back(x); edge[i + n].push_back(y);
    }

    vector<multiset<int>> a(2 * n + 1);
    vector<vector<int>> par(2 * n + 1, vector<int>(21, 0)), minVal(2 * n + 1, vector<int>(21, 0));

    auto dfs = [&](auto &self, int u) -> void {
        if(u <= n) return a[u].insert(u), minVal[u][0] = u, void();
        // cout << u << ' ';

        int l = edge[u][0], r = edge[u][1];
        par[l][0] = par[r][0] = u;

        self(self, l), self(self,  r);

        while(!a[l].empty() && !a[r].empty() && *a[l].rbegin() - d >= *a[r].rbegin()) a[l].erase(prev(a[l].end()));
        while(!a[r].empty() && !a[l].empty() && *a[r].rbegin() - d >= *a[l].rbegin()) a[r].erase(prev(a[r].end()));

        if(a[l].size() <= a[r].size()) {
            a[u].swap(a[r]); for(auto i : a[l]) a[u].insert(i);
        } else {
            a[u].swap(a[l]); for(auto i : a[r]) a[u].insert(i);
        }

        minVal[u][0] = *a[u].rbegin();
        // cout << u << ' ' << minVal[u][0] << "\n";

        return;
    }; 
    
    dfs(dfs, 2 * n - 1);

    // cout << "naidsfads \n";
    // FOR(u, 1, 2 * n - 1) {
        
    //     cout << "edge: " << u << "\n";
    //     for(auto i : a[u]) cout << i << ' ';
    //     cout << "\n";
    // }

    FOR(j, 1, 20) FOR(i, 1, 2 * n - 1) {
        par[i][j] = par[par[i][j - 1]][j - 1];
        minVal[i][j] = min(minVal[i][j - 1], minVal[par[i][j - 1]][j - 1]);
    }

    FOR(i, 1, n) {
        int ans = 0, u = i;
        #define MASK(i) (1LL << (i))

        for(int j = 20; j >= 0; j --) if(par[u][j] && i <= minVal[u][j]) {
            ans += MASK(j);
            u = par[u][j];
        }
        
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}