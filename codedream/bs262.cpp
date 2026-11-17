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
const ll N = 1e3;
ll n, m, a[N + 1][N + 1], height[N + 1], dp[N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            char x; cin >> x;
            a[i][j] = x - '0';
        }
    }
}

ll mono_height() {
    ll sum = 0;
    stack<ll> st;
    memset(dp, 0, sizeof(dp));

    for(ll i = 1; i <= m; i ++) {
        while(!st.empty() && height[st.top()] > height[i]) {
            st.pop();
        }
        
        if(st.empty()) {
            dp[i] = i * height[i];
        } else {
            dp[i] = dp[st.top()] + (i - st.top()) * height[i];
        }

        sum += dp[i];

        st.push(i);
    }

    return sum;
}

void solve() {
    ll ans = 0;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(a[i][j] == 1) {
                height[j] ++;
            } else {
                height[j] = 0;
            }
        }
        
        ans += mono_height();
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