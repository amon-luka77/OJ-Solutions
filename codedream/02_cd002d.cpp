#include<bits/stdc++.h>
#define ll long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 1e5;

int n, m;
pair<int, int> a[N + 1];

struct QUERY {
    int x, y, z;
} query[N + 1];

int parent[N + 1], sz[N + 1];

int L[N + 1], R[N + 1], Ans[N + 1];

int q;

int find_set(int k) {return k == parent[k] ? k : parent[k] = find_set(parent[k]);}

void union_set(int u, int v) {
    int x = find_set(u), y = find_set(v);

    if(x != y) {
        if(sz[x] < sz[y]) swap(x, y);
        parent[y] = x; sz[x] += sz[y];
    }
}

bool check(int x, int y, int z) {
    int xx = find_set(x), yy = find_set(y);

    int sum = xx == yy ? sz[xx] : sz[xx] + sz[yy];

    return sum >= z;
}

void ParallelBinarySearch() {
    vector<vector<int>> bucket(m + 1);

    while(1) {
        bool ok = 0;
        FOR(i, 1, m) bucket[i].clear();

        FOR(i, 1, q) if(L[i] <= R[i]) {
            int mid = (L[i] + R[i]) >> 1;
            ok = 1;
            bucket[mid].push_back(i);
        }

        if(!ok) break;

        FOR(i ,1, n) parent[i] = i, sz[i] = 1;

        FOR(i, 1, m) {
            union_set(a[i].first, a[i].second);

            for(auto id : bucket[i]) {
                auto [x, y, z] = query[id];
                if(check(x, y, z)) {
                    R[id] = i - 1;
                    Ans[id] = i;
                } else L[id] = i + 1;
            }
        }

        // FOR(i, 1, q) cout << Ans[i] << ' ';
        // cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    FOR(i, 1, m) cin >> a[i].first >> a[i].second;
    cin >> q;
    FOR(i, 1, q) {
        int x, y, z; cin >> x >> y >> z;
        query[i] = {x, y, z};
        L[i] = 1, R[i] = m, Ans[i] = 0;
    }

    ParallelBinarySearch();

    FOR(i, 1, q) cout << Ans[i] << "\n";
}