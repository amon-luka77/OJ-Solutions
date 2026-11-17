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
ll n, m, k, a[N + 1][N + 1], prefix[N + 1][N + 1];
bool vs[N + 1][N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void read() {
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            cin >> a[i][j];
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
        }
    }
}

bool check(ll i, ll j) {
    if(vs[i][j] || i < k || j < k) return 0;

    pair<ll, ll> l = {i - k + 1, j - k + 1};

    ll sum = prefix[i][j] - prefix[i][l.sc - 1] - prefix[l.ft - 1][j] + prefix[l.ft - 1][l.sc - 1];
    return sum <= 0;
}

void dfs(ll i, ll j) {
    vs[i][j] = 1;

    for(auto [x, y] : d) {
        ll new_i = i + x;
        ll new_j = j + y;
        if(new_i < 1 || new_i > n || new_j < 1 || new_j > m) continue;
        if(check(new_i, new_j)) {
            dfs(new_i, new_j);
        }
    }
}

void solve() {
    ll cnt = 0;

    for(ll i = 1; i <= n; i ++) {
        for(ll j = 1; j <= m; j ++) {
            if(check(i, j)) {
                cnt ++;
                dfs(i, j);
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