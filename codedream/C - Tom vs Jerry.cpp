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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;

const ll N = 1e6;
ll n, m, q, X, Y;

vector<ll> edge[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, m) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }

    cin >> X >> Y;
}

void bfs(ll u, vector<ll> &dis) {
    queue<ll> q;
    q.push(u);
    dis[u] = 0;

    while(!q.empty()) {
        ll v = q.front();
        q.pop();

        for(auto i : edge[v]) if(dis[i] == 1e18) {
            dis[i] = dis[v] + 1;
            q.push(i);
        }
    }
}

void solve() {
    vector<ll> disX(n + 1, 1e18), disY(n + 1, 1e18);
    bfs(X, disX), bfs(Y, disY);

    cin >> q;
    while(q --) {
        ll x; cin >> x;
        if(disX[x] <= disY[x]) cout << "YES" << el;
        else cout << "NO" << el;
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