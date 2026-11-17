#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
string s;
ll prefix[N];
map<ll, ll> ts;
void chuanbi(ll n) {
    for(ll i = 1; i <= n; i ++) {
        prefix[i] = prefix[i - 1] + (s[i] == '1') - (s[i] == '0');
    }
}
void lam(ll n) {
    ll ans = 0;
    ts[prefix[0]] ++;
    for(ll i = 1; i <= n; i ++) {
        ans += ts[prefix[i]];
        ts[prefix[i]] ++;
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ll n = s.size();
    s = ' ' + s;
    chuanbi(n);
    lam(n);
}