#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int N = 2e5;
    static int a[N + 1];
    static vector<int> edge[N + 1];

    static int in[N + 1], out[N + 1], nxt[N + 1], sz[N + 1], high[N + 1], par[N + 1];

    #define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

    int n, q; cin >> n >> q;

    FOR(i, 1, n) cin >> a[i];
    
    for(int i = 1, u, v; i <= n - 1 && cin >> u >> v; i ++) {
        edge[u].push_back(v); edge[v].push_back(u);
    }

    struct FenwickTree {
        int n;
        ll bit[N + 1];

        FenwickTree(int _n) {
            n = _n; fill(bit + 1, bit + n + 1, 0);
        }

        void updated(int i, int val) {
            for(; i <= n; i += i & -i) bit[i] += val;
        }

        ll getSum(int l, int r) {
            ll res = 0;
            for(--l; l; l -= l & -l) res -= bit[l];
            for(; r; r -= r & -r) res += bit[r];
            return res;
        }
    } bit(n);

    auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
        sz[u] = 1; par[u] = p;
        for(auto &v : edge[u]) if(v != p) {
            high[v] = high[u] + 1;
            self(self, v, u);
            sz[u] += sz[v];
            if(sz[v] > sz[edge[u][0]]) {
                swap(v, edge[u][0]);
            }
        }
    };

    int timeDfs = 0;
    auto hld = [&] (auto &self, int u = 1, int p = 0) -> void {
        in[u] = ++timeDfs; bit.updated(in[u], a[u]);
        for(auto &v : edge[u]) if(v != p) {
            nxt[v] = (v == edge[u][0] ? nxt[u] : v);
            self(self, v, u);
        } out[u] = timeDfs;
    };

    auto queryPath = [&] (int u, int v) {
        ll sum = 0;
        while(nxt[u] != nxt[v]) {
            if(high[nxt[u]] < high[nxt[v]]) swap(u, v);
            sum += bit.getSum(in[nxt[u]], in[u]);
            u = par[nxt[u]];
        }

        if(in[u] > in[v]) swap(u, v);
        sum += bit.getSum(in[u], in[v]);
        return sum;
    };

    dfs(dfs); hld(hld);

    while(q --) {
        int opt, s, x; cin >> opt >> s;
        if(opt == 1) {
            cin >> x;
            bit.updated(in[s], x - a[s]); a[s] = x;
        } else cout << queryPath(1, s) << "\n";
    }
}