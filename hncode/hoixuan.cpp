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
const ll N = 1e5;
ll n, k, a[N + 1], ans[N + 1], cnt[(ll)1e6 + 1];
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i]; a[n + i] = a[i];
    }
}
void solve() {
    ll l = 1, r = min(2 * k + 1, 2 * n);
    for(ll i = l; i <= r; i ++) {
        cnt[a[i]] ++;
    }
    while(l <= r && r <= 2 * n) {
        ll vt = l + k; if(vt > n) vt -= n;
        ans[vt] = cnt[a[vt]];
        if(r < 2 * n) cnt[a[r + 1]] ++;
        cnt[a[l]] --;
        r ++; l ++;
    }
    for(ll i = 1; i <= n ; i++) {
        cout << ans[i] << ' ';
    }

}
void write() {

}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}
// 1 1 2 2 2 1 1 1 2 2 2 1 1