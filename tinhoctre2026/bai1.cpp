#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 0;
ll n, a, b, c;

void read() {
    cin >> n >> a >> b >> c;
}

void solve() {
    if(b == 0) {
        set<pair<ll, ll>> ans;

        for(ll x = 1; x * x <= n; x ++) {
            if(n % x == 0) {
                ll k = (n / x) - a;
                if(k % c == 0) {
                    ll y = k / c;
                    ans.insert({x, y});
                }
            }
        }

        if(ans.empty()) {
            cout << 0;
            exit(0);
        }

        cout << ans.size() << el;

        for(auto &[i, j] : ans) {
            cout << i << ' ' << j << el;
        }
    }
    else {
        set<pair<ll, ll>> ans;
        for(ll x = 0; x <= 1000000; x ++) {
            ll k = n - a * x;
            ll t = b + c * x;

            if(t != 0 && k % t == 0) {
                ll y = k / t;
                if(y >= 0) {
                    ans.insert({x, y});
                }
            }
        }

        for(ll y = 0; y <= 1000000; y ++) {
            ll k = n - b * y;
            ll t = a + c * y;

            if(t != 0 && k % t == 0) {
                ll x = k / t;
                if(x >= 0) {
                    ans.insert({x, y});
                }
            }
        }

        if(ans.empty()) {
            cout << 0;
            exit(0);
        }

        cout << ans.size() << el;

        for(auto &[i, j] : ans) {
            cout << i << ' ' << j << el;
        }
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