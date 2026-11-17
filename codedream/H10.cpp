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
#define MASK(i) (1 << i)
using namespace std;

const ll N = 1e5, LOG = 18;
ll n, q, a[N + 1], minA[N + 1][LOG + 1], ansK[N + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        minA[i][0] = a[i];
    }

    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) {
        minA[i][j] = min(minA[i][j - 1], minA[i + MASK(j - 1)][j - 1]);
    }
}

ll getMin(ll l, ll r) {
    ll k = __lg(r - l + 1);
    return min(minA[l][k], minA[r - MASK(k) + 1][k]);
}

void solve() {
    FOR(k, 1, n) {
        FOR(i, 1, n - k + 1) {
            ll l = i, r = l + k - 1;
            ansK[k] += getMin(l, r);
        }
    }

    while(q --) {
        ll l, r, k; cin >> l >> r >> k;
        if(l == 1 & r == n) {
            cout << ansK[k] << el;
            continue;
        }
        ll ans = 0;

        FOR(i, l, r - k + 1) {
            ll j = i + k - 1;
            ans += getMin(i, j);
        }
        cout << ans << el;
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