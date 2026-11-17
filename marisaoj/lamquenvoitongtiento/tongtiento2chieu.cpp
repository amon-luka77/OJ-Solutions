#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3 + 5;
ll n, m, q, prefix[N][N];
void chuanbi() {
    cin >> n >> m >> q;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            ll x;
            cin >> x;
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + x;
        }
    }
}
ll tinh(ll x, ll y, ll x1, ll y1) {
    return prefix[x1][y1] + prefix[x - 1][y - 1] - prefix[x1][y - 1] - prefix[x - 1][y1];
}
void solve() {
    while(q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << tinh(a, b, c, d) << "\n";
    }   
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    return 0;
}