#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 1e5;
int n, q;

pair<int, int> a[N + 1];

struct QUERY {
    int x, y, z;
};

QUERY query[N + 1];

struct NODE {
    int val, left, right, sum;
};

NODE node[2 * N + 2];

int L[N + 1], R[N + 1], Ans[N + 1];

NODE merge(NODE x, NODE y) {
    NODE res;

    res.val = max(x.val, max(y.val, x.right + y.left));
    res.left = max(x.left, (x.left == x.sum) * (x.sum + y.left));
    res.right = max(y.right, (y.right == y.sum) * (y.sum + x.right));
    res.sum = x.sum + y.sum;

    return res;
}

void build() {
    FOR(i, 1, n) node[i + n] = NODE{0, 0, 0, 1};

    #define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

    FORD(i, n, 1) node[i] = merge(node[i << 1], node[i << 1 | 1]);
}

void updated(int i) {
    for(node[i += n] = {1, 1, 1, 1}, i >>= 1; i; i >>= 1) {
        node[i] = merge(node[i << 1], node[i << 1 | 1]);
    }
}

NODE base = {0, 0, 0, 0};

NODE get(int l, int r) {
    NODE Left = base, Right = base;

    for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if(l & 1) Left = merge(Left, node[l ++]);
        if(!(r & 1)) Right = merge(node[r --], Right);
    }

    return merge(Left, Right);
}

vector<int> bucket[N + 1];

void parallelBinarySearch() {
    while(1) {
        bool ok = 0;
        FOR(i, 1, n) bucket[i].clear();

        FOR(i, 1, q) if(L[i] <= R[i]) {
            int mid = (L[i] + R[i]) >> 1;
            ok = 1;
            bucket[mid].push_back(i);
        }

        if(!ok) break;

        build();
    
        FOR(i, 1, n) {
            updated( a[i].second);
            for(auto id : bucket[i]) {
                auto [x, y, z] = query[id];
                if(get(x, y).val >= z) {
                    R[id] = i - 1;
                    Ans[id] = i;
                } else L[id] = i + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;

    FOR(i, 1, n) cin >> a[i].first, a[i].second = i;

    sort(a + 1, a + n + 1, greater<pair<int, int>>());

    cin >> q;

    FOR(i, 1, q) {
        int x, y, z; cin >> x >> y >> z;
        query[i] = {x, y, z}; L[i] = 1, R[i] = n, Ans[i] = 0;
    }

    parallelBinarySearch();

    FOR(i, 1, q) cout << a[Ans[i]].first << "\n";
}