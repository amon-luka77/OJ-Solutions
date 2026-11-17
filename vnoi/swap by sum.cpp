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
const ll N = 2e5;
ll t;

void read() {
    cin >> t;
    while(t --) {
        ll n, k; cin >> n >> k;
        bool ok = 1;
        vector<ll> a(n + 1, 0), b(n + 1, 0);

        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        FOR(i, 1, n) {
            ll r = i;

            while(r < n && min(a[r], k - a[r]) == min(a[r + 1], k - a[r + 1])) r ++;

            vector<ll> checkA, checkB;

            FOR(j, i, r) {
                checkA.pb(a[j]);
                checkB.pb(b[j]);
            }

            sort(all(checkA));
            sort(all(checkB));

            FOR(j, 0, checkA.size() - 1) {
                if(checkA[j] != checkB[j]) {
                    ok = 0; break;
                }
            }

            if(!ok) break;
            i = r;
        }

        if(ok) cout << "YES" << el;
        else cout << "NO" << el;
    }
}   

void solve() {

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