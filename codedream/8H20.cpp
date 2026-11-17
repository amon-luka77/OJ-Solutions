/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "8H20"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
const ll mod = 998244353;
ll n, q;
ll a[N + 1], query[N + 1];

ll power(ll x, ll y) {
    ll res = 1; x %= mod;
    while(y) {
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod; y >>= 1;
    } return res;
}

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, q) cin >> query[i];
}

namespace Sub1 {
    bool check() {return n * q <= 1000000;}

    ll b[1001];

    void cal() {
        ll res = 0;
        FOR(i, 1, n) res = (res + power(b[i], i)) % mod;
        cout << res << ' ';
    }

    void solve() {
        FOR(i, 1, q) {
            ll x = query[i];
            if(x == 1) {
                FOR(i, 1, n) b[i] = a[n - i + 1];
            } else if(x == 2) {
                FOR(i, 1, n) b[i] = n - a[i] + 1;
            } else {
                FOR(i, 1, n) b[a[i]] = i;
            } cal(); FOR(i, 1, n) a[i] = b[i];
        }
    }
}

namespace Sub2 {
    bool check() {
        ll x = query[1];
        FOR(i, 2, q) if(x != query[i]) return 0;
        return 1;
    }

    ll ans[2];

    void solveQuery1() {
        ll res = 0;
        FOR(i, 1, n) res = (res + power(a[i], i)) % mod;
        ans[0] = res; res = 0;
        FOR(i, 1, n) res = (res + power(a[n - i + 1], i)) % mod;
        ans[1] = res;

        FOR(i, 1, q) cout << ans[i & 1] << ' ';
    }

    void solveQuery2() {
        ll res = 0;
        FOR(i, 1, n) res = (res + power(a[i], i)) % mod;
        ans[0] = res; res = 0;
        FOR(i, 1, n) res = (res + power(n - a[i] + 1, i)) % mod;
        ans[1] = res;

        FOR(i, 1, q) cout << ans[i & 1] << ' ';
    }

    ll b[N + 1];

    void solveQuery3() {
        ll res = 0; FOR(i, 1, n) b[a[i]] = i;
        FOR(i, 1, n) res = (res + power(a[i], i)) % mod;
        ans[0] = res; res = 0;
        FOR(i, 1, n) res = (res + power(b[i], i)) % mod;
        ans[1] = res;

        FOR(i, 1, q) cout << ans[i & 1] << ' ';
    }

    void solve() {
        ll x = query[1];
        if(x == 1) solveQuery1();
        if(x == 2) solveQuery2();
        if(x == 3) solveQuery3();
    }
}

namespace Sub3 {
    bool check() {
        FOR(i, 1, q) if(query[i] > 2) return 0;
        return 1;
    }

    ll ans[2][2];

    void build() {
        ll res = 0;
        // 0 0
        FOR(i, 1, n) res = (res + power(a[i], i)) % mod;
        ans[0][0] = res; res = 0;
        // 1 1
        FOR(i, 1, n) res = (res + power(n - a[n - i + 1] + 1, i)) % mod;
        ans[1][1] = res; res = 0;
        // 1 0
        FOR(i, 1, n) res = (res + power(a[n - i + 1], i)) % mod;
        ans[1][0] = res; res = 0;
        // 0 1
        FOR(i, 1, n) res = (res + power(n - a[i] + 1, i)) % mod;
        ans[0][1] = res; res = 0;
    }

    void solve() {
        build();
        ll cnt1 = 0, cnt2 = 0;
        FOR(i, 1, q) {
            cnt1 = (cnt1 + (query[i] == 1)) % 2;
            cnt2 = (cnt2 + (query[i] == 2)) % 2;

            cout << ans[cnt1][cnt2] << ' ';
        }
    }
}

namespace Sub4 {
    bool check() {
        FOR(i, 1, n) if(a[i] != i) return 0;
        return 1;
    }

    ll ans[2][2];

    void build() {
        ll res = 0;
        // 0 0
        FOR(i, 1, n) res = (res + power(a[i], i)) % mod;
        ans[0][0] = res; res = 0;
        // 1 1
        FOR(i, 1, n) res = (res + power(n - a[n - i + 1] + 1, i)) % mod;
        ans[1][1] = res; res = 0;
        // 1 0
        FOR(i, 1, n) res = (res + power(a[n - i + 1], i)) % mod;
        ans[1][0] = res; res = 0;
        // 0 1
        FOR(i, 1, n) res = (res + power(n - a[i] + 1, i)) % mod;
        ans[0][1] = res; res = 0;
    }

    void solve() {
        build();
        ll cnt1 = 0, cnt2 = 0;
        FOR(i, 1, q) {
            cnt1 = (cnt1 + (query[i] == 1)) % 2;
            cnt2 = (cnt2 + (query[i] == 2)) % 2;

            cout << ans[cnt1][cnt2] << ' ';
        }
    }
}

void solve() {
    if(Sub1::check()) return Sub1::solve(), void();
    if(Sub2::check()) return Sub2::solve(), void();
    if(Sub3::check()) return Sub3::solve(), void();
    if(Sub4::check()) return Sub4::solve(), void();
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}
