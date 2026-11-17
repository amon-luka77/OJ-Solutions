#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1000;
ll n, m, a[N + 1][N + 1];
bool mark[N + 1][N + 1];
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 0) {
                mark[i][j] = 1;
            }
        }
    }
}
void solve() {
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++) {
        ll maxn = a[i][1];
        cnt += (!mark[i][1]);
        mark[i][1] = 1;
        for(ll j = 2; j <= m; j ++) {
            if(a[i][j] > maxn) {
                cnt += (!mark[i][j]);
                mark[i][j] = 1;
                maxn = a[i][j];
            }
        }
    }
    
    for(ll i = 1; i <= n; i ++) {
        ll maxn = a[i][m];
        cnt += (!mark[i][m]);
        mark[i][m] = 1;
        for(ll j = m - 1; j >= 1; j --) {
            if(a[i][j] > maxn) {
                cnt += (!mark[i][j]);
                mark[i][j] = 1;
                maxn = a[i][j];
            }
        }
    }

    for(ll j = 1; j <= m; j ++) {
        ll maxn = a[1][j];
        cnt += (!mark[1][j]);
        mark[1][j] = 1;
        for(ll i = 2; i <= n; i ++) {
            if(a[i][j] > maxn) {
                cnt += (!mark[i][j]);
                mark[i][j] = 1;
                maxn = a[i][j];
            }
        }
    }

    for(ll j = 1; j <= m; j ++) {
        ll maxn = a[n][j];
        cnt += (!mark[n][j]);
        mark[n][j] = 1;
        for(ll i = n - 1; i >= 1; i --) {
            if(a[i][j] > maxn) {
                cnt += (!mark[i][j]);
                mark[i][j] = 1;
                maxn = a[i][j];
            }
        }
    }

    cout << cnt;
}
void write() {

}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}