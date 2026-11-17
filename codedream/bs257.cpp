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
const ll N = 5e5;
ll n, a[N + 1], l[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    stack<ll> st;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++) {
        while(!st.empty() && a[st.top()] < a[i]) {
            st.pop();
            ans ++;
        }

        if(!st.empty()) ans ++;

        st.push(i);
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