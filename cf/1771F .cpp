#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    const int N = 2e5;

    int n, q; cin >> n;

    static int a[N + 1];
    fill(a + 1, a + n + 1, 0);
    vector<int> b;

    for(int i = 1; i <= n && cin >> a[i]; i ++) b.push_back(a[i]);
    sort(b.begin(), b.end()); b.erase(unique(b.begin(), b.end()), b.end());
    FOR(i, 1, n) a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;

    int lastAns = 0;

    struct PersistentSegtree {
        int numNode = 

        void updated(int preNode, int l, int r, int i, ll val) {
            int curNode = ++numNode, node[curNOde] = node[preNode];
            if(l == r) {node[curNode] ^= val; return curNode;}
            int mid = (l + r) >> 1;

        }
    }
}

int main() {
    ios::sync_with_sdtio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;

    while(t --) solve();

    return 0;
}