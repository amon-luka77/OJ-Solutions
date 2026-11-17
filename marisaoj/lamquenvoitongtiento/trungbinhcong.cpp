#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll n, k, prefix[N], A[N];
void chuanbi() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i];
    }
}
void solve() {
    vector<ll> a[abs(k) + 5];
    ll ans = 0;
    a[0].push_back(0);
    for(ll i = 1; i <= n; i ++) {
        ll d = (abs(k) + prefix[i] % k) % abs(k);
        if(!a[d].empty()) {
            for(ll j = 0; j < a[d].size(); j ++) {
                if(prefix[i] == prefix[a[d][j]] + k * (i - a[d][j])) {
                    ans ++;
                }
            }
        }
        a[d].push_back(i);
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