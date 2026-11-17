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

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 5e5;
ll n, m, q;
ll a[N + 1], b[N + 1], s[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];
    FOR(i, 1, m) cin >> s[i];
    cin >> q;
}

namespace Sub1 {
    bool check() {return n * q <= (ll)1e8;}

    ll sumVal[N + 1];
    ll preVal[N + 1];

    void solve() {
        FOR(i, 1, n) sumVal[b[i]] += a[i];
        while(q --) {
            ll opt; cin >> opt;
            if(opt == 1) {
                ll l, r, x; cin >> l >> r >> x;
                FOR(i, l, r) preVal[b[i]] = sumVal[b[i]];
                FOR(i, l, r) if(preVal[b[i]] < s[b[i]]) {
                    a[i] += x; sumVal[b[i]] += x;
                }
            } else {
                ll l, r; cin >> l >> r;
                ll maxVal = a[l], minVal = a[l];
                FOR(i, l, r) {
                    maxVal = max(maxVal, a[i]);
                    minVal = min(minVal, a[i]);
                } cout << maxVal << ' ' << minVal << el;
            }
//            FOR(i, 1, n) cout << a[i] << ' ';
//            cout << el;
        }
    }
}

void solve() {
    if(Sub1::check()) Sub1::solve(), void();
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
