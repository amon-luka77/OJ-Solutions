#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    const int N = 2e5;

    int n, m, q; cin >> n >> m >W1W3> q;

    static pair<int, int> edge[N + 1];

    FOR(i, 1, m) cin >> edge[i].first >> edge[i].second;

    static int parent[N + 1], sz[N + 1], parity[N + 1], cnt = 0;
    static stack<tuple<int, int, int, int>> history; 

    FOR(i, 1, n) parent[i] = i, sz[i] = 1;

    auto find_set = [&] (int u) -> pair<int, int> {
        int p = 0;
        while(u != parent[u]) {
            p ^= parity[u];
            u = parent[u];
        }
        return {u, p};
    };

    auto union_set = [&] (int u, int v) -> void {
        auto [uu, pu] = find_set(u);
        auto [vv, pv] = find_set(v);

        if(uu != vv) {
            if(sz[uu] < sz[vv]) swap(uu, vv);
            history.push({uu, vv, sz[uu], parity[vv]});
            parent[vv] = uu; sz[uu] += sz[vv];
            parity[vv] = pu ^ pv ^ 1; 
        } else {
            if(pu == pv) cnt ++, history.push({-1, 0, 0, 0});
        }
    };

    auto rollback = [&](int roll) -> void {
        while(history.size() > roll) {
            auto [u, v, Size, pa] = history.top(); history.pop();
            if(u == -1) cnt --;
            else {
                parent[v] = v; sz[u] = Size;
                parity[v] = pa;
            }
        }
    };

    static int f[N + 1];

    #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

    auto dnc = [&](auto &self, int l, int r, int optL, int optR) -> void {
        if (l > r) return;
        int mid = (l + r) >> 1;

        int numRoll = history.size();
        FOR(i, l, mid - 1) union_set(edge[i].first, edge[i].second);

        int pos = max(mid - 1, optL);
        if (cnt) {
            pos = optR;
        } else {
            FORD(i, min(optR, m), max(mid, optL + 1)) {
                union_set(edge[i].first, edge[i].second);
                if (cnt) {
                    pos = i;
                    break;
                }
            }
        }

        f[mid] = pos;
        rollback(numRoll);

        numRoll = history.size();
        FOR(i, l, mid) union_set(edge[i].first, edge[i].second);
        self(self, mid + 1, r, f[mid], optR);
        rollback(numRoll);

        numRoll = history.size();
        FOR(i, f[mid] + 1, min(optR, m)) union_set(edge[i].first, edge[i].second);
        self(self, l, mid - 1, optL, f[mid]);
        rollback(numRoll);
    };

    dnc(dnc, 1, m, 1, m + 1);

    while(q --) {
        int l, r; cin >> l >> r;

        cout << (r < f[l] ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t

    while(t --) solve();

    return 0;
}