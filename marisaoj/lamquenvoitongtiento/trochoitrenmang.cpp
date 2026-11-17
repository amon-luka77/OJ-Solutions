#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll n, prefix[N];
void chuanbi() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        ll x;
        cin >> x;
        prefix[i] = prefix[i - 1] + x;
    }
}
void solve() {
    ll ans = LLONG_MIN;
    for(ll i = 1; i <= n; i ++) {
        ans = max({ans, prefix[i] * (-1) + prefix[n] - prefix[i], prefix[i] + (prefix[n] - prefix[i]) * (-1)});
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    return 0;
}