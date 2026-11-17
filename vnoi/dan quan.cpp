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
const ll N = 0;
ll t;

void read() {
    cin >> t;
    while(t --) {
        ll n, k, s;
        cin >> n >> k >> s;
        vector<ll> a(n + 5, 0);
        vector<ll> b, c;

        FOR(i, 1, n) {
            cin >> a[i];
        }

        ll cnt = 0;
        FOR(l, 1, n) {
            ll r = l;
            if(k == 0) {
                cnt --;
                break;
            }
            while(r <= n && a[r] > s) r ++;
            
            if(l == r) {
                cnt ++;
            } else {
                l = r - 1;
            }

            k --;
        }

        cout << cnt << el;
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