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
#define NAME ""
using namespace std;

const ll N = 1e6;
ll n, k, a[N + 1];

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}
void read() {
    cin >> n >> k; vector<ll> b;
    FOR(i, 1, n) {cin >> a[i]; b.pb(a[i]);}
    sort(all(b)); b.erase(unique(all(b)), b.end());
    FOR(i, 1, n) {a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;}
}

namespace Sub1 {
    bool check() {
        return k == 1;
    }

    ll bit[N + 1];

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getSum(ll l, ll r) {
        ll res = 0; l --;
        for(; l >= 1; l -= l & -l) res -= bit[l];
        for(; r >= 1; r -= r & -r) res += bit[r];
        return res;
    } 

    void solve() {
        ll res = 0;
        FOR(i, 1, n) {
            // cout << a[i] << ' ';
            res += getSum(a[i] + 1, n);
            updated(a[i], 1);
        }

        cout << res;
    }
}

namespace Sub2 {
    bool check() {
        return k == 2;
    }

    ll bit[N + 1], dpLeft[N + 1], dpRight[N + 1];

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getSum(ll l, ll r) {
        ll res = 0; l --;
        for(; l >= 1; l -= l & -l) res -= bit[l];
        for(; r >= 1; r -= r & -r) res += bit[r];
        return res;
    } 

    void solve() {
        FOR(i, 1, n) {
            // cout << a[i] << ' ';
           dpLeft[i] = dpLeft[i - 1] + getSum(a[i] + 1, n);
            updated(a[i], 1);
        }
        
        memset(bit, 0, sizeof bit);

        FORD(i, n, 1) {
            dpRight[i] = dpRight[i + 1] + getSum(1, a[i] - 1);
            updated(a[i], 1); 
        }

        ll res = 1e18;
        FOR(i, 1, n - 1) {
            res = min(res, dpLeft[i] + dpRight[i + 1]);
        }

        cout << res;
    }
}

namespace Sub3 {
    bool check() {
        return (n <= 100 && k <= 100);
    }

    ll bit[N + 1];
    vector<vector<ll>> dp;

    void updated(ll i, ll val) {
        for(; i <= n; i += i & -i) bit[i] += val;
    }

    ll getSum(ll l, ll r) {
        ll res = 0; l --;
        for(; l >= 1; l -= l & -l) res -= bit[l];
        for(; r >= 1; r -= r & -r) res += bit[r];
        return res;
    } 

    void solve() {
        dp.assign(n + 5, vector<ll> (k + 5, 1e18));
        FOR(j, 0, k) dp[0][j] = 0;
        // dp[1][1] = 0;

        FOR(i, 1, n) FOR(j, 1, min(i, k)) {
            ll cost = 0;
            // cerr << "\nbegin";
            FORD(K, i, j) {
                cost += getSum(1, a[K] - 1);
                dp[i][j] = min(dp[i][j], dp[K - 1][j - 1] + cost);
                // if(i == 2 && j == 1) cerr << el << K << ' ' << dp[K - 1][j - 1] + cost << el;
                updated(a[K], 1);
            }

            FOR(K, j, i) updated(a[K], -1);
            // cerr << "\nend";
        }

        // FOR(i, 1, n) FOR(j, 1, k) cout << i << ' ' << j << ' '  << dp[i][j] << el;
        cout << dp[n][k];
    }

}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub2::check()) {Sub2::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
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