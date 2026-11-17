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
ll n, k, a[N + 1], dp[N + 1];
void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    for(ll i = 1; i <= k; i ++) {
        for(ll j = 1; j <= n; j ++) {
            if(i >= a[j] && !dp[i - a[j]]) {
                dp[i] = 1;
                break;
            }
        }
    }
}
void write() {
    if(dp[k]) cout << "First";
    else cout << "Second";
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}