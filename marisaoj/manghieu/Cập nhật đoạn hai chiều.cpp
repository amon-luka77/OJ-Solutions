#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e3 + 5;
ll n, m, q;
ll d[N][N], amon[N][N];
void chuanbi() {
    cin >> n >> m >> q;
}
void solve() {
    while(q--) {
        ll a, b, c, d1;
        cin >> a >> b >> c >> d1;
        d[a][b] ++;
        d[c + 1][d1 + 1] ++;
        d[a][d1 + 1] --;
        d[c + 1][b] --;
    }
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            amon[i][j] = d[i][j] + amon[i - 1][j] + amon[i][j - 1] - amon[i - 1][j - 1];
        }
    }
}
void in() {
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cout << amon[i][j] << ' ';
        }
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    chuanbi();
    solve();
    in();
}