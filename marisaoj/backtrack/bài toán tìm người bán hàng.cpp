#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, MIN = LLONG_MAX, sl = 1, sum = 0;
ll a[15][15];
map<ll, ll> ts;
void backtrack(ll pos, ll bd) {
    if(sl == n) {
        MIN = min(MIN, sum + a[pos][bd]);
        return;
    }
    for(ll i = 1; i <= n; i ++) {
        if(ts[i] > 0) continue;
        if(sum + a[pos][i] > MIN) continue;
        else {
            sl ++;
            ts[i] ++;
            sum += a[pos][i];
            backtrack(i, bd);
            sl --;
            ts[i] --;
            sum -= a[pos][i];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    for(ll i = 1; i <= n; i ++) {
        sum = 0, sl = 1, ts.clear(), ts[i] ++;
        backtrack(i, i);
    }
    cout << MIN;
}