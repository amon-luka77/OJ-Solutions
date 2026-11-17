#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 6;
ll a[N], prefix[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i ++) cin >> a[i];
    for(ll i = 1; i <= n; i ++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll d = 0, MIN = prefix[0];
    for(ll i = 1; i <= n; i ++) {
        d = max(d, prefix[i] - MIN);
        MIN = min(MIN, prefix[i]);
    }
    cout << d;
}