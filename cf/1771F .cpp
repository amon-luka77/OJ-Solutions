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

    static struct PersistentSegtree {
        int numNode = 0;
        int root[N + 1];

        struct NODE {
            ll val, ls, rs;
        } node[20 * N + 1];

        int updated(int preNode, int l, int r, int i, ll val) {
            int curNode = ++numNode; node[curNode] = node[preNode];
            if(l == r) {node[curNode].val ^= val; return curNode;}
            int mid = (l + r) >> 1;
            if(i <= mid) node[curNode].ls = updated(node[curNode].ls, l, mid, i,  val);
            else node[curNode].rs = updated(node[curNode].rs, mid + 1, r, i, val);
            node[curNode].val = node[node[curNode].ls].val ^ node[node[curNode].rs].val;
            return curNode;
        }

        int get(int rLeft, int rRight, int l, int r) {
            if(!(node[rRight].val ^ node[rLeft].val)) return 0;
            if(l == r) return l;
            ll val = node[node[rRight].ls].val ^ node[node[rLeft].ls].val;
            int mid = (l + r) >> 1;
            if(val) return get(node[rLeft].ls, node[rRight].ls, l, mid);
            return get(node[rLeft].rs, node[rRight].rs, mid + 1, r);
        }
    } node;

    mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

    static ll hashVal[N + 1];

    FOR(i, 0, b.size() - 1) hashVal[i + 1] = rd();
    int maxNode = b.size();

    FOR(i, 1, n) node.root[i] = node.updated(node.root[i - 1], 1, maxNode, a[i], hashVal[a[i]]);

    // FOR(i, 1, n) cerr << hashVal[a[i]] << ' ';
    // cerr << "\n";

    cin >> q;

    while(q --) {
        int l, r; cin >> l >> r;
        l ^= lastAns; r ^= lastAns;
        // cerr << "query: " << l << ' ' << r << "\n";

        int x = node.get(node.root[l - 1], node.root[r], 1, maxNode);
        
        cout << (!x ? lastAns = 0 : lastAns = b[x - 1]) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1; 
    // cin >> t;

    while(t --) solve();

    return 0;
}