#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define el '\n'
#define all(x) (x).begin(), (x).end()
#define MASK(i) (1 << (i))
#define BIT(i) ((1 << (i)) & 1)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
const ll maxNode = 40 * N;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

struct persistentSegtree {
    int node[maxNode], L[maxNode + 1], R[maxNode + 1];
    int numNode = 0, pos[N + 1], root[N + 1];

    int updated(int preNode, int l, int r, int i, int val) {
        int curNode = ++numNode; node[curNode] = node[preNode];
        L[curNode] = L[preNode], R[curNode] = R[preNode];
        int mid = (l + r) >> 1;
        if(l == r) {node[curNode] += val; return curNode;}
        if(i <= mid) L[curNode] = updated(L[curNode], l, mid, i, val);
        else R[curNode] = updated(R[curNode], mid + 1, r, i, val);
        node[curNode] = node[L[curNode]] + node[R[curNode]]; return curNode;
    }

    int getK(int curNode, int l, int r, int i) {
        if(l == r) return l;
        ll mid = (l + r) >> 1; ll sumLeft = i - node[L[curNode]];
        if(sumLeft < 0) return getK(L[curNode], l, mid, i);
        else return getK(R[curNode], mid + 1, r, sumLeft);
    }

    int getSum(int curNode, int l, int r, int i, int j) {
        if(l == i && r == j) return node[curNode];
        ll mid = (l + r) >> 1;
        if(j <= mid) return getSum(L[curNode], l, mid, i, j);
        else if(i > mid) return getSum(R[curNode], mid + 1, r, i, j);
        return getSum(L[curNode], l, mid, i, mid) + getSum(R[curNode], mid + 1, r, mid + 1, j);
    }

    void build() {
        FORD(i, n, 1) {
            root[i] = root[i + 1];
            if(pos[a[i]]) root[i] = updated(root[i], 1, n, pos[a[i]], -1);
            root[i] = updated(root[i], 1, n, i, 1);
            pos[a[i]] = i;
        }
    }
} st;

void solve() {
    st.build();
    FOR(i, 1, n) {
        ll l = 1, res = 0;
        while(l <= n) {
            res ++;
            if(st.getSum(st.root[l], 1, n, l, n) <= i) break;
            l = st.getK(st.root[l], 1, n, i);
        } cout << res << ' ';
    }
}

void write() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    file();
    read();
    solve();
    write();
    return 0;
}
 