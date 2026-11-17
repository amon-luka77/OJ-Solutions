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
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 1e5;
ll n, maxA[N + 1], dp[N + 1];
map<ll, ll> ts;
vector<ll> b;

void read() {
    cin >> n;
    b.pb(0);
    FOR(i, 1, n) {
        ll x; cin >> x;
        b.pb(x);
        ts[x] ++;
    }


    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin() + 1, b.end()), b.end());
}

void solve() {
    dp[1] = b[1] * ts[b[1]];
    maxA[1] = dp[1];
    ll ans = dp[1];

    FOR(i, 2, b.size() - 1) {
        if(b[i] - b[i - 1] != 1) dp[i] = maxA[i - 1] + ts[b[i]] * b[i];
        else dp[i] = maxA[i - 2] + ts[b[i]] * b[i];

        ans = max(ans, dp[i]);
        maxA[i] = max(maxA[i - 1], dp[i]);
    }

    cout << ans;
}

void write() {

}

int main() {
    boost;
    file("CHONQUA");
    read();
    solve();
    write();
    return 0;
}