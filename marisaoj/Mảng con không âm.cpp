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
ll n, m = 0, cnt = 0, a[N + 1], prefix[N + 1];
vector<ll> b;

ll binary(ll tg) {
    ll l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

void read() {
    cin >> n;
    b.pb(0);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        b.pb(prefix[i]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    m = b.size() - 1;

    for(ll i = 1; i <= n; i ++) {
        prefix[i] = binary(prefix[i]);
    }
}   

struct SegmentTree {
    vector<ll> node;

    SegmentTree(ll n) {
        node.assign(4 * n + 1, 0);
    }

    void updated(ll id, ll l, ll r, ll i) {
        if(l > i || r < i) return;
        if(l == r) {
            node[id] ++;
            return;
        }

        ll mid = (l + r) >> 1;

        updated(id * 2, l, mid, i);
        updated(id * 2 + 1, mid + 1, r, i);

        node[id] = node[id * 2] + node[id * 2 + 1];
    }

    ll get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return 0;
        if(i <= l && r <= j) return node[id];

        ll mid = (l + r) >> 1;

        return get(id * 2, l, mid, i, j) + get(id * 2 + 1, mid + 1, r, i, j);
    }
};

void solve() {
    SegmentTree node(m);


    for(ll i = 1; i <= n; i ++) {
        cnt += node.get(1, 1, m, 1, prefix[i]);
        cnt += (b[prefix[i]] >= 0);
        node.updated(1, 1, m, prefix[i]);  
    }

    cout << cnt;
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
/*
prefix[r] - prefix[l - 1] >= 0;
prefix[r] >= prefix[l - 1];

1, -1, 0
3 1 2
*/