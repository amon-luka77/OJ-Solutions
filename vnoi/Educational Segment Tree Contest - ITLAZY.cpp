#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    const int N = 1e5;
    static int a[N + 1];

    int n; cin >> n;
    for(int i = 1; i <= n && cin >> a[i]; i ++);
    #define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)

    int q; cin >> q;

    static struct Segtree {
        int n, high;
        ll node[4 * N + 1];
        ll lazy[4 * N + 1];

        Segtree(int _n, int a[]) {
            memset(node, -0x3f, sizeof node);
            for(n = 1, high = 0; n < _n; n <<= 1, high ++);
            FOR(i, 1, _n) node[i + n - 1] = a[i];
            for(int i = n - 1; i; i --) node[i] = max(node[i << 1], node[i << 1 | 1]);
        }

        void apply(int i, ll val, int len) {
            node[i] += val; lazy[i] += val;
        }

    
        #define MASK(i) (1LL << (i))

        void push(int p) {
            for(int len = high, i; len; len --) {
                if(lazy[i = p >> len]) {
                    apply(i << 1, lazy[i], MASK(len - 1));
                    apply(i << 1 | 1, lazy[i], MASK(len - 1));
                    lazy[i] = 0;
                }
            }
        }

        void pull(int i) {
            for(int len = 2; i >>= 1; len <<= 1) {
                node[i] = max(node[i << 1], node[i << 1 | 1]) + lazy[i];
            }
        }

        void updated(int l, int r, ll val) {
            int curL = l += n - 1, curR = r += n - 1;
            push(curL); push(curR);

            for(int len = 1; l <= r; l >>= 1, r >>= 1, len <<= 1) {
                if(l & 1) apply(l ++, val, len);
                if(!(r & 1)) apply(r --, val, len);
            }

            pull(curL), pull(curR);
        }

        ll getMax(int l, int r) {
            ll res = -1e18;
            
            for(l += n - 1, r += n - 1, push(l), push(r); l <= r; l >>= 1, r >>= 1) {
                if(l & 1) res = max(res, node[l ++]);
                if(!(r & 1)) res = max(node[r --], res);
            } return res;
        }
    } node(n, a);

    while(q --) {
        ll x, l, r, k; cin >> x >> l >> r;

        if(x == 1) {
            cin >> k;
            node.updated(l, r, k);
        } else {
            cout << node.getMax(l, r) << "\n";
        }
    }
}