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
ll n, a[N + 1], l[N + 1], r[N + 1];
void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    stack<ll> st;
    for(ll i = 1; i <= n; i ++) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) l[i] = 1;
        else l[i] = st.top() + 1;
        st.push(i);
    }

    stack<ll> stl;

    for(ll i = n; i >= 1; i --) {
        while(!stl.empty() && a[stl.top()] >= a[i]) stl.pop();
        if(stl.empty()) r[i] = n;
        else r[i] = stl.top() - 1;
        stl.push(i);
    }

    for(ll i = 1; i <= n; i ++) {
        cout << l[i] << ' ';
    }

    cout << el;

    for(ll i = 1; i <= n; i ++) {
        cout << r[i] << ' ';
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