#include<bits/stdc++.h>
#define ft first
#define sc second
#define pb push_back
#define ll int
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define el '\n'
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define NAME "nhap"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}


const ll N = 1e5;
const ll block = 230;
ll n, m, q;
ll dp[N + 1];
bool mark[N + 1]; vector<pair<ll, ll>> P[N + 1];
vector<ll> edge[N + 1];

void read() {
    cin >> n >> m >> q;
    FOR(i, 1, m) {ll x, y; cin >> x >> y; edge[y].pb(x);}
}

bool vs[N + 1];
vector<pair<ll, ll>> pre;

void preprocess() {
    FOR(u, 1, n) {
        pre.pb({0, u});
        for(auto j : edge[u]) {
            pre.pb({1, j});
            for(auto &[x, y] : P[j]) pre.pb({x + 1, y});
        } sort(all(pre), greater<pair<ll, ll>>());

        P[u].pb(pre[0]); vs[pre[0].sc] = 1;
        FOR(j, 1, pre.size() - 1) {
            if(P[u].size() == block) break;
            if(!vs[pre[j].sc]) {
                P[u].pb(pre[j]); vs[pre[j].sc] = 1;
            }
        }

        for(auto &[x, y] : pre) vs[y] = 0;
        pre.clear();
    }

//    FOR(i, 1, n) {
//        cerr << "cet dinh thu: " << i << el;
//        for(auto &[i, j] : P[i]) {
//            cerr << "[" << j << ", " << i << "], ";
//        }
//        cerr << el;
//    }
}
vector<ll> child;

void calLight(ll u, ll y) {
    FOR(i, 1, y) {ll x; cin >> x; child.pb(x); mark[x] = 1;}
    ll ans = -1;
    for(auto &[d, v] : P[u]) if(!mark[v]) {
        ans = d; break;
    }

    for(auto j : child) mark[j] = 0; child.clear();
    cout << ans << el;
}

void calHeavy(ll u, ll y) {
    FOR(i, 1, y) {ll x; cin >> x; child.pb(x); mark[x] = 1;}
    FOR(i, 1, n) for(auto j : edge[i]) if(!mark[j] || (mark[j] && dp[j])) {
            dp[i] = max(dp[i], dp[j] + 1);
    }

    ll ans = (mark[u] && !dp[u] ? -1 : dp[u]); memset(dp, 0, sizeof dp);
    for(auto i : child) mark[i] = 0;
    child.clear();
    cout << ans << el; return;
}

void solve() {
    preprocess();
    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;
        if(y < block) calLight(x, y);
        else calHeavy(x, y);
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
    return 0;
}
