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
ll n, k;
bool check[N + 1];
vector<ll> snt;

void sang() {
    snt.pb(-1);
    for(ll i = 1; i <= N; i ++) {
        check[i] = 1;
    }

    check[1] = 0;
    for(ll i = 2; i * i <= N; i ++) {
        if(check[i]) {
            for(ll j = i * i; j <= N; j += i) {
                check[j] = 0;
            }
        }
    }

    for(ll i = 1; i <= N; i ++) {
        if(check[i]) snt.pb(i);
    }
}

void read() {
    sang();
    cin >> n >> k;
    string s = "";
    for(ll i = 1; i <= n; i ++) {
        string t = to_string(snt[i]);
        s += t;
    }

    ll cnt = 0;
    stack<char> st;

    for(ll i = 0; i < s.size(); i ++) {
        while(!st.empty() && k > 0 && st.top() < s[i]) {
            st.pop();
            k --;
        }

        st.push(s[i]);
    }

    while(!st.empty() && k > 0) {
        st.pop();
        k --;
    }

    vector<char> ans;
    while(!st.empty()) {
        ans.pb(st.top());
        st.pop();
    }

    for(ll i = ans.size() - 1; i >= 0; i --) cout << ans[i];
}

void solve() {

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

// 2 3 5 7 11 13 17 19 23 29