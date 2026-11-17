#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 1e6, base = 31;
ll n, q, mul[N + 1];
string s; 

struct NODE {
    ll val, sz;
};

NODE node[3][4 * N + 1];

void read() {
    cin >> n >> q >> s;
    s = ' ' + s;
    mul[0] = 1;

    FOR(i, 1, n) {
        mul[i] = mul[i - 1] * base;
    }
}

NODE merge(NODE x, NODE y) {
    return {x.val * mul[y.sz] + y.val, x.sz + y.sz};
}

void build(ll id, ll l, ll r, ll i) {
    if(l == r) {
        if(i == 1) node[i][id].val = s[l] - 'a' + 1;
        else node[i][id].val = (s[n - l + 1] - 'a') + 1;
        node[i][id].sz = 1;

        return;
    }

    ll mid = (l + r) >> 1;

    build(id * 2, l, mid, i);
    build(id * 2 + 1, mid + 1, r, i);

    node[i][id] = merge(node[i][id * 2], node[i][id * 2 + 1]);
}

void updated(ll id, ll l, ll r, ll idx, ll i, ll vl) {
    if(l == r) {
        node[idx][id].val = vl;

        return;
    }

    ll mid = (l + r) >> 1;

    if(i <= mid) updated(id * 2, l, mid, idx, i, vl);
    else updated(id * 2 + 1, mid + 1, r, idx, i, vl);

    node[idx][id] = merge(node[idx][id * 2], node[idx][id * 2 + 1]);
}

NODE getHash(ll id, ll l, ll r, ll rol, ll i, ll j) {
    if(l > j || r < i) return {0, 0};
    if(i <= l && r <= j) return node[rol][id];

    ll mid = (l + r) >> 1;

    return merge(getHash(id * 2, l, mid, rol, i, j), getHash(id * 2 + 1, mid + 1, r, rol, i, j));
}

void solve() {
    build(1, 1, n, 1);
    build(1, 1, n, 2);

    FOR(i, 1, q) {
        ll x;
        cin >> x;
        if(x == 1) {
            ll y; char z; cin >> y >> z;
            updated(1, 1, n, 1, y, z - 'a' + 1);
            updated(1, 1, n, 2, n - y + 1, z - 'a' + 1);
        } else {
            ll y, z; cin >> y >> z;
            if(getHash(1, 1, n, 1, y, z).val == getHash(1, 1, n, 2, n - z + 1, n - y + 1).val) {
                cout << "YES" << el;
            } else {
                cout << "NO" << el;
            }
        }
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
