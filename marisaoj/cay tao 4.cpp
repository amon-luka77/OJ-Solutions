#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define pb push_back

const int N = 100005;
const int MAX_NODES = N * 80;

struct Node {
    int cnt;
    int lc, rc;
} tree[MAX_NODES];

int node_cnt = 0;
int root[N];
int n, q, m;
int a[N], orig_a[N];
vector<int> vals;

struct InputQuery {
    int type, i, x, l, r, k;
} in_q[N];

void update_st(int& node, int l, int r, int val, int delta) {
    if (!node) node = ++node_cnt;
    tree[node].cnt += delta;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (val <= mid) update_st(tree[node].lc, l, mid, val, delta);
    else update_st(tree[node].rc, mid + 1, r, val, delta);
}

void bit_update(int pos, int val, int delta) {
    for (; pos <= n; pos += pos & -pos) {
        update_st(root[pos], 1, m, val, delta);
    }
}

vector<int> L_nodes, R_nodes;

int query_kth(int l, int r, int k) {
    L_nodes.clear();
    R_nodes.clear();

    for (int i = r; i > 0; i -= i & -i) R_nodes.pb(root[i]);
    for (int i = l - 1; i > 0; i -= i & -i) L_nodes.pb(root[i]);

    int low = 1, high = m;
    while (low < high) {
        int mid = (low + high) >> 1;
        int sum = 0;

        for (int r_node : R_nodes) sum += tree[tree[r_node].lc].cnt;
        for (int l_node : L_nodes) sum -= tree[tree[l_node].lc].cnt;

        if (sum >= k) {
            for (int &r_node : R_nodes) r_node = tree[r_node].lc;
            for (int &l_node : L_nodes) l_node = tree[l_node].lc;
            high = mid;
        } else {
            k -= sum;
            for (int &r_node : R_nodes) r_node = tree[r_node].rc;
            for (int &l_node : L_nodes) l_node = tree[l_node].rc;
            low = mid + 1;
        }
    }
    return low;
}

int get_val_id(int v) {
    return lower_bound(vals.begin(), vals.end(), v) - vals.begin() + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> q)) return 0;

    FOR(i, 1, n) {
        cin >> a[i];
        orig_a[i] = a[i];
        vals.pb(a[i]);
    }

    FOR(i, 1, q) {
        cin >> in_q[i].type;
        if (in_q[i].type == 1) {
            cin >> in_q[i].i >> in_q[i].x;
            vals.pb(in_q[i].x);
        } else {
            cin >> in_q[i].l >> in_q[i].r >> in_q[i].k;
        }
    }

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    m = vals.size();

    FOR(i, 1, n) {
        bit_update(i, get_val_id(orig_a[i]), +1);
    }

    FOR(i, 1, q) {
        if (in_q[i].type == 1) {
            int pos = in_q[i].i;
            int old_val_id = get_val_id(orig_a[pos]);
            int new_val_id = get_val_id(in_q[i].x);
            orig_a[pos] = in_q[i].x;

            bit_update(pos, old_val_id, -1);
            bit_update(pos, new_val_id, +1);
        } else {
            int ans_id = query_kth(in_q[i].l, in_q[i].r, in_q[i].k);
            cout << vals[ans_id - 1] << "\n";
        }
    }

    return 0;
}
