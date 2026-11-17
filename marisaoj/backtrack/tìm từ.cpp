#include<bits/stdc++.h>
#define ll long long
#define ft first 
#define sc second
using namespace std;
ll n, m;
ll dx[] = {0, -1, 0, 1, 0};
ll dy[] = {0, 0, 1, 0, -1}; 
vector<pair<ll, ll>> vt; 
char a[10][10];
string s;
void backtrack(ll x, ll y, ll pos) {
    for(ll i = 1; i <= 4; i ++) {
        ll nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
            if(a[nx][ny] == s[pos]) {
                if(pos == s.size() - 1) {
                    cout << "YES";
                    exit(0);
                } else backtrack(nx, ny, pos + 1);
            }
            else continue;
        } else {
            if(i < 4) continue;
            else return;
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
        }
    }
    cin >> s;
    s = '0' + s;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(a[i][j] == s[1]) vt.push_back({i, j});
        }
    }
    if(vt.empty()) {
        cout << "NO";
        return 0;
    }
    for(ll i = 0; i < vt.size(); i ++) {
        if(s.size() <= 2) {
            cout << "YES";
            return 0;
        }else backtrack(vt[i].ft, vt[i].sc, 2);
    }
    cout << "NO";
    return 0;
}