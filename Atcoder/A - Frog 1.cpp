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
ll n, h[N + 1], dp[N + 1];
void read() {
    cin >> n;
    for(ll i =1 ; i <= n; i ++) {
        cin >> h[i];
    }
}
void solve() {
    for(ll i = 2; i <= n; i ++) {
        if(i > 1) dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        if(i > 2) dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
    }
}
void write() {
    cout << dp[n];
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}