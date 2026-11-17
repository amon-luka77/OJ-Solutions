#include<bits/stdc++.h>
#define ll long long 
#define int long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

const int N = 1e5;
int n, q;

int a[N + 1];

int node[N * 2 + 2];

void build() {
    FOR(i, 1, n) node[i + n] = a[i];
    for(int i = n; i >= 1; i --) node[i] = max(node[i << 1], node[i << 1 | 1]);
}

void updated(int i, int val) {
    for(node[i += n] = val, i >>= 1; i >= 1; i >>= 1) {
        node[i] = max(node[i << 1], node[i << 1 | 1]);
    }
}

ll get(int l, int r) {
    int res = 0;
    for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if(l & 1) res = max(res, node[l ++]);
        if(!(r & 1)) res = max(res, node[r --]);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    build();

    cin >> q;
    while(q --) {
        int opt; cin >> opt;
        if(opt == 1) {
            int x, y; cin >> x >> y;
            updated(x, y);
        } else {
            int x, y; cin >> x >> y;
            cout << get(x, y) << "\n";
        }
    }
}