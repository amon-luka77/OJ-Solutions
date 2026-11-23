#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    const int N = 4e5;

    int n, m; cin >> n >> m;

    static pair<int, int> a[N + 1];

    #define ft first 
    #define sc second

    static int limit = 0;

    FOR(i, 1, n) cin >> a[i].ft >> a[i].sc, limit = max(limit, a[i].sc);

    const int maxN = 8e6;

    static bool vs[maxN + 1], mark[maxN + 1];
    static vector<int> edge[maxN + 1];
    static vector<pair<int, int>> node[4 * N + 1];
    static int parent[N + 1], sz[N + 1], comp[N + 1];

    auto find_set = [&](int k) {
        while(k != parent[k]) k = parent[k];
        return k;
    };

    static stack<pair<int, int>> st;

    static int numEdge;
    numEdge = n;

    FOR(i, 1, n) parent[i] = comp[i] = i, sz[i] = 1;

    auto union_set = [&](int u, int v) {
        int x = find_set(u), y = find_set(v);

        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            ++numEdge ;st.push({y, comp[x]});

            parent[y] = x; sz[x] += sz[y];

            edge[numEdge].push_back(comp[x]);
            edge[numEdge].push_back(comp[y]);

            comp[x] = numEdge;
        }
    };

    auto rollback = [&](int cnt) {
        while(st.size() > cnt) {
            auto [y, id] = st.top(); st.pop();
            int x = parent[y];

            comp[x] = id; sz[x] -= sz[y]; parent[y] = y;
        }
    };

    auto updated = [&](auto &self, int id, int l, int r, int i, int j, pair<int, int> val) -> void {
        if(l > r || i > j || l > j || r < i) return;
        if(l == i && r == j) return node[id].push_back(val), void();
        int mid = (l + r) >> 1;
        
        if(j <= mid) self(self, id << 1, l, mid, i, j, val);
        else if(i > mid) self(self, id << 1 | 1, mid + 1, r, i, j, val);
        else self(self, id << 1, l, mid, i, mid, val), self(self, id << 1 | 1, mid + 1, r, mid + 1, j, val);
    };

    auto dfs = [&](auto &self, int id, int l, int r) -> void {
        auto numRoll = st.size();
        // if(!node[id].empty()) {
        //     cout << id << "; ";
        //     for(auto &[x, y] : node[id]) cout << "[" << x << ", " << y << "], ";
        //     cout << "\n";
        // }

        for(auto &[x, y] : node[id]) union_set(x, y);

        if(l == r) {
            if(a[1].ft <= l && l <= a[1].sc) mark[comp[find_set(1)]] = 1;
            
        } else {
            int mid = (l + r) >> 1;
            self(self, id << 1, l, mid);
            self(self, id << 1 | 1, mid + 1, r);
        }

        rollback(numRoll);
    };

    FOR(i, 1, m) {
        int x, y; cin >> x >> y;
        int l = max(a[x].ft, a[y].ft);
        int r = min(a[x].sc, a[y].sc);

        // cerr << "ca;lsdfj: " << l << ' ' << r << "\n";

        if(l <= r) updated(updated, 1, 1, limit, l, r, make_pair(x, y));
    }

    dfs(dfs, 1, 1, limit);

    queue<int> q;

    mark[1] = 1;
    FOR(i, 1, numEdge) if(mark[i]) q.push(i), vs[i] = 1;

    // FOR(i, 1, numEdge) for(auto j : edge[i]) cout << i << ' ' << j << "\n";

    while(!q.empty()) {
        int x = q.front(); q.pop();

        for(auto i : edge[x]) if(!vs[i]) {
            vs[i] = 1;
            q.push(i);
        }
    }

    FOR(i, 1, n) if(vs[i]) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t --) solve();

    return 0;
}