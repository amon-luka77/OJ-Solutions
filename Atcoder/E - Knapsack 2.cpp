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
const ll N = 1000;
ll n, w, gh = 0, dp[(ll)1e5 + 5];
struct kk {
    ll weight, val;
} a[N + 5];
void read() {
    cin >> n >> w;
    for(ll i = 1; i <= n; i ++) {
        ll x, y; cin >> x >> y;
        gh += y;
        a[i] = {x, y};
    }

    for(ll i = 1; i <= (ll)1e5; i ++) {
        dp[i] = 1e9;
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = gh; j >= a[i].val; j --) {
            if(j >= a[i].val) dp[j] = min(dp[j], dp[j - a[i].val] + a[i].weight);
        }
    }
}
void write() {
    for(ll i = gh; i >= 1; i --) {
        if(dp[i] <= w) {
            cout << i;
            exit(0);
        }
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}