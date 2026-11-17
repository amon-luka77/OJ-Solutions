#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll n, q, prefix[N], sum[N];
void chuanbi() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        ll x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
        sum[i] = sum[i - 1] + prefix[i];
    }
}
void solve() {
    while(q--) {
        ll l, r;
        cin >> l >> r;
        ll x = r - l + 1;
        cout << prefix[r] * x - (sum[r - 1] - sum[l - 2]) << "\n";
    }   
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    return 0;
}