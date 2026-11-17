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
ll n, q, m, block = 0, a[N + 1], ans[N + 1];
vector<ll> b;
ll cnt = 0;

struct BIT {
    int n;
    vector<ll> bit;

    BIT(int n = 0) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void reset(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // cộng val vào vị trí i
    void update(int i, ll val) {
        for(; i <= n; i += i & -i)
            bit[i] += val;
    }

    // lấy tổng [1..i]
    ll get(int i) {
        ll s = 0;
        for(; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // lấy tổng [l..r]
    ll get(int l, int r) {
        if(l > r) return 0;
        return get(r) - get(l - 1);
    }
};

BIT node(1);

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
    cin >> n >> q;
    b.pb(0);

    block = sqrt(n) + 1;

    for(ll i = 0; i < n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    m = b.size() - 1;
    node = BIT(m);

    for(ll i = 0; i < n; i ++) {
        a[i] = binary(a[i]);
    }
}

void add(ll pos, ll type) {
    ll k = a[pos];

    if(type == 1) cnt += node.get(1, k - 1);
    else cnt += node.get(k + 1, m);

    node.update(k, 1);
}

void remove(ll pos, ll type) {
    ll k = a[pos];

    node.update(k, -1);

    if(type == 1) cnt -= node.get(1, k - 1);
    else cnt -= node.get(k + 1, m);
}

struct QUERY {
    ll x, y, z;
};

vector<QUERY> query;

void solve() {
    for(ll i = 1; i <= q;  i++) {
        ll l, r; cin >> l >> r;
        query.pb({--l, --r, i});
    }

    sort(all(query), [](QUERY &x, QUERY &y) {
        ll rx = x.x / block;
        ll ry = y.x / block;

        if(rx != ry) return rx < ry;
        else {
            if(rx % 2) return x.y < y.y;
            return x.y > y.y;
        }
    });

    ll cur_l = 0, cur_r = -1;
    for(auto [i, j, k] : query) {

        while(cur_l > i) add(-- cur_l, 1);
        while(cur_l < i) remove(cur_l ++, 1);
        while(cur_r < j) add(++ cur_r, 2);
        while(cur_r > j) remove(cur_r --, 2);

        ans[k] = cnt;
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