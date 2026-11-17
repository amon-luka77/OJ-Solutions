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
ll n, m;
void read() {
    cin >> n >> m;
}
void solve() {
    ll d = __gcd(n, m);
    if(d == 1) {
        cout << -1;
        exit(0);
    }
    for(ll i = 2; i * i <= d; i ++) {
        if(d % i == 0) {
            cout << d / i;
            exit(0);
        }
    }
}
void write() {
    cout << 1;
}
int main() {
    boost;
    file("UOCCHUNG");
    read();
    solve();
    write();
    return 0;
}