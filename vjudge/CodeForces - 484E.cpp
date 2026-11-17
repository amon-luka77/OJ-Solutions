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

const ll N = 1e5;
const ll maxNode = 20 * N;
ll n, q, numNode = 0, root[N + 1];
pair<ll, ll> a[N + 1];

ll Left[maxNode + 1], Right[maxNode + 1];
struct Node{
    ll pref, suf, sum;
    ll len, val;
};
Node node[maxNode + 1];

Node merge(const Node &nodeLeft, const Node &nodeRight) {
    Node curNode;
    curNode.pref = max(nodeLeft.pref, (nodeLeft.len == nodeLeft.sum) * (nodeLeft.len + nodeRight.pref));
    curNode.suf = max(nodeRight.suf, (nodeRight.len == nodeRight.sum) * (nodeRight.len + nodeLeft.suf));
    curNode.sum = nodeLeft.sum + nodeRight.sum;
    curNode.len = nodeLeft.len + nodeRight.len;
    curNode.val = max({nodeLeft.val, nodeRight.val, nodeLeft.suf + nodeRight.pref});
    return curNode;
}

inline void copyNode(ll &numNode, ll curNode) {
    node[numNode] = node[curNode];
    Left[numNode] = Left[curNode];
    Right[numNode] = Right[curNode];
}

ll updated(ll preNode, ll l, ll r, ll i, ll val) {
    ll curNode = ++numNode; copyNode(curNode, preNode);
    if(l == r) {node[curNode] = {1, 1, 1, 1, 1}; return curNode;}
    ll mid = (l + r) >> 1;
    if(i <= mid) Left[curNode] = updated(Left[curNode], l, mid, i, val);
    else Right[curNode] = updated(Right[curNode], mid + 1, r, i, val);
    node[curNode] = merge(node[Left[curNode]], node[Right[curNode]]);
    return curNode;
}

Node get(ll curNode, ll l, ll r, ll i, ll j) {
    if(l == i && r == j) return node[curNode];
    ll mid = (l + r) >> 1;
    if(j <= mid) return get(Left[curNode], l, mid, i, j);
    else if(i > mid) return get(Right[curNode], mid + 1, r, i, j);
    return merge(get(Left[curNode], l, mid, i, mid), get(Right[curNode], mid + 1, r, mid + 1, j));
}

ll build(ll l, ll r) {
    ll curNode = ++numNode;
    if(l == r) {node[curNode] = {0, 0, 0, 1, 0}; return curNode;}
    ll mid = (l + r) >> 1;
    Left[curNode] = build(l, mid); Right[curNode] = build(mid + 1, r);
    node[curNode].len = node[Left[curNode]].len + node[Right[curNode]].len;
    return curNode;
}

void read() {
    cin >> n; 
    root[0] = build(1, n);
    FOR(i, 1, n) {cin >> a[i].ft; a[i].sc = i;}
    sort(a + 1, a + n + 1, greater<pair<ll, ll>>());
    FOR(i, 1, n) root[i] = updated(root[i - 1], 1, n, a[i].sc, 1);
    // FOR(i,1 , n) cerr << i << ' ' << "[" << a[i].ft << ", " << a[i].sc << "]\n";
}

bool check(ll l, ll r, ll len, ll i) {
    return get(root[i], 1, n, l, r).val >= len;
}

void solve() {
    // cerr << get(root[5], 1, n, 1, n).val;

    cin >> q;
    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y >> z;
        ll l = 1, r = n, ans = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(check(x, y, z, mid)) {
                ans = a[mid].ft;
                r = mid - 1;
            } else l = mid + 1;
        }

        cout << ans << el;
    }
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