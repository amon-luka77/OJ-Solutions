#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[25][25], bang[25][25], cnt[25][25];
ll dx[] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
ll dy[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
void bomtang(ll x, ll y) {
    for(ll i = 1; i <= 8; i ++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) cnt[nx][ny] ++;
    }
}
void bomtru(ll x, ll y) {
    for(ll i = 1; i <= 8; i ++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) cnt[nx][ny] --;
    }
}
bool checkbom1(ll x) {
    for(ll i = 1; i <= m; i ++) {
        if(cnt[x][i] != a[x][i]) return true;
    }
    return false;
}
bool checkbom2(ll x, ll y) {
    for(ll i = 1; i <= y; i ++) {
        if(cnt[x][i] != a[x][i]) return true;
    }
    return false;
}
void backtrack(ll x, ll y) {
    if((x > 2 && checkbom1(x - 2)) || (x > 1 && y > 2 && checkbom2(x - 1, y - 2))) return; 
    if(x > n) {
        for(ll i = 1; i <= n; i ++) {
            for(ll j = 1; j <= m; j ++) {
                cout << bang[i][j] << ' ';
            }
            cout << "\n";
        }
        exit(0);
    }
    else {
        for(ll k = 0; k <= 1; k ++) {
            bang[x][y] = k;
            if(k == 1) {
               bomtang(x, y); 
            }
            if(y == m) backtrack(x + 1, 1);
            else backtrack(x, y + 1);
            if(k == 1) {
               bomtru(x, y); 
            }
            bang[x][y] = -1;
        }  
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
            bang[i][j] = -1;
        }
    }
    backtrack(1, 1);
}