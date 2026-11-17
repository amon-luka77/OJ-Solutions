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
ll n, q, a[N + 1], dp[N + 1];
void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    stack<ll> st;
    
    for(ll i = n; i >= 1; i --) {
        while(!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }

        if(!st.empty()) {
            dp[i] = dp[st.top()] + 1;
        }

        st.push(i);
    }

}
void write() {
    while(q--) {
        ll x; cin >> x;
        cout << dp[x] << el;
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