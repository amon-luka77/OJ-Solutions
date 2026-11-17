/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e6;
const ll maxNode = 4 * N + N * __lg(N);

struct Node { int l, r; ll val;};

Node node[maxNode + 1];
int numNode = 0, root[N + 1];
ll a[N + 1], n, q;

int build(int l, int r) {
    int curNode = ++numNode, mid = (l + r) >> 1;
    if(l == r) {node[curNode].val = a[l]; return curNode;}
    node[curNode].l = build(l, mid);
    node[curNode].r = build(mid + 1, r);
    return curNode;
}

int updated(int preNode, int l, int r, int i, ll val) {
    int curNode = ++numNode, mid = (l + r) >> 1;
    node[curNode] = node[preNode]; if(l == r) {node[curNode].val = val; return curNode;}
    if(i <= mid) node[curNode].l = updated(node[preNode].l, l, mid, i, val);
    else node[curNode].r = updated(node[preNode].r, mid + 1, r, i, val);
    return curNode;
}

ll query(int curNode, int l, int r, int i) {
    if(l == r) return node[curNode].val;
    int mid = (l + r) >> 1;
    if(i <= mid) return query(node[curNode].l, l, mid, i);
    return query(node[curNode].r, mid + 1, r, i);
}

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

void solve() {
    root[0] = build(1, n);
    // cerr << "\nbegin";
    FOR(i, 1, q) {
        ll x, y, z, t; cin >> x >> y >> z;
        if(y == 1) {cin >> t; root[i] = updated(root[x], 1, n, z, t);}
        else {
            cout << query(root[x], 1, n, z) << el;
            root[i] = root[x];
        }
    }
    // cerr << "\nend";
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}