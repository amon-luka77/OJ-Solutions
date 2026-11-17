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

const ll N = 500, mod = 1e9 + 7;
ll n, dp[MASK(20) + 1], a[N + 1];

void read() {
    cin >> n;
    FOR(i, 0, n - 1) cin >> a[i];
}

bool checkMask(ll mask, ll pos) {
    if(__builtin_popcountll(mask) <= 2) return 1;
    mask ^= MASK(pos);

    ll maskLeft = mask & ~(MASK(pos + 1) - 1);
    ll Left = (maskLeft != 0) ? __builtin_ctzll(maskLeft) : __builtin_ctzll(mask);
    
    ll maskRight = mask & (MASK(pos) - 1);
    ll Right = (maskRight != 0) ? (63 - __builtin_clzll(maskRight)) : (63 - __builtin_clzll(mask));

    return a[Left] != a[Right];
}

bool check() {
    FOR(i, 0, n - 1) if(a[i] == a[(i + 1) % n]) return 0;
    return 1;
}

void solve() {
    dp[MASK(n) - 1] = check();

    FORD(mask, MASK(n) - 1, 1) if(dp[mask]) FOR(i, 0, n - 1) if(BIT(mask, i) && checkMask(mask, i)) {
        dp[mask ^ MASK(i)] += dp[mask]; 
        if(dp[mask ^ MASK(i)] >= mod) dp[mask ^ MASK(i)] -= mod;
    }

    // FOR(mask, 0, MASK(n) - 1) cout << mask << ' ' << dp[mask] << el;
    cout << dp[0];
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