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
const ll N = 2e5, maxN = 2e6;
ll n, k, a[N + 1];
vector<ll> snt;
vector<bool> check(maxN + 1, false);
void sang() {

    check[0] = false, check[1] = false;
    for(ll i = 2; i * i <= maxN; i ++) {
        if(!check[i]) continue;
        for(ll j = i * i; j <= maxN; j += i) {
            check[j] = false;
        }
    }

    for(ll i = 1; i <= maxN; i ++) {
        if(check[i]) snt.pb(i);
    }
}
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        for(auto j : snt) {
            ll mu = 0;
            while(a[i] % j == 0) {
                mu ++;
                a[i] /= j;
            }
            if(!mark[j][mu % k] && !mark[j][k - (mu % k)]) {
                cnt ++;
                !mark[j][mu % k] = true; mark[j][k - (mu % k)] = true;
            }
        }
    }
}
void solve() {

}
void write() {

}
int main() {
    boost;
    //file();
    sang();
    read();
    solve();
    write();
    return 0;
}