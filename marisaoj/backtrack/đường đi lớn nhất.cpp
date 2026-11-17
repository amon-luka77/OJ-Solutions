#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[7][7];
ll dx[] = {0, 1, 0};
ll dy[] = {0, 0, 1};
ll ans = 0;
ll cn = 0;
void backtrack(ll x, ll y) {
    for(ll i = 1; i <= 2; i ++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx == 4 && ny == 4) {
            ans = max(ans, cn + a[nx][ny]);
            return;
        }
        if(nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4) {
            cn += a[nx][ny];
            backtrack(nx, ny);
            cn -= a[nx][ny];
        } else continue;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 1; i <= 4; i ++) {
        for(ll j = 1; j <= 4; j ++) {
            cin >> a[i][j];
        }
    }
    cn += a[1][1];
    backtrack(1, 1);
    cout << ans;
}