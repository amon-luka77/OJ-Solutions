#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
using namespace std;
const ll N = 1e5;
map<ll, ll> diff, cont;
ll n, q, l, r, a[N + 5], nam = 0, thao = 0;
void chuanbi() {
    cin >> n >> q;
    for(ll i = 1; i <= q; i ++) {
        cin >> l >> r;
        diff[l] -= (l - 1); diff[r + 1] += (l - 1);
        cont[l] ++; cont[r + 1] --;
    }
}
void solve() {
    for(ll i = 1; i <= n; i ++) {
        nam += diff[i], thao += cont[i];
        a[i] = thao * i + nam;
    }
}
void in(){
    for(ll i = 1; i <= n; i ++) cout << a[i] << ' ';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
}