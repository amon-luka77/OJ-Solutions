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

const ll N = 2e5, mod = 1e9 + 7;
ll n, q, a[N + 1];

ll power(ll a, ll b) {
    if(b == 0) return 1;
    ll t = power(a, b / 2) % mod;
    ll res = (t * t) % mod;
    if(b % 2) res = (res * a % mod) % mod;
    return res;
}

ll sumScp(ll a) {
    a %= mod;
    return (((a * (a + 1)) % mod * (2 * a + 1) % mod) % mod * 166666668) % mod;
}

    struct NODE {
        ll x, y, z, t, lazy;
    };

    NODE node[4* N + 1];

    NODE merge(NODE x, NODE y) {
        return {(x.x * y.x) % mod, (x.y + y.y) % mod, (x.z + y.z) % mod, (x.t + y.t) % mod, -1};
    }

    void lazy(ll id, ll l, ll r) {
        if(node[id].lazy == -1) return;
        ll k = node[id].lazy; node[id].lazy = -1;
        ll mid = (l + r) >> 1;
        
        node[id * 2].x = power(k + 1, mid - l + 1);
        node[id * 2].y = ((((mid - l + 1) * (mid + l)) % mod * k) % mod * 500000004) % mod;
        node[id * 2].z = ((mid - l + 1) * k) % mod;
        node[id * 2].t = (k * (sumScp(mid) - sumScp(l - 1) + mod) % mod) % mod;
        node[id * 2].lazy = k;

        node[id * 2 + 1].x = power(k + 1, r - mid);
        node[id * 2 + 1].y = ((((r - mid) * (r + mid + 1)) % mod * k) % mod * 500000004) % mod;
        node[id * 2 + 1].z = ((r - mid) * k) % mod;
        node[id * 2 + 1].t = (k * (sumScp(r) - sumScp(mid) + mod) % mod) % mod;
        node[id * 2 + 1].lazy = k;
    }

    void build(ll id, ll l, ll r) {
        if(l == r) {
            a[l] %= mod;
            node[id].x = (a[l] + 1) % mod;
            node[id].y = (a[l] * l) % mod;
            node[id].z = a[l];
            node[id].t = ((a[l] * l) % mod * l) % mod;

            return;
        }

        ll mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);

        node[id] = merge(node[id * 2], node[id * 2 + 1]);
    }

    void updated(ll id, ll l, ll r, ll i, ll j, ll val) {
        if(l > j || r < i) return;
        if(i <= l && r <= j) {
            node[id].x = power(val + 1, r - l + 1);
            node[id].y = (r - l + 1) * (r + l) % mod * val % mod * 500000004 % mod;
            node[id].z = ((r - l + 1) * val) % mod;
            node[id].t = val * (sumScp(r) - sumScp(l - 1) + mod) % mod % mod;
            node[id].lazy = val;

            return;
        }

        lazy(id, l, r);

        ll mid = (l + r) >> 1;
        updated(id * 2, l, mid, i, j, val);
        updated(id * 2 + 1, mid + 1, r, i, j, val);

        node[id] = merge(node[id * 2], node[id * 2 + 1]);
    }

    NODE get(ll id, ll l, ll r, ll i, ll j) {
        if(l > j || r < i) return  {1, 0, 0, 0, -1};
        if(i <= l && r <= j) return node[id];

        lazy(id, l, r);
        ll mid = (l + r) >> 1;

        return merge(get(id * 2, l, mid, i, j), get(id * 2 + 1, mid + 1, r, i, j));
    }

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}
// 166666668 
void solve() {
    build(1, 1, n);

    while(q --) {
        ll x, l, r; cin >> x >> l >> r;
        l ++; r ++;
        if(x == 1) {
            ll val; cin >> val;
            val %= mod;
            updated(1, 1, n, l, r, val);
        } else {
            auto k = get(1, 1, n, l, r);
            ll amon = mod - (l * r % mod * k.z % mod) % mod;
            ll y = (l + r) * k.y % mod;
            ll z = (r - l) * k.z % mod;
            ll t = mod + (k.z - k.t) % mod % mod;
            cout << (k.x * ((((amon + y) % mod + z) % mod + t) % mod * 500000004 % mod)) % mod << el;
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