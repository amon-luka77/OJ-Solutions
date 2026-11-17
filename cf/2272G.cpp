#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    const int N = 2e5;

    int n, m, q; cin >> n >> m >> q;

    static pair<int, int> edge[N + 1], newEdge[N + 1];
    static int startEdgeId[N + 1];

    FOR(i, 1, m) startEdgeId[i] = 1;
    
    for(int i = 1, x, y; i <= m && cin >> x >> y; i ++) {
        y ++;
        if(x > y) swap(x, y);
        edge[i] = {x, y}; newEdge[i] = {x, y};
    }
    
    static int parent[N + 2], sz[N + 2];
    FOR(i, 1, n + 1) parent[i] = i, sz[i] = 1;

    static vector<pair<int, int>> node[4 * N + 1];
    FOR(i, 1, 4 * q) node[i].clear();

    #define ls id << 1
    #define rs id << 1 | 1

    auto updated = [&](auto &self, int id, int l, int r, int i, int j, pair<int, int> val) -> void {
        if(l > r || i > j || l > j || r < i) return;
        
        if(i <= l && r <= j) return node[id].push_back(val), void();
        int mid = (l + r) >> 1;
        
        self(self, ls, l, mid, i, j, val); self(self, rs, mid + 1, r, i, j, val);
    };


    auto find_set = [&](auto &self, int k) -> int {return k == parent[k] ? k : self(self, parent[k]);};

    stack<tuple<int, int, int>> st;

    auto union_set = [&](int u, int v, bool ok) {
        int x = find_set(find_set, u), y = find_set(find_set, v);

        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            if(ok) st.push({x, y, sz[x]});
            parent[y] = x; sz[x] += sz[y];
        }
    };

    auto check = [&](int u,  int v) {
        return find_set(find_set, u) != find_set(find_set, v);
    };

    static int res = 0;
    res = 0;

    auto rollback = [&](int cnt) {
        while(cnt --) {
            auto [x, y, Size] = st.top(); st.pop();
            parent[y] = y; sz[x] = Size; res --;
        }
    };

    #define ft first
    #define sc second
        
    sort(newEdge + 1, newEdge + m + 1, [](auto &x, auto &y) {return (x.sc - x.ft + 1) < (y.sc - y.ft + 1);});
    FOR(i, 1, m) if(check(newEdge[i].ft, newEdge[i].sc)) {
        union_set(newEdge[i].ft, newEdge[i].sc, 0); res ++; 
    } cout << res << "\n";

    res = 0; FOR(i, 1, n + 1) parent[i] = i, sz[i] = 1;

    auto dfs = [&](auto &self, int id, int l, int r) -> void {
        sort(node[id].begin(), node[id].end(), [](auto &x, auto &y) {return (x.sc - x.ft + 1) < (y.sc - y.ft + 1);});
        int numRollback = 0; 
        for(auto &[x, y] : node[id]) if(check(x, y)) {
            union_set(x, y, 1); numRollback ++; res ++; 
            // if(l == r && l == 3) cout << "[" << x << ", " << y << "], ";
            // cout << "\n";
            // cout << "amon\n";
        }

        int mid = (l + r) >> 1;

        if(l == r) {
            cout << res << "\n";
            // cout << "numId: " << l << "\n";
            // for(auto &[x, y] : node[id]) cout << "[" << x << ", " << y << "], ";
            // cout << "\n";
            rollback(numRollback); return;
        } else {
            self(self, ls, l, mid), self(self, rs, mid + 1, r);
        }

        rollback(numRollback);
    };

    for(int i = 1, p, l, r; i <= q && cin >> p >> l >> r; i ++) {
        r ++;
        updated(updated, 1, 1, q, startEdgeId[p], i - 1, edge[p]);
        if(l > r) swap(l, r);
        edge[p] = {l, r};
        startEdgeId[p] = i;
    }

    FOR(i, 1, m) updated(updated, 1, 1, q, startEdgeId[i], q, edge[i]);

    // cout << "\n---------------\n";
    dfs(dfs, 1, 1, q);
    // cout << "\n---------------\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}