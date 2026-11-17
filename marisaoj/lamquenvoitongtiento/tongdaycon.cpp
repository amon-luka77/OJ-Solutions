#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll prefix[N], a[N], n, x;
map<ll, ll> ts;
void chuanbi() {
    cin >> n >> x;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
    }
}
void lam() {
    ll ans = 0;
    ts[prefix[0]] ++;
    for(ll i = 1; i <= n; i ++) {
        ans += ts[prefix[i] - x];
        ts[prefix[i]] ++;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    lam();
}