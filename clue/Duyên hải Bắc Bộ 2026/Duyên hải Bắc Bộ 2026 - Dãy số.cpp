#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const ll N = 3e5;
ll n, a[N + 1];
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

ll binary(ll tg) {
    ll l = 1, r = b.size() -  1, ans = -1;

    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] >= tg) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

void read() {
    cin >> n;
    b.pb(0);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    for(ll i = 1; i <= n; i ++) {
        a[i] = binary(a[i]);
    }
}

void slove() {
    ll m = b.size() - 1;
    SegmentTree node_left(m), node_right(m);
    ll cnt = 0;
    
    for(ll i = 1; i <= n; i ++) {
        node_right.updated(1, 1, m, a[i], 1);
    }

    for(ll i = 1; i <= n; i ++) {
        node_right.updated(1, 1, m, a[i], -1);
        cnt += node_left.get(1, 1, m, a[i], m) * node_right.get(1, 1, m, a[i], m) + node_left.get(1, 1, m, 1, a[i]) * node_right.get(1, 1, m, 1, a[i]);
        cnt -= node_left.get(1, 1, m, a[i], a[i]) * node_right.get(1, 1, m, a[i], a[i]);
        node_left.updated(1, 1, m, a[i], 1);
    }

    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    read();
    slove();
    return 0;
}