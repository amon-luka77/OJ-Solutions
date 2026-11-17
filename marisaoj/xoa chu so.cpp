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
ll n, k, a[N + 1];
stack<ll> st;

void read() {
    string s; cin >> s; n = s.size(); s = ' ' + s;
    FOR(i, 1, n) a[i] = s[i] - '0';
    cin >> k;
}

void solve() {
    FOR(i, 1, n) {
        while(k > 0 && !st.empty() && a[st.top()] < a[i]) {
            st.pop();
            k --;
        }

        st.push(i);
    }

    while(k > 0) {
        st.pop(); k --;
    }

    vector<ll> ans;
    while(!st.empty()) {
        ans.pb(a[st.top()]); st.pop();
    }

    FORD(i, ans.size() - 1, 0) cout << ans[i];
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