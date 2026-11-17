/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
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

const ll N = 26;
ll n, a[N + 1], dp[MASK(N) + 1];

void read() {
    cin >> n;
    FOR(i, 0, n - 1) {
        string s; cin >> s;
        FOR(j, 0, s.size() - 1) a[i] |= MASK(s[j] - 'a');
    }
}

void solve() {
    ll cnt = 0;

    FOR(i, 0, n - 1) dp[MASK(i)] = a[i];
    
    FOR(mask, 0, MASK(n) - 1) {
        if(__builtin_popcountll(mask) >= 2) {
            ll temp = mask & -mask;
            dp[mask] = dp[temp] | dp[mask ^ temp];
        }

        cnt += (dp[mask] == MASK(26) - 1);
    }

    cout << cnt;
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