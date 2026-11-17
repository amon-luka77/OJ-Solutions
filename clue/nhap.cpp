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
const ll N = 10;
ll n, m, t;
vector<pair<ll, ll>> D = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

struct kk {
    ll x, y, z;
};

void read() {
    while(cin >> n >> m >> t) {
        if(n == 0 && m == 0 && t == 0) break;

        vector<vector<char>> a(n + 1, vector<char>(m + 1, '7'));
        pair<ll, ll> start_node, end_node;

        for(ll i = 1; i <= n; i ++) {
            for(ll j = 1; j <= m; j ++) {
                cin >> a[i][j];
                if(a[i][j] == 'S') {
                    start_node = {i, j};
                }

                if(a[i][j] == 'D') {
                    end_node = {i, j};
                }
            }
        }

        vector<vector<vector<bool>>> d(n + 1, vector<vector<bool>>(m + 1, vector<bool>(t + 1, false)));

        queue<kk> q;
        q.push({start_node.ft, start_node.sc, 0});

        while(!q.empty()) {
            auto [x, y, dis] = q.front();
            q.pop();
            if(dis >= t) break;

            for(auto [i, j] : D) {
                ll new_i = i + x;
                ll new_j = j + y;
                ll dis_node = dis + 1;

                if(new_i < 1 || new_i > n || new_j < 1 || new_j > m || d[new_i][new_j][dis_node] || a[new_i][new_j] == 'X') continue;

                if(!d[new_i][new_j][dis_node]) {
                    d[new_i][new_j][dis_node] = 1;
                    q.push({new_i, new_j, dis_node});
                }
            }
        }

        if(d[end_node.ft][end_node.sc][t]) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

void solve() {

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