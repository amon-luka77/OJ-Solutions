#include<bits/stdc++.h>
#define ll long long
#define int long long 

using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    const int N = 2e5, mod = 998244353;
    static vector<int> edge[N + 1];

    #define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
    #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

    struct NODE {
        ll a = 1, b = 0;

        NODE operator + (NODE other) const {
            NODE res;
            // ax + b;
            // cx + d
            // a(cx + d) + b
            res.a = a * other.a % mod;
            res.b = (b + a * other.b % mod) % mod;
            return res; 
        }
    };

    struct DATA {
        NODE up, down;

        DATA operator + (DATA other) const {
            DATA res;
            res.up = up + other.up;
            res.down = other.down + down;
            return res; 
        }
    };

    static NODE a[N + 1];

    FOR(i, 1, n) cin >> a[i].a >> a[i].b;
    for(int i = 1, x, y; i < n && cin >> x >> y; i ++) {
        edge[x].push_back(y); edge[y].push_back(x);
    }
        
    struct Segtree {
        int n;

        DATA node[2 * N + 1];

        Segtree(int _n, int in[], NODE a[]) {
            n = _n; 
            FOR(i, 1, n) node[in[i] + n - 1] = DATA{a[i], a[i]};
            FORD(i, n - 1, 1) node[i] = node[i << 1] + node[i << 1 | 1];
        }

        void updated(int i, NODE val) {
            for(node[i += n - 1] = DATA{val, val}, i >>= 1; i; i >>= 1) {
                node[i] = node[i << 1] + node[i << 1 | 1];
            }
        }

        NODE get(int l, int r, bool ok) {
            NODE left, right;

            for(l += n - 1, r += n - 1; l <= r; l >>= 1, r >>= 1) {
                if(l & 1) left = (ok ? left + node[l ++].up : node[l ++].down + left);
                if(!(r & 1)) right = (ok ? node[r --].up + right : right + node[r --].down);
            }

            return (ok ? left + right : right + left);
        }
    };

    static int par[N + 1], in[N + 1], out[N + 1], sz[N + 1], head[N + 1], high[N + 1];
    int timeDfs = 0;

    auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
        sz[u] = 1;
        for(auto &v : edge[u]) if(v != p) {
            par[v] = u; high[v] = high[u] + 1;
            self(self, v, u);
            sz[u] += sz[v];
            if(edge[u][0] == p || sz[v] > sz[edge[u][0]]) {
                swap(v, edge[u][0]);
            }
        }
    }; dfs(dfs);

    auto hld = [&](auto &self, int u = 1, int p = 0) -> void {
        in[u] = ++timeDfs;
        for(auto &v : edge[u]) if(v != p) {
            head[v] = v == edge[u][0] ? head[u] : v;
            self(self, v, u);
        } out[u] = timeDfs;
    }; hld(hld);

    static Segtree node(n, in, a);

    auto queryPath = [&](int u, int v, ll val) {
        NODE left, right;

        while(head[u] != head[v]) {
            if(high[head[u]] >= high[head[v]]) left = node.get(in[head[u]], in[u], 1) + left, u = par[head[u]];
            else right = right + node.get(in[head[v]], in[v], 0), v = par[head[v]];
        }
        
        if(in[u] >= in[v]) left = node.get(in[v], in[u], 1) + left;
        else right = right + node.get(in[u], in[v], 0);

        NODE res = right + left;

        cout << ((res.a * val) % mod + res.b) % mod << "\n";
    };

    while(q --) {
        int opt, x, y; ll val; cin >> opt >> x >> y >> val;
        if(opt == 0) node.updated(in[x], NODE{y, val});
        else queryPath(x, y, val);
    }
}