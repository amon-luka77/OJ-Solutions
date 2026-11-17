#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
using namespace std;
const ll N = 2*1e5;
ll n, q, s, t, l, r, x, amon = 0;
ll a[N + 5], diff[N + 5];
void chuanbi() {
    cin >> n >> q >> s >> t >> a[0];
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    diff[n + 1] = 0;
}
void tru(ll l, ll r) {
    amon = amon - (diff[l] < 0) * (t * (abs(diff[l]))) + (diff[l] >= 0) * (s * diff[l]);
    if(r < n) amon = amon - (diff[r + 1] < 0) * (t * (abs(diff[r + 1]))) + (diff[r + 1] >= 0) * (s * diff[r + 1]);
}
void tang(ll l, ll r) {
    amon = amon + (diff[l] < 0) * (t * (abs(diff[l]))) - (diff[l] >= 0) * (s * diff[l]);
    if(r < n) amon = amon + (diff[r + 1] < 0) * (t * (abs(diff[r + 1]))) - (diff[r + 1] >= 0) * (s * diff[r + 1]);
}
void solve() {
    for(ll i = 1; i <= q; i ++) {
        ll l, r, x;
        cin >> l >> r >> x;
        if(i == 1) {
            diff[l] += x;
            diff[r + 1] -= x;
            for(ll j = 1; j <= n; j ++) {
                if(diff[j] < 0) {
                    amon += t * (abs(diff[j]));
                } else {
                    amon -= s * (diff[j]);
                }
            }
        } else {
            tru(l, r);
            diff[l] += x;
            diff[r + 1] -= x;
            tang(l, r);
        }
        cout << amon << "\n";
    }
}
void in(){
    
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
    return 0;
}
