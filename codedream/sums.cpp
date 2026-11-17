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
#define NAME "sums"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 70;
ll n, a[N + 1];
ll sum = 0;

void read() {
    cin >> n;
    FOR(i, 1, n) {cin >> a[i]; sum += a[i];}
}

ll dpSumDiff[70000];
ll cntMax = 0, maxVal = 0;

void sumDiffrent() {
    ll res = 0; dpSumDiff[0] = 1;
    FOR(i, 1, n) FORD(j, sum, a[i]) if(dpSumDiff[j - a[i]]) dpSumDiff[j] += dpSumDiff[j - a[i]];
    cntMax = dpSumDiff[1], maxVal = 1;
    FOR(i, 1, sum) {
        res += (dpSumDiff[i] > 0);
        if(dpSumDiff[i] >= dpSumDiff[maxVal]) {
            maxVal = i; cntMax = dpSumDiff[i];
        }
    }
    cout << res << el;
    cout << maxVal << ' ' << cntMax << el;
}

ll dp[N + 1][70001];
pair<ll, ll> trace [N + 1][70001];

void traceSum() {
    sort(a + 1, a + n + 1, greater<ll>());
    FOR(i, 0, n) dp[i][0] = 1;

    FOR(i, 1, n) FOR(j, 0, sum) {
        dp[i][j] |= dp[i - 1][j];
        if(j >= a[i]) {
            dp[i][j] |= dp[i - 1][j - a[i]];
        }
    }

    ll pos = n;

    vector<ll> ans;
    while(pos) {
        if(dp[pos - 1][maxVal - a[pos]]) {
            ans.pb(a[pos]); maxVal -= a[pos];
        } pos --;
    }

    FOR(i, 0, ans.size() - 1) cout << ans[i] << ' ';
}

void solve() {
    sumDiffrent();
    traceSum();
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
