#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll n, prefix[N], A[N], maxpref[N], minpref[N];
void chuanbi() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> A[i];
        prefix[i] = prefix[i - 1] + A[i];
    }

}
void maxprefix() {
    ll min_pref = 0, d = LLONG_MIN;
    for(ll i = n; i >= 1; i --) {
        d = max(d, prefix[n] - prefix[i - 1] - min_pref);
        maxpref[i] = d;
        min_pref = min(min_pref, prefix[n] - prefix[i - 1]);
    }
}
void minprefix() {
    ll min_pref = 0, d = LLONG_MIN;
    for(ll i = 1; i <= n; i ++) {
        d = max(d, prefix[i] - min_pref);
        minpref[i] = d;
        min_pref = min(min_pref, prefix[i]);
    }
}
void solve() {
    ll ans = LLONG_MIN;
    for(ll i = 1; i <= n; i ++) {
        if(i == 1) {
            ans = max(minpref[i] + maxpref[i + 1], ans);
        } else if(i == n) {
            ans = max(minpref[i - 1] + maxpref[i], ans);
        } else {
            ans = max({minpref[i] + maxpref[i + 1], minpref[i - 1] + maxpref[i], ans});
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    maxprefix();
    minprefix();
    solve();
    return 0;
}