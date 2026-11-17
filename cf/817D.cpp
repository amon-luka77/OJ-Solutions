#include<bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

const int N = 1e6;
int n, a[N + 1];
int minLeft[N + 1], minRight[N + N1];
int maxLeft[N + 1], maxRight[N + 1];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    stack<int> st;

    FOR(i, 1, n) {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        maxLeft[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    } while(!st.empty()) st.pop();

    FOR(i, 1, n) {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        minLeft[i] = (st.empty() ? 1 : st.top() + 1);
        st.push(i);
    } while(!st.empty()) st.pop();

    FORD(i, n, 1) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        maxRight[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    } while(!st.empty()) st.pop();

    FORD(i, n, 1) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        minRight[i] = (st.empty() ? n : st.top() - 1);
        st.push(i);
    } while(!st.empty()) st.pop();

    ll res = 0;
    FOR(i, 1, n) {
        res += a[i] * (i - maxLeft[i] + 1) * (maxRight[i] - i + 1);
        res -= a[i] * (i - minLeft[i] + 1) * (minRight[i] - i + 1);
    }

    cout << res;
}
