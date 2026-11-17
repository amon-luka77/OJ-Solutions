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
ll n;
pair<ll, ll> T1[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> T1[i].ft >> T1[i].sc;
    }
    ll ans = 1e18;
    for(ll i = 1; i <= 1000; i ++) {
        for(ll j = 1; j <= 1000; j ++) {
            ll kc = 0;
            for(ll k = 1; k <= n; k ++) {
                kc += abs(i - T1[k].ft) + abs(j - T1[k].sc);
            }
            ans = min(ans, kc);
        }
    }
    cout << ans;
}

void solve() {

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