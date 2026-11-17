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
ll n, m, sl = 0;
ll dis[N + 1][N + 1];
bool vs[N + 1][N + 1];
char a[N + 1][N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
struct kk {
    ll fi, se;
};
queue<kk> q;
vector<char> ans;
pair<ll, ll> A, path[N + 1][N + 1];
void read() {
    cin >> n >> m;
    memset(dis, -1, sizeof(dis));
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                A = {i, j};
                a[i][j] = '.';
            }
            if(a[i][j] == 'M') {
                q.push({i, j});
                dis[i][j] = 0;
                a[i][j] = '.';
            }
        }
    }
}

void trace(ll i, ll j) {
    while(!(i == A.ft && j == A.sc)) {
        pair<ll, ll> k = path[i][j];
        if(i == k.ft - 1) {
            ans.pb('U');
        } else if(i == k.ft + 1) {
            ans.pb('D');
        } else if(j == k.sc + 1) {
            ans.pb('R');
        } else if (j == k.sc - 1) {
            ans.pb('L');
        }
        i = k.ft;
        j = k.sc;
    }
}

void solve() {
    while(!q.empty()) {
        auto t = q.front(); q.pop();
        
        for(auto j : d) {
            ll new_i = t.fi + j.ft, new_j = t.se + j.sc;
            if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || a[new_i][new_j] == '#' || dis[new_i][new_j] != -1) continue;
            dis[new_i][new_j] = dis[t.fi][t.se] + 1;
            q.push({new_i, new_j});
        }
    }
    queue<pair<kk, ll>> p;
    p.push({{A.ft, A.sc}, 0});
    vs[A.ft][A.sc] = true;
    while(!p.empty()) {
        auto t = p.front(); p.pop();

        if(t.ft.fi == 1 || t.ft.fi == n || t.ft.se == 1 || t.ft.se == m) {
            trace(t.ft.fi, t.ft.se);
            cout << "YES" << el;
            cout << ans.size() << el;
            for(ll l = ans.size() - 1; l >= 0; l --) {
                cout << ans[l];
            }
            exit(0);
        }

        for(auto i : d) {
            ll new_i = t.ft.fi + i.ft, new_j = t.ft.se + i.sc;
            if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || a[new_i][new_j] == '#' || dis[new_i][new_j] != -1 && dis[new_i][new_j] <= t.sc + 1 || vs[new_i][new_j]) continue;
            path[new_i][new_j] = {t.ft.fi, t.ft.se};
            vs[new_i][new_j] = true;
            p.push({{new_i, new_j}, t.sc + 1});
            
        }
    }
}
void write() {
    cout << "NO";
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}
