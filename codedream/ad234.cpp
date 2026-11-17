#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 50;
ll n, m, ans, cnt = 0, a[N + 1][N + 1], color[N + 1][N + 1], newColor[N + 1];
bool markColor[N + 1][N + 1], vs[N + 1];

vector<ll> edge[N + 1];
vector<pair<ll, ll>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void read() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
}

void dfsColor(ll i, ll j, ll cl) {
    color[i][j] = cl;
    for(auto &[x, y] : d) {
        ll newI = i + x, newJ = j + y;
        if(newI < 1 || newI > n || newJ < 1 || newJ > m) continue;
        if(color[newI][newJ] != 0 && color[newI][newJ] != cl && !markColor[color[newI][newJ]][cl]) {
            edge[cl].pb(color[newI][newJ]);
            edge[color[newI][newJ]].pb(cl);
            markColor[color[newI][newJ]][cl] = 1;
            markColor[cl][color[newI][newJ]] = 1;
        } 

        if(color[newI][newJ] == 0 && a[i][j] == a[newI][newJ]) dfsColor(newI, newJ, cl);
    }
}

void dfs(ll u, ll par) {
    ll cur = 0;
    vs[u] = 1;
    vector<bool> t(ans + 3, 0);
    t[newColor[u]] = 1;

    for(auto i : edge[u]) if(i != par) {
        FOR(j, 0, ans - 1) {
            if(!t[j]) {
                newColor[i] = j;
                t[j] = 1; 
                break;
            }
        }
    }

    for(auto i : edge[u]) if(!vs[i]) {
        dfs(i, u);
    }
}

void solve() {
    FOR(i, 1, n) FOR(j, 1, m) if(color[i][j] == 0) {
        dfsColor(i, j, ++cnt);
    }

    ans = 0;

    FOR(i, 1, cnt) {
        ans = max(ans, (ll)edge[i].size());
    }
    newColor[1] = 0;
    cout << ans << el;
    
    dfs(1, -1);

    FOR(i, 1, n) {
        FOR(j, 1, m) {
            cout << newColor[color[i][j]] << ' ';
        }
        cout << el;
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