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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5;
ll n, b, W;

struct A {
    ll e, w, c;
};

vector<A> a;

void read() {
    cin >> n >> b >> W;
    FOR(i, 1, n) {
        ll x, y, z; cin >> x >> y >> z;
        a.pb({x, y, z});
    }
}

namespace Sub1 {
    bool check() {
        return (n <= 20);
    }

    struct DP {
        ll e = 0, w = 0, c = 0;
    };

    DP dp[MASK(21) + 5];

    void solve() {
        FOR(i, 0, MASK(n) - 1) FOR(j, 0, n - 1) if(!BIT(i, j)) {
            ll e = dp[i].e + a[j].e;
            ll w = dp[i].w + a[j].w;
            ll c = dp[i].c + a[j].c;

            double x = e / (1.0 * (w + W)), y = dp[i | MASK(j)].e / (1.0 * (dp[i | MASK(j)].w + W));
            if(c <= b) {
                if(x > y) dp[i | MASK(j)] = {e, w, c};
                else if(x == y && c < dp[i | MASK(j)].c) dp[i | MASK(j)] = {e, w, c};
            } 
        }

        double ans = 0;
        FOR(i, 0, MASK(n) - 1) {
            ans = max(ans, dp[i].e / (1.0 * (dp[i].w + W)));
            // cout << i << ' ' << dp[i].e / 1.0 * (dp[i].w + W) << el;
        }
        cout << fixed << setprecision(4) << ans;
    }
}

namespace Sub4 {
    bool check() {
        return 1;
    }

    double dp[N + 1];
    pair<double, ll> c[N + 1];

    bool checkMid(double mid) {
        memset(dp, -0x3f, sizeof dp);
        dp[0] = 0;
        // e / (W + wi) >= mid 
        // e >= mid * W + mid * wi;
        // sum(ei - mid * wi >= mid * W
        
        FOR(i, 0, n - 1) c[i] = {a[i].e - mid * a[i].w, a[i].c};

        FOR(i, 0, n - 1) FORD(j, b, 0) if(j >= c[i].sc) {
            dp[j] = max(dp[j], dp[j - c[i].sc] + c[i].ft);
        }

        double ans = -1e18;
        FOR(i, 0, b) {
            ans = max(ans, dp[i]);
            // cout << i << ' ' << dp[i].e / 1.0 * (dp[i].w + W) << el;
        }

        return ans >= mid * W;
    }

    void solve() {
        sort(all(a), [](const A &x, const A &y) {
            return x.c < y.c;
        });

        double l = 0, r = 1e9, ans = 0, limit = pow(10, -4);
        while(r - l >= limit) {
            double mid = l + (r - l) / 2.0;
            if(checkMid(mid)) {
                l = mid;
                ans = mid;
            } else {
                r = mid;
            }
        }

        cout << fixed << setprecision(4) << ans;
    }   
}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub4::check()) {Sub4::solve(); return;}
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