#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    const int N = 2e5;

    static ll a[N + 1];
    static vector<int> edge[N + 1];

    #define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
    #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

    FOR(i, 1, n) cin >> a[i];

    for(int i = 1, x, y; i <= n - 1 && cin >> x >> y; i ++) {
        edge[x].push_back(y); edge[y].push_back(x);
    }

    static struct Segtree {
        int n; ll node[2 * N + 1];

        Segtree(int _n) {
            n = _n;
        }

        void updated(int i, ll val) {
            for(node[i += n] = val, i >>= 1; i >= 1; i >>= 1) {
                node[i] = max(node[i << 1], node[i << 1 | 1]);
            }
        }

        ll getMax(int l, int r) {
            ll res = 0;
            for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
                if((l & 1)) res = max(res, node[l ++]);
                if(!(r & 1)) res = max(res, node[r --]);
            }
            return res;
        }
    } node(n);

    static int high[N + 1], head[N + 1], par[N + 1], in[N + 1], out[N + 1], sz[N + 1];

    auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
        sz[u] = 1; par[u] = p;
        for(auto &v : edge[u]) if(v != p) {
            high[v] = high[u] + 1;
            self(self, v, u);
            sz[u] += sz[v];
            if(edge[u][0] == p || sz[v] > sz[edge[u][0]]) {
                swap(v, edge[u][0]);
            }
        }
    };

    int timeDfs = 0;
    auto hld = [&](auto &self, int u = 1, int p = 0) -> void {
        in[u] = ++timeDfs; node.updated(in[u], a[u]);
        for(auto v : edge[u]) if(v != p) {
            head[v] = v == edge[u][0] ? head[u] : v;
            self(self, v, u);      
        } out[u] = timeDfs;
    };

    auto queryPath = [&](int u, int v) {
        ll res = 0;
        while(head[u] != head[v]) {
            if(high[head[u]] < high[head[v]]) swap(u, v);
            res = max(res, node.getMax(in[head[u]], in[u]));
            u = par[head[u]];
        }
        if(in[u] > in[v]) swap(u, v);
        res = max(res, node.getMax(in[u], in[v]));
        return res;
    };

    dfs(dfs); hld(hld);

    while(q --) {
        int opt; cin >> opt;
        if(opt == 1) {
            int s; ll val; cin >> s >> val;
            node.updated(in[s], val);
        } else {
            int x, y; cin >> x >> y;
            cout << queryPath(x, y) << " ";
        }
    }
}