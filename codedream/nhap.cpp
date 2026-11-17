#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int t; cin >> t;

    const int N = 2e5;
    static vector<int> edge[N + 1];
    static int sz[N + 1];
    
    while(t --) {
        int n; cin >> n;
        FOR(i, 1, n) edge[i].clear();
        for(int i = 1, x, y; i < n && cin >> x >> y; i ++) {
            edge[x].push_back(y); edge[y].push_back(x);
        }

        auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
            sz[u] = 1;
            for(auto &v : edge[u]) if(v != p) {
                self(self, v, u);
                sz[u] += sz[v];
            }
        };

        dfs(dfs); 
        
        static int b[N + 1];
        int pos = 0;
        for(auto &i : edge[1]) b[++pos] = sz[i];

        sort(b + 1, b + pos + 1, greater<int>());

        cout << (pos <= 2 ? n : n - b[3]) << "\n";
    }
}