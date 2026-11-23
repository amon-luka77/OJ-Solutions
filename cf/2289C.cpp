#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);

    FOR(i ,1, n) cin >> a[i];

    vector<int> L(n + 1), R(n + 1);

    stack<int> st;

    FOR(i, 1, n) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) L[i] = 1;
        else L[i] = st.top() + 1;
        st.push(i);
    } while(!st.empty()) st.pop();

    for(int i = n; i >= 1; i --) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) R[i] = n;
        else R[i] = st.top() - 1;
        st.push(i);
    }

    ll ans = 0;

    FOR(i, 1, n) {
        if(L[i] == i || R[i] == i) ans += (R[i] - L[i] + 1);
        else ans += 2;
    }

    // if(n == 4) FOR(i, 1, n) cout << i << ' ' << L[i] << ' ' << R[i] << "\n";

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}