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
const ll N = 1e6;
ll n, a[N + 1], l[N + 1], r[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    stack<ll> st;
    ll ans = 0;

    for(ll i = 1; i <= n + 1; i ++) {
        while(!st.empty() && a[st.top()] > a[i]) {
            ll k = st.top();
            st.pop();
            ll cr = a[k], cd;
            if(st.empty()) cd = i - 1;
            else cd = i - st.top() - 1;
            if(cr <= cd) ans = max(ans, cr); 
        }

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