#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 50005;

int n, m, k;

pair<int,int> edge[N];

struct Query {
    int l, r, id;
};

vector<Query> query;
int ans[N];

int parent[N], sz[N];
int components;

stack<pair<int*, int>> st;

void initDSU() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    components = n;
    while (!st.empty()) st.pop();
}

int find_set(int v) {
    while (v != parent[v]) v = parent[v];
    return v;
}

void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);

    st.push({&parent[b], parent[b]});
    st.push({&sz[a], sz[a]});

    parent[b] = a;
    sz[a] += sz[b];

    components--;
}

int snapshot() {
    return st.size();
}

void rollback(int snap) {
    while ((int)st.size() > snap) {
        auto [ptr, val] = st.top();
        st.pop();
        *ptr = val;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edge[i].first >> edge[i].second;
    }

    cin >> k;
    query.resize(k);

    for (int i = 0; i < k; i++) {
        cin >> query[i].l >> query[i].r;
        query[i].id = i;
    }

    int block = sqrt(m);

    sort(query.begin(), query.end(), [&](Query a, Query b) {
        if (a.l / block != b.l / block)
            return a.l < b.l;
        return a.r < b.r;
    });

    for (int i = 0; i < k;) {
        int j = i;

        int block_id = query[i].l / block;

        while (j < k && query[j].l / block == block_id)
            j++;

        initDSU();

        int block_end = (block_id + 1) * block;
        int curR = block_end;

        for (int t = i; t < j; t++) {
            int l = query[t].l;
            int r = query[t].r;

            // ⚠️ CASE đặc biệt: cùng block
            if (l / block == r / block) {
                int snap = snapshot();

                for (int x = l; x <= r; x++) {
                    unite(edge[x].first, edge[x].second);
                }

                ans[query[t].id] = components;

                rollback(snap);
                continue;
            }

            // RIGHT
            while (curR <= r) {
                unite(edge[curR].first, edge[curR].second);
                curR++;
            }

            // LEFT
            int snap = snapshot();

            for (int x = l; x < block_end; x++) {
                unite(edge[x].first, edge[x].second);
            }

            ans[query[t].id] = components;

            rollback(snap);
        }

        i = j;
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}