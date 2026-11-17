#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;

    const int N = 5e5;

    static vector<int> edge[N + 1];
    static set<pair<int, int>> color[N + 1];
    static int a[N + 1];

    FOR(i, 1, n) cin >> a[i];

    for(int i = 1, x, y; i < n && cin >> x >> y; i ++) {
        edge[x].push_back(y); edge[y].push_back(x);
    }

    const int LOG = 20;
    int timeDfs = 0;
    int cntPos = 0; 

    static int high[N + 1], in[N + 1], out[N + 1];
    static int posEuler[N + 1], euler[2 * N + 1], minHigh[2 * N + 1][LOG + 1];

    auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
        in[u] = ++timeDfs; 
        color[a[u]].insert({in[u], u});
        euler[++cntPos] = u; posEuler[u] = cntPos;
        for(auto &v : edge[u]) if(v != p) {
            high[v] = high[u] + 1;
            self(self, v, u);
            euler[++cntPos] = u;
        } out[u] = timeDfs;
    }; dfs(dfs);

    #define BIT(x, i) (((x) >> (i)) & 1LL)
    #define MASK(i) (1LL << (i))

    #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

    FOR(i, 1, cntPos) minHigh[i][0] = euler[i];

    #define MIN_HIGH(x, y) (high[x] < high[y] ? x : y)
    FOR(j, 1, LOG) FOR(i, 1, cntPos - MASK(j) + 1) {
        minHigh[i][j] = MIN_HIGH(minHigh[i][j - 1], minHigh[i + MASK(j - 1)][j - 1]);
    }

    auto lca = [&](int u, int v) {
        auto l = posEuler[u], r = posEuler[v];
        if(l > r) swap(l, r);
        int k = __lg(r - l + 1);
        return MIN_HIGH(minHigh[l][k], minHigh[r - MASK(k) + 1][k]);
    };

    // FOR(i, 1, n) cout << par[i][0] << ' ';
    // cout << "\n";
    // cout << "LCA: " << lca(4, 3) << "\n";

    static struct Segtree {
        int n; int node[2 * N + 2];

        Segtree(int _n) {
            n = _n;
        }

        void build(int a[]) {
            FOR(i, 1, n) node[i + n] = a[i];
            FORD(i, n, 1) node[i] = node[i << 1] + node[i << 1 | 1];
        }

        void updated(int i, int val) {for(node[i += n] += val, i >>= 1; i; i >>= 1) node[i] = node[i << 1] + node[i << 1 | 1];}

        int getSum(int l, int r) {
            int res = 0;
            for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
                if(l & 1) res += node[l ++];
                if(!(r & 1)) res += node[r --];
            } return res;
        }
    } node(n);

    #define sc second

    static int base[N + 1];
    FOR(i, 1, n) base[i] = 1;

    FOR(i, 1, m) {
        for(auto it = color[i].begin(); it != color[i].end() && next(it) != color[i].end(); it ++) {
            base[in[lca(it->sc, next(it)->sc)]] --;
        }
    }

    node.build(base);

    auto updatedQuery = [&](int i, int val) {
        auto &aa = color[a[i]];
        auto it = aa.find({in[i], i});

        auto l = (it == aa.begin() ? aa.end() : prev(it));
        auto r = next(it);

        if(l != aa.end()) node.updated(in[lca(l->sc, i)], 1);
        if(r != aa.end()) node.updated(in[lca(r->sc, i)], 1);
        if(l != aa.end() && r != aa.end()) node.updated(in[lca(l->sc, r->sc)], -1);

        aa.erase(it); color[val].insert({in[i], i}); a[i] = val;

        auto &bb = color[val];
        it = bb.find({in[i], i});

        l = (it == bb.begin() ? bb.end() : prev(it));
        r = next(it);

        if(l != bb.end()) node.updated(in[lca(l->sc, i)], -1);
        if(r != bb.end()) node.updated(in[lca(r->sc, i)], -1);
        if(l != bb.end() && r != bb.end()) node.updated(in[lca(l->sc, r->sc)], 1);
    };

    while(q --) { 
        int opt, x, y; cin >> opt >> x;
        if(opt == 1) {
            cin >> y; 
            updatedQuery(x, y);
        } else cout << node.getSum(in[x], out[x]) << "\n";
    }
}
