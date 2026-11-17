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
const ll maxNode = 40 * N;
ll n, k, q, a[N + 1], root[N + 1];
map<ll, vector<ll>> pos;

void read() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
}

ll numNode = 0;
struct Node{ll ls, rs, val;};
Node node[maxNode + 1];

ll updated(ll preNode, ll l, ll r, ll i, ll val) {
    ll curNode = ++numNode; node[curNode] = node[preNode];
    if(l == r) {node[curNode].val += val; return curNode;}
    ll mid = (l + r) >> 1;
    if(i <= mid) node[curNode].ls = updated(node[curNode].ls, l, mid, i, val);
    else node[curNode].rs = updated(node[curNode].rs, mid + 1, r, i, val);
    node[curNode].val = node[node[curNode].ls].val + node[node[curNode].rs].val;
    return curNode;
}

ll get(ll curNode, ll l, ll r, ll i, ll j) {
    if(l == i && r == j) return node[curNode].val;
    ll mid = (l + r) >> 1;
    if(j <= mid) return get(node[curNode].ls, l, mid, i, j);
    else if(i > mid) return get(node[curNode].rs, mid + 1, r, i, j);
    else return get(node[curNode].ls, l, mid, i, mid) + get(node[curNode].rs, mid + 1, r, mid + 1, j);
}

void solve() {
    FOR(i, 1, n) {
        root[i] = updated(root[i - 1], 1, n, i, 1);
        pos[a[i]].pb(i); // 0 1 2 3 
        if(pos[a[i]].size() > k) root[i] = updated(root[i], 1, n, pos[a[i]][pos[a[i]].size() - k - 1], -1);
    }

    cerr << "end build" << el;

    cin >> q; ll preAns = 0;
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        x = (x + preAns) % n + 1;
        y = (y + preAns) % n + 1;
        if(x > y) swap(x, y);
        preAns = get(root[y], 1, n, x, y); cout << preAns << el;
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