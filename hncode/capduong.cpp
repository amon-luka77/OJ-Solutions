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
const ll N = 2e5;
ll n;
void read() {
    cin >> n;
    ll am = 0, duong = 0, cnt = 0;
    for(ll i = 1; i <= n; i ++) {
        ll x; cin >> x;
        if(x > 0) {
            cnt += duong;
            duong ++;
        } else if(x < 0) {
            cnt += am;
            am ++;
        }
    }
    cout << cnt;
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