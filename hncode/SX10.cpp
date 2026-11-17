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
ll n, k;
void read() {
    cin >> n >> k;
}
void solve() {
    vector<ll> a, prefix;
    ll sum = 0, tong = 0;
    while(n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    ll them = 0;
    for(ll i = 0; i < a.size(); i ++) {
        ll x = tong + a[i] + them;
        tong += a[i];
        sum += x % 10;
        them = x / 10;
    }
    ll u = tong + them;
    sum += (a.size() + k - 2 * a.size() + 1) * (u % 10);
    for(ll i = 0; i < a.size(); i ++) {
        tong -= a[i];
        ll u = tong + them;
        sum += u % 10;
        them = u / 10;
    }
    cout << sum;
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