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
ll n, x;
void read() {
    cin >> n >> x;
}
void solve() {
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++) {
        if(x % i == 0 && x / i <= n) cnt ++;
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