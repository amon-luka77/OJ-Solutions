#include<bits/stdc++.h>
#define ll long long 
#define pb push_back

using namespace std;

const ll N = 0;
ll t;

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 1);
    }

    void updated(ll id, ll l, ll r, ll i, ll val, ll mod) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] = (node[id] * val % mod) % mod;
            return;
        }

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, val, mod);
        updated(id * 2 + 1, mid + 1, r, i, val, mod);

        node[id] = (node[id * 2] * node[id * 2 + 1]) % mod;
    }

    void chia(ll id, ll l, ll r, ll i, ll mod) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] = 1;
            return;
        }

        ll mid = (l + r) >> 1;

        chia(id * 2, l, mid, i, mod);
        chia(id * 2 + 1, mid + 1, r, i, mod);

        node[id] = (node[id * 2] * node[id * 2 + 1]) % mod;
    }

    ll get(ll id, ll l, ll r, ll i, ll j, ll mod) {
        if(l > j || r < i) return 1;
        if(i <= l && r <= j) return node[id] % mod;

        ll mid = (l + r) >> 1;

        return (get(id * 2, l, mid, i, j, mod) * get(id * 2 + 1, mid + 1, r, i, j, mod)) % mod;
    }
};

void read() {
    cin >> t;
}

void slove() {
    while(t --) {
        ll q, m;
        cin >> q >> m;

        SegmentTree node(q);

        for(ll i = 1; i <= q; i ++) {
            ll x, y; cin >> x >> y;
            
            if(x == 1) {
                node.updated(1, 1, q, i, y, m);
            } else {
                node.chia(1, 1, q, y, m);
            }

            cout << node.get(1, 1, q, 1, q, m) << "\n";
        }
    }
}

void write() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    read();
    slove();
    write();
}
