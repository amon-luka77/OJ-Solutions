#include<bits/stdc++.h>
#define ll long long
#define ft first 
#define sc second
using namespace std;
ll n, m, q;
ll l[10], r[10], dk[10];
map<ll, ll> ts;
ll a[10];
ll kq = 0;
void backtrack(ll pos) {
    if(pos > n) {
        for(ll i = 1; i <= q; i ++) {
            if(a[l[i]] + a[r[i]] != dk[i]) return;
        }
        kq ++;
        return;
    }
    for(ll i = 1; i <= m; i ++) {
        a[pos] = i; 
        ts[i] ++;
        backtrack(pos + 1);
        ts[i] = 0;
        a[pos] -= i;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(ll i = 1; i <= q; i ++) {
        cin >> l[i] >> r[i] >> dk[i];
    }
    backtrack(1);
    cout << kq;
}