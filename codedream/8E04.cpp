#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define el "\n"
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= b; i --)
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define NAME "8E04"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 2e6;
ll n, m, k;
vector<vector<ll>> a, b, prefix;
bool vs[N + 1];
struct HCN{ll x = 1e18, y = 0, z = 1e18, t = 0;}; HCN HCN_size[N + 1];
pair<ll, ll> color[N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void read() {
    cin >> n >> m >> k;
    a.assign(n + 1, vector<ll>(m + 1, 0));
    b.assign(n + 1, vector<ll>(m + 1, 0));
    prefix.assign(n + 1, vector<ll>(m + 1, 0));
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
}

inline posId(ll x, ll y) {return (x - 1) * m + y;}

void preprocess() {
    FOR(i, 1, n) FOR(j, 1, m) if(!vs[posId(i, j)]) {
        color[a[i][j]] = {i, j}; b[i][j] = 1; vs[posId(i, j)] = 1;
        HCN_size[a[i][j]] = {i, i, j, j};
        queue<pair<ll, ll>> q; q.push({i, j});

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
//            cerr << x << ' ' << y << el;

            for(auto &[X, Y] : d) {
                ll newI = x + X, newJ = y + Y;
                if(newI < 1 || newI > n || newJ < 1 || newJ > m || a[x][y] != a[newI][newJ] || vs[posId(newI, newJ)]) continue;

                auto [A, M, O, N] = HCN_size[a[newI][newJ]];
                HCN_size[a[newI][newJ]] = {min(A, newI), max(M, newI), min(O, newJ), max(N, newJ)};
                q.push({newI, newJ}); vs[posId(newI, newJ)] = 1;
            }
        }
    }

//    FOR(i, 1, n) FOR(j, 1, m) cerr << b[i][j] << " \n"[j == m];

    FOR(i, 1, n) FOR(j, 1, m) {
        prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1] + b[i][j];
    }

//    FOR(i, 1, k) {
//        auto [A, m, o, n] = HCN_size[i];
//        cerr << "dinh mau: " << i << "[" << A << ", " << m << ", " << o << ", " << n << "]\n";
//    }
}

ll mark[N + 1]; bool markColor[N + 1];

void solve() {
    preprocess();

    FOR(i, 1, k) {
        auto [x, y, z, t] = HCN_size[i];
        // [x, z]; [y, t]
        ll res = prefix[y][t] - prefix[y][z - 1] - prefix[x - 1][t] + prefix[x - 1][z - 1];
//        cerr << x << ' ' << z << ' ' << y << ' ' << t << el << res << el;
        ll pos = 0;

        FOR(j, z, t) if(!markColor[a[x][j]] && a[x][j] != i) {
            auto [K, L] = color[a[x][j]]; mark[++pos] = a[x][j]; markColor[a[x][j]] = 1;
            if(!(x <= K && K <= y && z <= L && L <= t)) res ++;
        }

        FOR(j, z, t) if(!markColor[a[y][j]] && a[y][j] != i) {
            auto [K, L] = color[a[y][j]]; mark[++pos] = a[y][j]; markColor[a[y][j]] = 1;
            if(!(x <= K && K <= y && z <= L && L <= t)) res ++;
        }

        FOR(j, x, y) if(!markColor[a[j][t]] && a[j][t] != i) {
            auto [K, L] = color[a[j][t]]; mark[++pos] = a[j][t]; markColor[a[j][t]] = 1;
            if(!(x <= K && K <= y && z <= L && L <= t)) res ++;
        }

        FOR(j, x, y) if(!markColor[a[j][z]] && a[j][z] != i) {
            auto [K, L] = color[a[j][z]]; mark[++pos] = a[j][z]; markColor[a[j][z]] = 1;
            if(!(x <= K && K <= y && z <= L && L <= t)) res ++;
        }

        FOR(i, 1, pos) markColor[mark[i]] = 0;

        cout << res - 1 << ' ';
    }
}


void write() {

}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    file();
    read();
    solve();
    write();
}
