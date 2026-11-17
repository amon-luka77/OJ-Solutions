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
const ll N = 50;
ll n, m, a[N + 1][N + 1], dis[N + 1][N + 1][5];
struct KK {
    ll x, y, role;
} path[N + 1][N + 1][5];
vector<ll> dx = {0, -1, 0, 1, 0}, dy = {1, 0, 0, 0, -1};
void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    memset(dis, -1, sizeof(dis));
}

void bfs() {
    queue<KK> q;
    q.push({n, 1, 0});
    dis[n][1][0] = 0;
    while(!q.empty()) {
        auto t = q.front(); q.pop();
        for(ll i = 0; i <= 4; i ++) {
            ll new_i = t.x + dx[i], new_j = t.y + dy[i];
            if(new_i < 1 || new_i > n || new_j < 1 || new_j > m) continue;
            ll new_role = (a[new_i][new_j] - (t.role + 1) + 4) % 4;
            if(new_role == 0) continue;
            ll role2 = (t.role + 1) % 4;
            if(dis[new_i][new_j][role2] == -1) {
                dis[new_i][new_j][role2] = dis[t.x][t.y][t.role] + 1;
                path[new_i][new_j][role2] = {t.x, t.y, t.role};
                q.push({new_i, new_j, role2});
            } else {
                if(dis[new_i][new_j][role2] > dis[t.x][t.y][t.role] + 1) {
                    dis[new_i][new_j][role2] = dis[t.x][t.y][t.role] + 1;
                    path[new_i][new_j][role2] = {t.x, t.y, t.role};
                    q.push({new_i, new_j, role2});
                }
            }
        }
    }
}   

void solve() {
    bfs();
    ll ans = 1e18;
    for(ll i = 0; i <= 3; i ++) {
        if(dis[1][m][i] != -1 && ans > dis[1][m][i]) {
            ans = dis[1][m][i];
        }
    }
    if(ans == 1e18) {
        cout << "NO";
        exit(0);
    }  else cout << ans << el;
    vector<char> kq;
    for(ll i = 0; i <= 3; i ++) {
        if(ans != dis[1][m][i]) continue;
        KK b = {1, m, i};
        vector<char> sunny;
        while(!(b.x == n && b.y == 1 && b.role == 0)) {
            KK c = path[b.x][b.y][b.role];
            if(c.x - 1 == b.x) sunny.pb('N');
            else if(c.x + 1 == b.x) sunny.pb('S');
            else if(c.y + 1 == b.y) sunny.pb('E');
            else if(c.y - 1 == b.y) sunny.pb('W');
            else sunny.pb('P');
            b = c;
        }
        if((kq.empty()) || (sunny < kq)) kq = sunny;
    }
    for(ll i = kq.size() - 1; i >= 0; i --) {
        cout << kq[i];
    }
    
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
