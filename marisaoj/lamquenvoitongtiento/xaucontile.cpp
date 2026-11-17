#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
using namespace std;
const ll N = 1e5 + 5;
ll a[N], x, y, prefix1[N], n, prefix0[N], cnt = 0;
string s;
map<ll, ll> ts;
void chuanbi() {
    cin >> x >> y >> s;
    n = s.size();
    s = ' ' + s;
    for(ll i = 1; i <= n; i ++) {
        prefix0[i] = prefix0[i - 1] + (s[i] == '0') * y;
        prefix1[i] = prefix1[i - 1] + (s[i] == '1') * x;
        a[i] = prefix0[i] - prefix1[i];
    }
}
void solve() {
    ts[a[0]]++;
    for(ll i = 1; i <= n; i ++) {
        cnt += ts[a[i]];
        ts[a[i]] ++;
    }
}
void in() {
    cout << cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
}