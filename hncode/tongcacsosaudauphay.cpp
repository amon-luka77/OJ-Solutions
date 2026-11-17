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
ll a, b, n;
void read() {
    cin >> a >> b >> n;
}
void solve() {
    ll sl = 0, sum = 0;
    if(a % b == 0) {
        cout << 0;
        exit(0);
    }
    a %= b;
    while(1) {
        if(a < b) a *= 10;
        sl ++;
        if(a < b) continue;
        if(sl > n) break;
        sum += a / b;
        a %= b;
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