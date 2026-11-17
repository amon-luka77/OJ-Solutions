#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;
const int N = 3e5;

struct QUERY {
    int x, y, z;

    bool operator < (const QUERY &other) const {
        return x > other.x;
    }
};

static QUERY query[N + 1];
static int a[N + 1];

int bit[N + 1];

void updated(int i, int n) {
    for(; i <= n; i += i & -i) bit[i] ++;
}

int get(int i) {
    int res = 0;
    for(; i > 0; i -= i & -i) res += bit[i];
    return res;
}

int getSum(int l, int r) {
    return get(r) - get(l - 1);
}

vector<int> edge[N + 1];

int maxEdge[N + 1];
pair<int, int> b[N + 1];
int tin[N + 1], tout[N + 1];

void testcase() {
    int n; cin >> n;

    FOR(i, 1, n) {
        edge[i].clear();
        bit[i] = 0;
        maxEdge[i] = 0;
    }

    FOR(i, 1, n - 1) {
        int x, y; cin >> x >> y; x ++; y ++;
        edge[x].push_back(y); edge[y].push_back(x);
    }

    #define all(x) (x).begin(), (x).end()
    FOR(i, 1, n) sort(all(edge[i]));

    int timeDfs = 0, pos = 0;

    auto dfsPos = [&] (auto &self, int u, int par) -> void {
        tin[u] = ++timeDfs; a[timeDfs] = u;
        for(auto i : edge[u]) if(i != par) {
            self(self, i, u);
            maxEdge[u] = max(maxEdge[u], i);
        }
        tout[u] = timeDfs;
        query[++pos] = QUERY{maxEdge[u], tin[u], tout[u]};
    };

    int res = 0;

    dfsPos(dfsPos, 1, 0);

    // FOR(i, 1, n) res += (maxEdge[i] < a[tout[i] + 1]);

    FOR(i, 1, n) b[i] = {i, tin[i]};
    sort(b + 1, b + n + 1, greater<pair<int, int>>());
    sort(query + 1, query + n + 1);
    
    int i = 1;

    FOR(j, 1, n) {
        auto [val, l, r] = query[j];
        while(i <= n && b[i].first > val) updated(b[i ++].second, n);
        res += getSum(l, r);
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int tt; cin >> tt;

    while(tt --) testcase();
}