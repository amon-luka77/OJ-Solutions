/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 1e5;
ll n, a[N + 1], l[N + 1], r[N + 1], ans = 0;

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

void solve() {
    stack<ll> st;
    FOR(i, 1, n) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) l[i] = 1;
        else l[i] = st.top() + 1;

        st.push(i);
    }

    st = stack<ll>();

    FORD(i, n, 1) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(st.empty()) r[i] = n;
        else r[i] = st.top() - 1;

        st.push(i);
    }

    FOR(i, 1, n) {
        ans = max(ans, (r[i] - l[i] + 1) * a[i]);
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