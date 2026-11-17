/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 4e5;
ll n, m;
vector<vector<ll>> a;
bool vs[N + 1];
pair<ll, ll> pos[N + 1];
vector<pair<ll, ll>> d = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<pair<ll, ll>> d2 = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void read() {
    cin >> n >> m;
    a.assign(n + 1, vector<ll>(m + 1, 0));
    FOR(i, 1, n) FOR(j, 1, m) {cin >> a[i][j]; pos[a[i][j]] = {i, j};}
}

set<ll> order;

bool bfs() {
    vs[1] = 1;

    FOR(num, 1, n * m) {
        if(!vs[num]) return 0;
        auto [i, j] = pos[num];

        for(auto [x, y] : d) {
            ll newI = i + x, newJ = j + y;
            if(newI < 1 || newI > n || newJ < 1 || newJ > m || vs[a[newI][newJ]]) continue;
 
            ll color = a[newI][newJ];
            vs[color] = 1;
        }
    }

    return 1;
}

vector<ll> amon;

bool checkGrid() {
    for(auto color : amon) {
        for(auto [x, y] : d2) {
            ll i = pos[color].ft + x, j = pos[color].sc + y;
            if(i < 1 || i > n || j < 1 || j > m) continue;

            bool ok = 1;

            for(auto [X, Y] : d) {
                ll newI = i + X, newJ = j + Y;
                if(newI < 1 || newI > n || newJ < 1 || newJ > m) continue;
    
                if(a[newI][newJ] < a[i][j]) ok = 0;
            }

            if(ok && a[i][j] != 1) return 0;
        }
    }

    return 1;
}

ll cnt = 0;

void check(ll color) {
    auto [i, j] = pos[color];
    bool ok = 1;
    for(auto [x, y] : d) {
        ll newI = i + x, newJ = j + y;
        if(newI < 1 || newI > n || newJ < 1 || newJ > m) continue;

        if(a[newI][newJ] < color) ok = 0;
    }

    if(ok) {
        cnt ++;
        order.insert(color);
        for(auto [x, y] : d) {
            ll newI = i + x, newJ = j + y;
            if(newI < 1 || newI > n || newJ < 1 || newJ > m) continue;

            order.insert(a[newI][newJ]);
        }
    }
}

// set<pair<ll, ll>> ans;

void solve() {
    if(bfs()) {cout << 0; return;}

    FOR(i, 2, n * m) check(i);
    if(cnt > 2) {cout << 2; return;}
    ll res = 0; for(auto i : order) {amon.pb(i);}

    for(auto i : order) FOR(j, 1, n * m) if(i != j && !(j < i && order.find(j) != order.end())) {
        ll &x = a[pos[i].ft][pos[i].sc], &y = a[pos[j].ft][pos[j].sc];
        swap(x, y); swap(pos[i], pos[j]);
        // cout << min(i, j) << ' ' << max(i, j) << el;
        amon.pb(j);
        res += checkGrid();
        amon.pop_back();
        // ans.insert({min(i, j), max(i, j)});
        swap(x, y); swap(pos[i], pos[j]);
    }
        
    if(res) cout << "1 " << res;
    else cout << 2;
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