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
const ll N = 1e3;
ll n, m, a[N + 1][N + 1], height[N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
}

ll mono_height() {
    ll ans = 0;
    stack<ll> st;

    for(ll i = 1; i <= m + 1; i ++) {
        while(!st.empty() && height[st.top()] > height[i]) {
            ll k = st.top();
            st.pop();
            ll dis;
            if(st.empty()) dis = i - 1;
            else dis = i - st.top() - 1;

            ans = max(ans, dis * height[k]);
        }

        st.push(i);
    }

    return ans;
}

void solve() {
    ll ans = 0;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(a[i][j] == 0) {
                height[j] = 0;
            } else {
                height[j] ++;
            }
        }
        
        ans = max(ans, mono_height());
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