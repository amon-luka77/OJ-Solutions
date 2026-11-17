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
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 20;
ll n, W, a[N + 1], sum[MASK(N) + 1];
pair<ll, ll> dp[MASK(N) + 1];

void read() {
    cin >> n >> W;
    FOR(i, 0, n - 1) cin >> a[i];
}

void solve() {
    FOR(i, 0, MASK(n) - 1) dp[i] = {1e18, 1e18};
    dp[0] = {1, 0};

    FOR(mask, 0, MASK(n) - 1) FOR(i, 0, n - 1) if(!BIT(mask, i)) {
        auto [cnt, lastWeight] = dp[mask];

        if(lastWeight + a[i] <= W) dp[mask | MASK(i)] = min(dp[mask | MASK(i)], {cnt, lastWeight + a[i]});
        else dp[mask | MASK(i)] = min(dp[mask | MASK(i)], {cnt + 1, a[i]});
    }

    cout << dp[MASK(n) - 1].ft;
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