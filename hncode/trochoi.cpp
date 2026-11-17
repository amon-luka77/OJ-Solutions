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
ll n, t;
void read() {
    cin >> n >> t;
    ll sum = 0;
    vector<ll> a, b;
    for(ll i = 1; i <= n; i ++) {
        ll x, y; cin >> x >> y;
        a.pb(x + y);
        b.pb(y);
    }
    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end(), greater<ll>());
    for(auto i : a) {
        if(t == 0 || i <= b[0]) break;
        t --;
        sum += i;
    }
    sum += t * b[0];
    cout << sum;
}
void solve() {

}
void write() {

}
int main() {
    boost;
    file("TROCHOI");
    read();
    solve();
    write();
    return 0;
}