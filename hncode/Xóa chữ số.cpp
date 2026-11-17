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
string s; ll k, n, a[N + 1];
void read() {
    cin >> s >> k;
    n = s.size();
    s = ' ' + s;
    for(ll i = 1; i < s.size(); i ++) {
        a[i] = s[i] - '0';
    }
}
void solve() {
    stack<ll> st;
    ll sl = 0;
    for(ll i = 1; i <= n; i ++) {
        while(!st.empty() && st.top() < a[i] && sl < k) {
            st.pop();
            sl ++;
        }
        if(sl == k) {
            vector<ll> ans;
            while(!st.empty()) {
                ans.pb(st.top());
                st.pop();
            }
            for(ll j = ans.size() - 1; j >= 0; j--) {
                cout << ans[j];
            }
            for(ll j = i; j <= n; j ++) {
                cout << a[j];
            }
            exit(0);
        }
        st.push(a[i]);
    }
    sl = 0;
    vector<ll> ans;
    while(!st.empty()) {
        ans.pb(st.top());
        st.pop();
    }
    reverse(all(ans));
    for(ll i = 0; i < ans.size(); i ++) {
        sl ++;
        if(sl > n - k) break;
        cout << ans[i];
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