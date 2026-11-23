#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
using namespace std;

void solve() {
    ll x; cin >> x;

    // uoc chan: x, uoc le: y
    // x = 2^k * x
    // -> x = k * y
    // y = y

    // x >= y

    // -> k = 1 -> thua
    // k = 0 || k  1 thang
    // 

    if(x % 2 || x % 4 == 0) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;

    while(t --) solve();

    return 0;
}