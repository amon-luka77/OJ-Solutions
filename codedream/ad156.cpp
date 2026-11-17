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
const ll N = 2e5;
ll n, m, s, t, dis[55][55][7][7];
pair<ll, ll> S, T;
vector<pair<ll, ll>> b = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char a[55][55];
struct kk {
    ll x, y, cl, huong;
};
void read() {
    cin >> n >> m >> s >> t;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                S = {i, j};
                a[i][j] = '.';
            }
            if(a[i][j] == 'T') {
                T = {i, j};
                a[i][j] = '.';
            }
        }
    }
    memset(dis, -1, sizeof(dis));
}
void solve() {
    queue<kk> q;
    dis[S.ft][S.sc][s][1] = 0;
    q.push({S.ft, S.sc, s, 1});
    while(!q.empty()) {
        auto i = q.front(); q.pop();
        if(i.x == T.ft && i.y == T.sc) continue;
        for(ll j = 1; j <= 4; j ++) {
            ll new_i = i.x + b[j].ft, new_j = i.y + b[j].sc;
            ll mau = (i.cl % 5 + 4) % 5 + (i.cl % 5 == 1) * 5;
            if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || a[new_i][new_j] == '#') continue;
            if(dis[new_i][new_j][mau][j] == -1 || dis[new_i][new_j][mau][j] > dis[i.x][i.y][i.cl][i.huong] + min(abs(j - i.huong), 4 - abs(j - i.huong)) + 1) {
                dis[new_i][new_j][mau][j] = dis[i.x][i.y][i.cl][i.huong] + min(abs(j - i.huong), 4 - abs(j - i.huong)) + 1;
                q.push({new_i, new_j, mau, j});
            }
        }
    }
}
void write() {
    ll ans = 1e9;
    for(ll i = 1; i <= 4; i ++) {
        if(dis[T.ft][T.sc][t][i] != -1) ans = min(ans, dis[T.ft][T.sc][t][i]);
    }
    cout << ans;
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}
