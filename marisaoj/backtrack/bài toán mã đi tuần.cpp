#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[10][10];
ll dx[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
ll dy[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};
void backtrack(ll x, ll y, ll cnt) {
    for(ll i1 = 1; i1 <= 8; i1 ++) {
        ll nx = x + dx[i1], ny = y + dy[i1];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 0) {
            a[nx][ny] = cnt;
            if(cnt == n * m) {
                for(ll i = 1; i <= n; i ++) {
                    for(ll j = 1; j <= m; j ++) {
                        cout << a[i][j] << ' ';
                   }
                    cout << "\n";
                }
                exit(0);
            } else {
                backtrack(nx, ny, cnt + 1);
                a[nx][ny] = 0; 
            }
        } else continue;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    backtrack(3, 2, 1);
}