/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 250000;
ll n, m, k, p[N + 1], dis[N + 1];

vector<ll> edge[N + 1];

void read() {
    cin >> k >> n;
    FOR(i, 1, k) cin >> p[i];
    cin >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
    }
}

void bfs(ll u, ll endNode) {
    FOR(i, 1, n) dis[i] = 1e18;
    dis[u] = 0;
    queue<ll> q;
    q.push(u);

    while(!q.empty()) {
        ll v = q.front(); q.pop();

        for(auto i : edge[v]) if(dis[i] == 1e18) {
            dis[i] = dis[v] + 1;
            q.push(i);
        }
    }
}

void solve() {
    ll ans = 0;

    FOR(i, 2, k) {
        bfs(p[i - 1], p[i]);
        ll x = p[i];
        if(dis[x] == 1e18) break;
        if(dis[x] == 1) ans += 2;
        else ans ++;
    }

    cout << ans;
}

void write() {

}

int main() {
    boost;
    freopen("7E07.inp", "r", stdin);
    freopen("7E07.ans", "w", stdout);
    read();
    solve();
    write();
    return 0;
}