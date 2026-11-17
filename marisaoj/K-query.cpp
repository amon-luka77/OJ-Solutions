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
ll n, q, a[N + 1], ans[N + 1];
vector<ll> b;

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i, ll val) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] += val;
            return;
        }

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i, val);
        updated(id * 2 + 1, mid + 1, r, i, val);

        node[id] = node[id * 2] + node[id * 2 + 1];
    } 

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

struct KK {
    ll last, type, num, t;
};

bool cmp(KK x, KK y) {
    return x.last < y.last;
}

ll binary(ll k) {
    ll l = 1, r = b.size() - 1, ans = -1;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] >= k) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

void read() {
    cin >> n >> q;
    b.pb(0);
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }
}
void solve() {
    vector<KK> query;

    for(ll i = 1; i <= q; i ++) {
        ll l, r, k;
        cin >> l >> r >> k;

        b.pb(k + 1);

        query.pb({l - 1, i, k + 1, -1LL});
        query.pb({r, i, k + 1, 1LL});
    }

    sort(all(query), cmp);
    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
    ll k = b.size();
    SegmentTree node(k);

    for(ll i = 0; i < query.size(); i ++) {
        if(i == 0) {
            for(ll j = 1; j <= query[i].last; j ++) {
                node.updated(1, 1, k, binary(a[j]), 1);
            }
        } else {
            for(ll j = query[i - 1].last + 1; j <= query[i].last; j ++) {
                node.updated(1, 1, k, binary(a[j]), 1);
            }
        }

        ans[query[i].type] += node.get(1, 1, k, binary(query[i].num), k) * query[i].t;
    }

    for(ll i = 1; i <= q; i ++) {
        cout << ans[i] << el;
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