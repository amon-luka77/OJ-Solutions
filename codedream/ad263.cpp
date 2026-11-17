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
const ll N = 5e4;
ll n, q, block, a[N + 1];
vector<ll> b;

ll binary(ll k) {
    ll l = 1, r = b.size() - 1, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(b[mid] <= k) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

struct QUERY {
    string x; 
    ll y, z, t;
};

struct BIT {
    ll n;
    vector<ll> bit;

    void resize(ll m) {
        n = m;
        bit.assign(m + 1, 0);
    }

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getBlock(ll i) {
        ll res = 0;
        for(; i >= 1; i -= i & -i) res += bit[i];

        return res;
    }
};

BIT bit[400];
vector<QUERY> query;

void read() {
    cin >> n >> q;
    b.pb(0);
    block = sqrt(n);

    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b.pb(a[i]);
    }

    for(ll i = 1; i <= q; i ++) {
        string s; ll x, y, z; cin >> s >> x >> y;
        if(s == "GET") {
            cin >> z;
            query.pb({s, x, y, z});
            b.pb(z);
        } else {
            query.pb({s, x, y, 0});
            b.pb(y);
        }
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());

    for(ll i = 0; i <= block; i ++) {
        bit[i].resize(b.size() - 1);
    }

    for(ll i = 1; i <= n; i ++) {
        a[i] = binary(a[i]);
        bit[(i - 1) / block].updated(a[i], 1);
    }
}

ll get(ll l, ll r, ll val) {
    val = binary(val);

    ll cnt = 0;
    ll blockL = (l - 1) / block;
    ll blockR = (r - 1) / block;

    if(blockL == blockR) {
        for(ll i = l; i <= r; i ++) {
            cnt += (a[i] <= val);
        }
    } else {
        for(ll i = blockL + 1; i <= blockR - 1; i ++) {
            cnt += bit[i].getBlock(val);
        }

        // 1 2 3 4 5 6 7 8
        for(ll i = l; i <= min((blockL + 1) * block, n); i ++) {
            cnt += (a[i] <= val);
        }

        for(ll i = blockR * block + 1; i <= r; i ++) {
            cnt += (a[i] <= val);
        }
    }

    return cnt;
}

void updated_block(ll i, ll val) {
    ll t = binary(val);
    bit[(i - 1) / block].updated(a[i], -1);
    bit[(i - 1) / block].updated(t, 1);
    a[i] = t;
}

void solve() {
    for(auto [x, y, z, t] : query) {
        if(x == "GET") {
            cout << get(y, z, t) << el;
        } else {
            updated_block(y, z);
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