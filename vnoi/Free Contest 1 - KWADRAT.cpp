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

ll n;

bool check(ll k) {
    if(k <= 1) return 0; 
    for(ll i = 2; i * i <= k; i ++) {
        if(k % i == 0) return 0;
    }
    return 1;
}

void read() {
    cin >> n;
    vector<pair<ll, ll>> luu;

    for(ll i = 2; i * i <= n; i ++) {
        if(check(i)) {
            ll cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt ++;
            }

            luu.pb({i, cnt});
        }
    }

    if(check(n)) {
        luu.pb({n, 1});
    }

    ll k = 1;

    for(auto &[i, j] : luu) {
        FOR(l, 1, (j + 1) / 2) {
            k *= i * i;
        }
    }

    cout << k;
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