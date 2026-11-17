/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const int N = 1e5;
const int maxQuery = 5e5;

void solve() {
    int n, qq, k; cin >> n >> qq >> k;
    int numQuery = 1;

    struct QUERY {int x, y, z;};

    static vector<QUERY> q[maxQuery + 1];

    static vector<pair<int, int>> node[4 * maxQuery + 1];

    static int parent[N + 1], sz[N + 1];

    FOR(i, 1, qq) {
        int opt, x, y; cin >> opt;
        if(opt == 1) {
            cin >> x >> y;
            q[numQuery].push_back({opt, x, y});
        } else if(opt == 2) {
            cin >> x;
            q[numQuery].push_back({opt, x, 0});
        } else numQuery ++;
    }

    FOR(i, 1, n) parent[i] = i, sz[i] = 1;

    #define ls id << 1
    #define rs id << 1 | 1

    auto updated = [&](auto &self, int id, int l, int r, int i, int j, pair<int, int> val) -> void {
        if(l > r || i > j || l > j || r < i) return;
        
        if(i <= l && r <= j) return node[id].push_back(val), void();
        int mid = (l + r) >> 1;
        
        self(self, ls, l, mid, i, j, val); self(self, rs, mid + 1, r, i, j, val);
    };

    struct HS {int x, y, z;};

    static stack<HS> st;

    auto find_set = [&](auto &self, int k) -> int {return k == parent[k] ? k : self(self, parent[k]);};

    auto union_set = [&](int u, int v) {
        int x = find_set(find_set, u), y = find_set(find_set, v);

        if(x != y) {
            if(sz[x] < sz[y]) swap(x, y);
            st.push(HS{x, y, sz[x]});
            parent[y] = x; sz[x] += sz[y];
        }
    };

    FOR(i, 1, numQuery) for(auto &[opt, x, y] : q[i]) {
        if(opt == 1) {
            int l = i + 1, r = min(numQuery, i + k - 1);
            if(l <= r) updated(updated, 1, 1, numQuery, l, r, make_pair(x, y));
        }
    }

    auto rollback = [&]() {
        while(!st.empty()) {
            auto [x, y, Size] = st.top(); st.pop();
            if(!x) break;
            parent[y] = y; sz[x] = Size;
        }
    };

    auto dfs = [&](auto &self, int id, int l, int r) {
        st.push({0, 0, 0});
        for(auto &[x, y] : node[id]) union_set(x, y);

        int mid = (l + r) >> 1;

        if(l == r) {
            for(auto &[opt, x, y] : q[l]) {
                if(opt == 1) union_set(x, y);
                else cout << sz[find_set(find_set, x)] << "\n";
            }

            // cout << "day: " << l << "\n";
            // FOR(i, 1, n) cout << "[" << i << ", " << sz[find_set(find_set, i)] << "], ";
            // cout << "\n";
            rollback(); return;
        } else self(self, ls, l, mid), self(self, rs, mid + 1, r);

        rollback();
    };

    dfs(dfs, 1, 1, numQuery);

    auto printTree = [&](auto &self, int id, int l, int r) {
        // cout << "nodeID: " << l << ", " << r << "\n";
        // for(auto &[x, y] : node[id]) cout << "[" << x << ", " << y << "]; ";
        // cout << "\n";
        if(l == r) return;

        int mid = (l + r) >> 1;

        self(self, ls, l, mid); self(self, rs, mid + 1, r);
    };

    printTree(printTree, 1, 1, numQuery);
}

int main() {
    boost;
    //file();
    
    int t = 1;
    // cin >> t;

    while(t --) solve();

    return 0;
}