#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll prefix[N], a[N], n, d;
map<ll, ll> ts;
void chuanbi() {
    cin >> n >> d;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        prefix[i] = (d + (prefix[i - 1] + a[i]) % d) % d;
    }
}
void lam() {
    ll ans = 0;
    ts[prefix[0]] ++;
    for(ll i = 1; i <= n; i ++) {
        ans += ts[prefix[i]];
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