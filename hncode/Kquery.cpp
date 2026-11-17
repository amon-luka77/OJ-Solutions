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
const ll N = 2e5;
ll n, a[N + 1], q, ans[N + 1];
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

        ll mid =  (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

struct KK {
    ll cuoi, max_n, loai, type;
};

bool cmp(KK x, KK y) {
    return x.cuoi < y.cuoi;
}

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(N);
    vector<KK> query;
    cin >> q;
    ll sl = 1;
    while(q --) {
        ll l, r, k;
        cin >> l >> r >> k;
        query.pb({l - 1, k, sl, -1LL});
        query.pb({r, k, sl, 1LL});
        sl ++;
    }

    sort(query.begin(), query.end(), cmp);

    for(ll i = 0; i < query.size(); i ++) {

        if(i == 0) {

            for(ll j = 1; j <= query[i].cuoi; j ++) {
                node.updated(1, 1, N, a[j], 1);
            }

            ans[query[i].loai] += node.get(1, 1, N, query[i].max_n + 1, N) * query[i].type;

        } else {

            for(ll j = query[i - 1].cuoi + 1; j <= query[i].cuoi; j ++) {
                node.updated(1, 1, N, a[j], 1);
            }

            ans[query[i].loai] += node.get(1, 1, N, query[i].max_n + 1, N) * query[i].type;

        }
    }


    for(ll i = 1; i < sl; i ++) {
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