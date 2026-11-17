#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e5;
ll n, q, cnt = 0, a[N + 1], b[N + 1];
ll root[N + 1];
struct NODE {
    ll val, left, right;
} node[20 * N + 1];

ll build(ll l, ll r) {
    ll id = cnt ++;
    if(l == r) {
        return id;
    }

    ll mid = (l + r) >> 1;
    node[id].left = build(l, mid);
    node[id].right = build(mid + 1, r);

    return id;
}

ll updated(ll last, ll l, ll r, ll pos) {
    ll id = cnt ++;

    if(l == r) {
        node[id].val = node[last].val + 1;
        return id;
    }

    ll mid = (l + r) >> 1;

    if(pos <= mid) {
        node[id].right = node[last].right;
        node[id].left = updated(node[last].left, l, mid, pos);
    } else {
        node[id].left = node[last].left;
        node[id].right = updated(node[last].right, mid + 1, r, pos);
    }

    node[id].val = node[node[id].left].val + node[node[id].right].val;

    return id;
}

ll get(ll r1, ll r2, ll l, ll r, ll i) {
    if(l == r) {
        return l;
    }

    ll sum_left = node[node[r2].left].val - node[node[r1].left].val;
    ll mid = (l + r) >> 1;
    if(sum_left >= i) {
        return get(node[r1].left, node[r2].left, l, mid, i);
    } else {
        return get(node[r1].right, node[r2].right, mid + 1, r, i - sum_left);
    }
}

void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }
    unordered_map<ll, ll> ts;
    sort(b + 1, b + n + 1);
    for(ll i = 1; i <= n; i ++) {
        if(ts[b[i]] == 0) ts[b[i]] = i;
    }
    for(ll i = 1; i <= n; i ++) {
        a[i] = ts[a[i]];
    }
}
void solve() {
    root[0] = build(1, n);
    for(ll i = 1; i <= n; i ++) {
        root[i] = updated(root[i - 1], 1, n, a[i]);
    }

    while(q --) {
        ll l, r, k; cin >> l >> r >> k;
        cout << b[get(root[l - 1], root[r], 1, n, k)] << el;
    }
}
void write() {

}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}