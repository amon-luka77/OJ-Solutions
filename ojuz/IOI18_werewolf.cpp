#ifndef Amon
#include "werewolf.h"
#endif

#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
using namespace std;

const int N = 2e5, LOG = 20;

struct krt {
    int parent[N + 1], sz[N + 1], val[2 * N + 1], par[2 * N + 1][LOG + 1], bestNode[2 * N + 1];
    vector<int> edge[2 * N + 1]; int n, numNode, pos[N + 1];
    int L[2 * N + 1], R[2 * N + 1], timeDfs = 0;

    bool ok = 0;

    int find_set(int k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

    void add(int u, int v) {edge[u].push_back(v);}

    inline int amon (int u, int v) {return (ok ? max(u, v) : min(u, v));}

    void union_set(int u, int v) {
        if((u = find_set(u)) == (v = find_set(v))) return;
        ++numNode; add(numNode, bestNode[u]); add(numNode, bestNode[v]);
        val[numNode] = amon(val[bestNode[u]], val[bestNode[v]]);
        if(sz[u] < sz[v]) swap(u, v); 
        sz[u] += sz[v]; parent[v] = u; bestNode[u] = numNode;
    }


    void dfs(int u, int p = 0) {
        if(u <= n) return par[u][0] = p, pos[u] = ++timeDfs, L[u] = R[u] = timeDfs, void();

        int l = edge[u][0], r = edge[u][1]; par[l][0] = u, par[r][0] = u;

        dfs(l, u), dfs(r, u);

        L[u] = min(L[l], L[r]), R[u] = max(R[l], R[r]);
        // val[u] = amon(val[l], val[r]);
    }

    void build(const vector<pair<int, int>> &xx, int _n, bool type) {
        ok = type; n = numNode = _n;
        FOR(i, 1, n) parent[i] = bestNode[i] = i, sz[i] = 1, val[i] = i;

        for(auto &[x, y] : xx) union_set(x, y);

        dfs(2 * n - 1);

        // cerr << "\n----------\n";
        // for(int i = numNode; i > 0; i --) {
        //     cerr << "edge: " << i << " val: " << val[i][0] << "\n";
        //     for(auto j : edge[i]) cerr << j << ", ";
        //     cerr << "\n"; 
        // }
        // cerr << "\n----------\n";

        FOR(j, 1, LOG) FOR(i, 1, 2 * n - 1) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }

    pair<int, int> jump(int u, int value) {
        for(int i = LOG; i >= 0; i --) if(par[u][i] && (ok ? (val[par[u][i]] <= value) : (val[par[u][i]] >= value))) {
            u = par[u][i];
        } return make_pair(L[u], R[u]);
    }
    
} minT, maxT;

vector<int> check_validity(int maxN, vector<int> X, vector<int> Y,
                                vector<int> S, vector<int> E,
                                vector<int> L, vector<int> R) {
    
    int n = maxN, m = X.size();

    vector<pair<int, int>> edge(m);

    FOR(i, 0, m - 1) {
        int x = X[i] + 1, y = Y[i] + 1;
        edge[i] = {x, y};
    }

    int q = S.size();

    #define ft first 
    #define sc second

    vector<int> ans(q, 0);

    #define all(x) (x).begin(), (x).end()
    sort(all(edge), [&](const pair<int, int> &x, const pair<int ,int> &y) {return min(x.first, x.second) > min(y.first, y.second);});
    minT.build(edge, n, 0);

    sort(all(edge), [&](const pair<int, int> &x, const pair<int ,int> &y) {return max(x.first, x.second) < max(y.first, y.second);});
    maxT.build(edge, n, 1);

    struct Event {
        int y1, y2, id, sign;
    };

    vector<vector<Event>> event(n + 1);
    vector<int> pos(n + 1);

    FOR(i, 1, n) pos[minT.pos[i]] = maxT.pos[i];

    // FOR(i, 1, n) cout << "check " << i << ' ' << maxT.pos[i] << ' ' << minT.pos[i] << "\n"; 
 
    FOR(i, 0, q - 1) {
        int u = S[i] + 1, v = E[i] + 1;
        int l = L[i] + 1, r = R[i] + 1;
        // auto [u, v] = {S[i] + 1, E[i] + 1};
        // auto [l, r] = {L[i] + 1, R[i] + 1};
        // u->i min >= l
        auto x = minT.jump(u, l), y = maxT.jump(v, r);
        
        // cout << "dinh: " << u << ' ' << x.ft << ' ' << x.sc << "\n";
        // cout << "dinh: " << v << ' ' << y.ft << ' ' << y.sc << "\n";

        if(x.ft - 1 >= 1) event[x.ft - 1].push_back({y.ft, y.sc, i, -1});
        event[x.sc].push_back({y.ft, y.sc, i, 1});
    }

    vector<int> bit(n + 1, 0), sum(q + 1);

    auto updated = [&](int i) {for(; i <= n; i += i & -i) bit[i] ++;};

    auto get = [&](int i) {int res = 0; for(; i; i -= i & -i) res += bit[i]; return res;};

    auto getSum = [&](int l, int r) {return get(r) - get(l - 1);};

    FOR(i, 1, n) {
        updated(pos[i]);
        for(auto x : event[i]) {
            sum[x.id] += x.sign * getSum(x.y1, x.y2);
        }
    }


    FOR(i, 0, q - 1) ans[i] = (sum[i] > 0);

    return ans;
}

#ifdef Amon

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, q;

    cin >> n >> m >> q;
    vector<int> a(m), b(m); 

    FOR(i, 0, m - 1) cin >> a[i];
    FOR(i, 0, m - 1) cin >> b[i];

    vector<int> x(q), y(q), e(q), s(q);

    FOR(i, 0, q - 1) cin >> s[i];
    FOR(i, 0, q - 1) cin >> e[i];
    FOR(i, 0, q - 1) cin >> x[i];
    FOR(i, 0, q - 1) cin >> y[i];
        

    vector<int> xx = check_validity(n, a, b, s, e, x, y);

    // if(xx.empty()) cout << 11111;
    for(auto i : xx) cout << i << ' ';
}

#endif