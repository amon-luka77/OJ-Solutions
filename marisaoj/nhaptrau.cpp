
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Chiến thuật sai: Liên tục tìm đỉnh có bậc (degree) lớn nhất hiện tại chưa bị xóa,
// tham ăn chọn đỉnh đó vào tập độc lập, sau đó loại bỏ đỉnh đó và các đỉnh kề với nó.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("test.out", "r", stdin);
    freopen("test.inp", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> deg(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    vector<bool> removed(n + 1, false);
    int ans = 0;

    while (true) {
        int max_deg = -1, best_u = -1;
        for (int i = 1; i <= n; i++) {
            if (!removed[i] && deg[i] > max_deg) {
                max_deg = deg[i];
                best_u = i;
            }
        }

        if (best_u == -1 || max_deg < 0) break;

        ans++;
        removed[best_u] = true;
        for (int v : adj[best_u]) {
            if (!removed[v]) {
                removed[v] = true;
                for (int w : adj[v]) {
                    deg[w]--;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
