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

const ll N = 1e6, base = 5;
ll n, q, mul[N + 1][3], mode[3];
string s; 

void read() {
    cin >> s;
    n = s.size(); s = ' ' + s;
    FOR(i, 1, 2) mul[0][i] = 1;
    // mode[1] = 1e9 + 7, mode[2] = 998244353;

    FOR(i, 1, n) FOR(j, 1, 2) {
        mul[i][j] = (mul[i - 1][j] * base);
    }
}

struct SegmentTree {
    ll numNode;
    struct NODE {
        ll val, sz;
    };

    vector<vector<NODE>> node;

    void resize(ll m) {
        numNode = m;
        node.assign(3LL, vector<NODE>(4 * numNode + 1, {0, 0}));
    }

    NODE merge(NODE l, NODE r, ll i) {
        return {(l.val * mul[r.sz][i] + r.val), l.sz + r.sz};
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            FOR(i, 1, 2) {
                node[i][id].val = s[l];
                node[i][id].sz = 1;
            }

            return;
        }      

        ll mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        FOR(i, 1, 2) {
            node[i][id] = merge(node[i][id * 2], node[i][id * 2 + 1], i);
        }
    }

    void updated(ll id, ll l, ll r, ll i) {
        if(l == r) {
            FOR(i, 1, 2) {
                node[i][id].val = 0;
                node[i][id].sz = 0;
            }

            return;
        }

        ll mid = (l + r) >> 1;
        if(i <= mid) updated(id * 2, l, mid, i);
        else updated(id * 2 + 1, mid + 1, r, i);

        FOR(i, 1, 2) {
            node[i][id] = merge(node[i][id * 2], node[i][id * 2 + 1], i);
        }
    }

    NODE getHash(ll id, ll l, ll r, ll i, ll j, ll m) {
        if(l > j || r < i) return {0, 0};
        if(i <= l && r <= j) return node[m][id];

        ll mid = (l + r) >> 1;

        return merge(getHash(id * 2, l, mid, i, j, m), getHash(id * 2 + 1, mid + 1, r, i, j, m), m);
    }

    ll getPos(ll id, ll l, ll r, ll k) {
        if(l == r) return l;

        ll mid = (l + r) >> 1;

        if(node[1][id * 2].sz >= k) return getPos(id * 2, l, mid, k);
        return getPos(id * 2 + 1, mid + 1, r, k - node[1][id * 2].sz);
    }
};

SegmentTree node;

bool check(ll l, ll r, ll curL, ll curR) {
    if(node.getHash(1, 1, n, l, r, 1).val == node.getHash(1, 1, n, curL, curR, 1).val && 
        node.getHash(1, 1, n, l, r, 2).val == node.getHash(1, 1, n, curL, curR, 2).val) {
            return 1;
    } 

    return 0;
}

void solve() {
    cin >> q;
    node.resize(n);
    node.build(1, 1, n);

    FOR(i, 1, q) {
        char x; ll y, z, t; 
        cin >> x >> y;

        if(x == '-') {
            node.updated(1, 1, n, node.getPos(1, 1, n, y));
        } else {
            cin >> z >> t;
    
            if(check(node.getPos(1, 1, n, y), node.getPos(1, 1, n, y + t - 1), 
                    node.getPos(1, 1, n, z), node.getPos(1, 1, n, z + t - 1))) cout << "YES" << el;
            else cout << "NO" << el;
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