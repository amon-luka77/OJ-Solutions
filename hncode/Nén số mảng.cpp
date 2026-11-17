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
ll n, k[2 * N + 1];
pair<ll, ll> a[N + 1];
unordered_map<ll, ll> ts;
void read() {
    cin >> n;
    vector<ll> b;
    for(ll i = 1; i <= n; i ++) {
        ll x, y; cin >> x >> y;
        a[i] = {x, x + y};
        b.pb(x); b.pb(x + y);
    }
    sort(b.begin(), b.end());
    if(b[0] != 1) {
        cout << 0; exit(0);
    }

    ll sl = 1;
    for(ll i = 0; i < b.size(); i ++) {
        if(ts[b[i]] == 0) {
            ts[b[i]] = sl;
            sl ++;
        }
    }

    for(ll i = 1; i <= n; i ++) {
        a[i].ft = ts[a[i].ft];
        a[i].sc = ts[a[i].sc];
    }
}
void solve() {
    sort(a + 1, a + n + 1);

    ll ans = 0;

    for(ll i = 1; i <= n; i ++) {
        k[a[i].sc] = max(k[a[i].sc], k[a[i].ft] + 1);
    }

    for(ll i = 1; i <= 2 * N; i ++) {
        ans = max(ans, k[i]);
    }

    cout << ans;
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