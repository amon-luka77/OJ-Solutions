#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

using namespace std;

void solve() {
    const int N = 1e6;

    int numCel, numCol, q; cin >> numCel >> numCol >> q;

    int n = numCel * numCol;

    auto getPos = [&](int x, int y) {
        return (x - 1) * numCol + y;
    };

    static struct PersistentSegtree {
        int numNode = 0, startNode = 0;
        int root[N + 1];

        struct NODE {
            int val, ls, rs;
            bool flip;
        } node[7000000];
        
        int clone(int id) {
            if(id > startNode) return id;

            int curNode = ++numNode; node[curNode] = node[id];
            return numNode;
        }

        void apply(int id, int l, int r) {
            node[id].val = (r - l + 1) - node[id].val;
            node[id].flip ^= 1;
        }

        void push(int id, int l, int r) {
            if(!node[id].flip || l == r) return;
            int mid = (l + r) >> 1;

            node[id].ls = clone(node[id].ls);
            node[id].rs = clone(node[id].rs);

            apply(node[id].ls, l, mid);
            apply(node[id].rs, mid + 1, r);

            node[id].flip = 0;
        }

        int updatedNode(int id, int l, int r, int i, int val) {
            id = clone(id);
            if(l == r) {
                node[id].val = val; node[id].flip = 0; return id;
            } int mid = (l + r) >> 1;

            push(id, l, r);

            if(i <= mid) node[id].ls = updatedNode(node[id].ls, l, mid, i, val);
            else node[id].rs = updatedNode(node[id].rs, mid + 1, r, i, val);

            node[id].val = node[node[id].ls].val + node[node[id].rs].val;
            return id;
        }

        int updatedRanges(int id, int l, int r, int i, int j) {
            id = clone(id);
            if(l == i && r == j) {
                apply(id, l, r); return id;
            } int mid = (l + r) >> 1;

            push(id, l, r);

            if(i <= mid) node[id].ls = updatedRanges(node[id].ls, l, mid, i, min(mid, j));
            if(j > mid) node[id].rs = updatedRanges(node[id].rs, mid + 1, r, max(mid + 1, i), j);

            node[id].val = node[node[id].ls].val + node[node[id].rs].val;
            return id;
        }

        int get(int id, int l, int r, int i, int j) {
            if(!id || i > j) return 0;
            if(l == i && r == j) return node[id].val;

            int mid = (l + r) >> 1;

            int sum = get(node[id].ls, l, mid, i, min(mid, j)) + 
                        get(node[id].rs, mid + 1, r, max(mid + 1, i), j);

            if(node[id].flip) return (r - l + 1) - sum;
            else return sum;
        }
    } node;

    FOR(i, 1, q) {
        int opt, x, y; cin >> opt >> x;
        if(opt == 1 || opt == 2) {
            cin >> y; int pos = getPos(x, y);
            node.root[i] = node.updatedNode(node.root[i - 1], 1, n, pos, (opt == 1 ? 1 : 0));
        } else if(opt == 3) {
            node.root[i] = node.updatedRanges(node.root[i - 1], 1, n, (x - 1) * numCol + 1, x * numCol);
        } else node.root[i] = node.root[x];

        node.startNode = node.numNode;
        cout << node.node[node.root[i]].val << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t --) solve();

    return 0;
}