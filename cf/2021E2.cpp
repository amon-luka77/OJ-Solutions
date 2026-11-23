#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    int n, m, p;

    cin >> n >> m >> p;

    const int N = 2e5;

    vector<int> h(p + 5);

    FOR(i, 1, p) cin >> h[i];
    
    struct Edge {
        int x, y, z;

        bool operator < (const Edge &other) const {
            return z < other.z;
        }
    }; 

    vector<Edge> e(m);
    vector<vector<int>> edge(2 * n);

    FOR(i, 0, m - 1) cin >> e[i].x >> e[i].y >> e[i].z;

    sort(e.begin(), e.end());

    vector<int> parent(2 * n), sz(2 * n), val(2 * n);

    FOR(i, 1, n) parent[i] = i;
    FOR(i, 1, 2 * n - 1) sz[i] = 0;
    FOR(i, 1, p) sz[h[i]] = 1;

    int numNode = n;

    auto find_set = [&](auto &self, int k) -> int {return k == parent[k] ? k : self(self, parent[k]);};

    auto add = [&](int u, int v) {edge[v].push_back(u);};

    auto union_set = [&](int u, int v, int value) {
        if((u = find_set(find_set, u)) == (v = find_set(find_set, v))) return;

        numNode ++;
        parent[u] = parent[v] = parent[numNode] = numNode; val[numNode] = value;
        sz[numNode] = sz[u] + sz[v];
        add(u, numNode), add(v, numNode);
    };


    for(auto [x, y, z] : e) union_set(x, y, z);

    vector<vector<ll>> dp(numNode + 1);

    FOR(i, 1, numNode) {
        dp[i].assign(sz[i] + 1, 1e18);
    }

    auto dfs = [&](auto &self, int u, int p) -> void {
        if(u <= n) {
            if(sz[u]) dp[u][1] = 0;
            return;
        }

        int l = edge[u][0], r = edge[u][1];
        self(self, l, u), self(self, r, u);
        // cout << "Val: " << u << ' ' << sz[u] << "\n";
        // cout << u << ' ' << l << "\n";
        // cout << u << ' ' << r << "\n";

        FOR(i, 1, sz[l]) dp[u][i] = min(dp[u][i], dp[l][i] + 1LL * val[u] * sz[r]);
        FOR(i, 1, sz[r]) dp[u][i] = min(dp[u][i], dp[r][i] + 1LL * val[u] * sz[l]);

        FOR(i, 1, sz[l]) FOR(j, 1, sz[r]) dp[u][i + j] = min(dp[u][i + j], dp[l][i] + dp[r][j]);

        // cout << "check [" << u << ", " << sz[u] << "]\n";
        // FOR(i, 1, sz[u]) cout << i << ' ' << dp[u][i] << " [] ";
        // cout << "\n";
    };

    dfs(dfs, numNode, 0);

    FOR(i, 1, n) cout << (i < p ? dp[numNode][i] : 0) << ' ';
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t --) {
        solve();
    }

    return 0;
}