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
const ll maxN = N * 20;
ll n, q, numNode = 0, a[N + 1], root[N + 1];

struct Node {ll ls, rs, val;};
Node node[maxN + 1];

ll updated(ll preNode, ll l, ll r, ll i) {
    ll curNode = ++numNode; node[curNode] = node[preNode];
    if(l == r) {node[curNode].val ++; return curNode;}
    ll mid = (l + r) >> 1;
    if(i <= mid) node[curNode].ls = updated(node[curNode].ls, l, mid, i);
    else node[curNode].rs = updated(node[curNode].rs, mid + 1, r, i);
    node[curNode].val = node[node[curNode].ls].val + node[node[curNode].rs].val;
    return curNode;
}

ll get(ll root1, ll root2, ll l, ll r, ll i) {
    if(l == r) return l;
    ll mid = (l + r) >> 1;
    ll sumLeft = node[node[root2].ls].val - node[node[root1].ls].val;
    if(i <= sumLeft) return get(node[root1].ls, node[root2].ls, l, mid, i);
    else return get(node[root1].rs, node[root2].rs, mid + 1, r, i - sumLeft);
}

vector<ll> b;

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {cin >> a[i]; b.pb(a[i]);}
    sort(all(b)); b.erase(unique(all(b)), b.end());
    FOR(i, 1, n) a[i] = upper_bound(all(b), a[i]) - b.begin();
}

void solve() {
    FOR(i, 1, n) root[i] = updated(root[i - 1], 1, n, a[i]);
    FOR(i, 1, q) {
        ll x, y, z; cin >> x >> y >> z;
        cout << b[get(root[x - 1], root[y], 1, n, z) - 1] << el;
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
