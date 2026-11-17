/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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

const ll N = 2000;
long long n, m, k, a[N + 1][N + 1], h[N + 1], maxCel[N + 1], prefix[N + 1][N + 1];

struct NODE {
    int val, lazy;
};

NODE node[4 * N + 1];

void lazy(ll id) {
    if(node[id].lazy == 0) return;
    ll k = node[id].lazy; node[id].lazy = 0;

    node[id * 2].val += k;
    node[id * 2 + 1].val += k;
    node[id * 2].lazy += k;
    node[id * 2 + 1].lazy += k;
}

void updated(ll id, ll l, ll r, ll i, ll j, ll vl) {
    if(l > j || r < i) return;
    if(i <= l && r <= j) {
        node[id].val += vl;
        node[id].lazy += vl;
        return;
    }

    lazy(id);
    ll mid = (l + r) >> 1;

    updated(id * 2, l, mid, i, j, vl);
    updated(id * 2 + 1, mid + 1, r, i, j, vl);

    node[id].val = min(node[id * 2].val, node[id * 2 + 1].val);
}

void build(ll id, ll l, ll r) {
    node[id].lazy = 0;
    if(l == r) {
        node[id].val = -l;
        return;
    }

    ll mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    node[id].val = min(node[id * 2].val, node[id * 2 + 1].val);
}

void read() {
    cin >> n >> m >> k;
    FOR(i, 1, k) {
        cin >> h[i];
    }

    sort(h + 1, h + k + 1);

    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    FOR(i, 1, n) FOR(j, 1, m) {
        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (a[i][j]);
        a[i][j] = upper_bound(h + 1, h + k + 1, a[i][j]) - h;
    }
}

void solve() {
    ll cnt = 0;
    // cout << el << el;

    FOR(i, 1, m) maxCel[i] = 1;

    FOR(i, 1, n) {
        build(1, 1, k);

        FOR(j, 1, k) {
            updated(1, 1, k, maxCel[j], k, 1);
            // if(i == 1) cout << maxCel[j] << ' ' << k << el;
        }

        if(node[1].val >= 0) {
            ll s = prefix[i][k] - prefix[i-1][k];
            if (s == 0) cnt++;
            // cout << i << ' ' << 1 << ' ' << i << ' ' << k << el;
        }

        // cout << i << ' ' << 1 << ' ' << i << ' ' << k << ' ' << getMin(1, 1, k, 1, k) << el;

        FOR(r, k + 1, m) {
            ll l = r + 1 - k;
            updated(1, 1, k, maxCel[r], k, 1);
            updated(1, 1, k, maxCel[l - 1], k, -1);

            if(node[1].val >= 0) {
                ll s = prefix[i][r] - prefix[i-1][r] - prefix[i][l-1] + prefix[i-1][l-1];
                if (s == 0) cnt++;
                // cout << i << ' ' << l << ' ' << i << ' ' << r << el;
            }
        }

        FOR(j, 1, m) maxCel[j] = max(a[i][j], maxCel[j]);
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