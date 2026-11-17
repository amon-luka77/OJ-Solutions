#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

template<typename T, typename U>
pair<T, U>& operator += (pair<T, U> &x, const pair<T, U> &y) {
    x.first += y.first, x.second += y.second;
    return x;
}
template<typename T, typename U>
pair<T, U>& operator -= (pair<T, U> &x, const pair<T, U> &y) {
    x.first -= y.first, x.second -= y.second;
    return x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;

    const int N = 1e5;

    static vector<int> edge[N + 1];
    static pair<int, int> edgeId[N + 1];

    for(int i = 1, x, y; i <= n - 1 && cin >> x >> y; i ++) {
        edge[x].push_back(y); edge[y].push_back(x); edgeId[i] = {x, y};
    }

    static pair<int, int> tram[N + 1];

    #define ft first
    #define sc second

    FOR(i, 1, m) cin >> tram[i].ft >> tram[i].sc;
    sort(tram + 1, tram + m + 1, [&](const auto &x, const auto &y) {return x.sc < y.sc;});

    static struct QUERY {
        int startNode, endNode, gold, id; ll silver;
    } query[N + 1];

    static int L[N + 1], R[N + 1], Ans[N + 1];

    FOR(i, 1, q) {
        cin >> query[i].startNode >> query[i].endNode >> query[i].gold >> query[i].silver;
        L[i] = 1, R[i] = m, query[i].id = i;
    }

    static int par[N + 1], head[N + 1], sz[N + 1], in[N + 1], out[N + 1];

    auto dfs = [&](auto &self, int u = 1, int p = 0) -> void {
        sz[u] = 1; par[u] = p;
        for(auto &v : edge[u]) if(v != p) {
            self(self, v, u);
            sz[u] += sz[v];
            if(edge[u][0] == p || sz[v] > sz[edge[u][0]]) {
                swap(v, edge[u][0]);
            }
        }
    };

    int timeDfs = 0;
    auto hld = [&](auto &self, int u = 1, int p = 0) -> void {
        in[u] = ++timeDfs;
        for(auto &v : edge[u]) if(v != p) {
            head[v] = v == edge[u][0] ? head[u] : v;
            self(self, v, u);
        } out[u] = timeDfs;
    };

    static struct FenwickTree {
        int n; 
        pair<ll, int> bit[N + 1];

        FenwickTree(int _n) {n = _n;}

        void reset() {FOR(i, 1, n) bit[i] = {0LL, 0};}

        void updated(int i, pair<ll, int> val) {for(; i <= n; i += i & -i) bit[i] += val;}

        pair<ll, int> get(int l, int r) {
            pair<ll, int> res = {0, 0}; if(l > r) return {0LL, 0};
            for(l --; l; l -= l & -l) res -= bit[l];
            for(; r; r -= r & -r) res += bit[r];
            return res;
        }
    } bit(n);

    auto updatedQuery = [&](int i) -> void {
        auto [id, val] = tram[i];
        auto [x, y] = edgeId[id];

        if(in[x] < in[y]) bit.updated(in[y], {val, 1});
        else bit.updated(in[x], {val, 1});
    };

    auto queryPath = [&](int u, int v) {
        pair<ll, int> res = {0LL, 0};

        while(head[u] != head[v]) {
            if(in[head[u]] < in[head[v]]) swap(u, v);
            res += bit.get(in[head[u]], in[u]);
            u = par[head[u]];
        }

        if(in[u] > in[v]) swap(u, v);
        res += bit.get(in[u] + 1, in[v]);

        return res;
    };

    auto parallelBinarySearch = [&]() {
        static vector<int> bucket[N + 1];

        while(1) {
            bool ok = 0;
            FOR(i, 1, m) bucket[i].clear();

            FOR(i, 1, q) if(L[i] <= R[i]) {
                int mid = (L[i] + R[i]) >> 1;
                ok = 1;
                bucket[mid].push_back(i);
            } if(!ok) break;

            bit.reset();

            FOR(i, 1, m) {
                updatedQuery(i);
                for(auto id : bucket[i]) {
                    auto [sum, cnt] = queryPath(query[id].startNode, query[id].endNode);
                    if(sum <= query[id].silver) {
                        L[id] = i + 1, Ans[id] = cnt;
                    } else R[id] = i - 1;
                }
            }
        }
    };

    dfs(dfs); 
    hld(hld);
    parallelBinarySearch();

    bit.reset();
    FOR(i, 1, m) updatedQuery(i);

    FOR(i, 1, q) {
        int sum = queryPath(query[i].startNode, query[i].endNode).sc - Ans[i];
        cout << (query[i].gold < sum ? -1 : query[i].gold - sum) << "\n";
    }
}