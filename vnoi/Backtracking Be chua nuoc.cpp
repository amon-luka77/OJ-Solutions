#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb puhs_back
using namespace std;
const ll N = 20;
ll n, k, a[N + 1];
ll ans = 0;

void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}

void backtrack(ll pos, ll more) {
    if(more < 0) return;
    if(pos > n) {
        ll nuoc = 0;
        for(ll i = 1; i <= n; i ++) {
            ll max_left = 0, max_right = 0;
            for(ll j = 1; j <= i; j ++) max_left = max(max_left, a[j]);
            for(ll j = i; j <= n; j ++) max_right = max(max_right, a[j]);
            nuoc += min(max_left, max_right) - a[i];
        }
        ans = max(ans, nuoc);
        return;
    }

    for(ll i = 0; i <= more; i ++) {
        a[pos] += i;
        backtrack(pos + 1, more - i);
        a[pos] -= i;
    }
}

void solve() {
    backtrack(1, k);
}

void write() {
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("vnoi.inp", "r", stdin);
    freopen("vnoi.out", "w", stdout);
    read();
    solve();
    write();
    return 0;
}

