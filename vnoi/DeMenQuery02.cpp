#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    const int N = 3e5;
    static vector<int> edge[N + 1];

    #define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
    #define FORD(i, a, b)for(int i = (a), _b = (b); i >= _b; i --)

    for(int i = 1, x, y; i < n && cin >> x >> y; i ++) {
        edge[x].push_back(y); edge[y].push_back(x);
    }

    static int high[N + 1], par[N + 1], sz[N + 1];

    auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
        sz[u] = 1;
        for(auto &v : edge[u]) if(v != p) {
            high[v] = high[u] + 1; par[v] = u;
            self(self, v, u);
            sz[u] += sz[v];
            if(edge[u][0] == p || sz[v] > sz[edge[u][0]]) {
                swap(v, edge[u][0]);
            }
        } 
    }; dfs(dfs);

    static int in[N + 1], out[N + 1], head[N + 1];
    int timeDfs = 0;

    auto hld = [&](auto &self, int u = 1, int p = 0) -> void {
        in[u] = ++timeDfs;
        for(auto &v : edge[u]) if(v != p) {
            head[v] = v == edge[u][0] ? head[u] : v;
            self(self, v, u);
        } out[u] = timeDfs;
    }; hld(hld);

    static struct Segtree {
        int n, high; 
        ll node[4 * N + 1], lazy[4 * N + 1];

        Segtree(int _n) {
            for(n = 1, high = 0; n < _n; n <<= 1, high ++);
        }

        void pull(int i) {
            for(int len = 2; i >>= 1; len <<= 1) {
                node[i] = max(node[i << 1], node[i << 1 | 1]) + lazy[i];
            }
        }

        void apply(int i, ll val, int len) {
            node[i] += val; lazy[i] += val;
        }

        #define MASK(i) (1LL << (i))

        void push(int p) {
            for(int len = high, i; len; len --) {
                if(lazy[i = p >> len]) {
                    apply(i << 1, lazy[i], MASK(len - 1));
                    apply(i << 1 | 1, lazy[i], MASK(len - 1));
                    lazy[i] = 0;
                }
            }
        }

        void updated(int l, int r, ll val) {
            int curL = l += n - 1, curR = r += n - 1;
            push(curL); push(curR);
            for(int len = 1; l <= r; l >>= 1, r >>= 1, len <<= 1) {
                if(l & 1) apply(l ++, val, len);
                if(!(r & 1)) apply(r --, val, len);
            }
            pull(curL), pull(curR);
        }

        ll getMax(int l, int r) {
            ll res = 0; l += n - 1, r += n - 1;
            push(l), push(r);
            
            for(; l <= r; l >>= 1, r >>= 1) {
                if(l & 1) res = max(res, node[l ++]);
                if(!(r & 1)) res = max(node[r --], res);
            } return res;
        }
    } node(n);

    auto updatedPath = [&](int u, int v, ll val, bool ok) {
        ll res = 0;
        while(head[u] != head[v]) {
            if(in[head[u]] < in[head[v]]) swap(u, v);
            if(!ok) node.updated(in[head[u]], in[u], val);
            else res = max(res, node.getMax(in[head[u]], in[u]));
            u = par[head[u]];
        } if(in[u] > in[v]) swap(u, v);

        if(!ok) node.updated(in[u], in[v], val);
        else cout << max(res, node.getMax(in[u], in[v])) << "\n";
    };

    while(q --) {
        int opt, u, v; ll val;
        cin >> opt >> u;
        if(opt == 1) {
            cin >> v >> val; updatedPath(u, v, val, 0);
        } else if(opt == 2) {
            cin >> val;
            node.updated(in[u], out[u], val);
        } else if(opt == 3) {
            cin >> v; updatedPath(u, v, val, 1);
        } else cout << node.getMax(in[u], out[u]) << "\n";
    }
}