#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 5;
ll n, q;
ll a[N], amon[N];
void chuanbi() {
    cin >> n >> q;
}
void solve() {
    while(q--) {
        ll x, y;
        cin >> x >> y;
        a[x - 1] ++;
        a[y] --;
    }
    for(ll i = 1; i <= n; i ++) {
        amon[i] = amon[i - 1] + a[i - 1];
    }
}
void in() {
    for(ll i = 1; i <= n; i ++) {
        cout << amon[i] << ' ';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
}