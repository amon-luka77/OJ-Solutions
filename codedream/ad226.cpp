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

const ll N = 2e5;
ll n, startNode, endNode;

vector<ll> edge[N + 1];

void read() {
    cin >> n;

    FOR(i, 1, n - 1) {
        ll x, y; cin >> x >> y;
        edge[x].pb(y);
        edge[y].pb(x);
    }
}

void bfs(ll u, vector<ll> &dis, ll t) {
    queue<ll> q;
    q.push(u);
    dis[u] = 0;


    while(!q.empty()) {
        ll v = q.front();
        q.pop();
        if(t == 0) startNode = v;
        if(t == 1) endNode = v;

        for(auto i : edge[v]) if(dis[i] == -1) {
            dis[i] = dis[v] + 1;
            q.push(i);
        }   
    }
}

void solve() {
    vector<ll> dis1(n + 1, -1), disEnd(n + 1, -1), disStart(n + 1, -1);
    bfs(1, dis1, 0);
    bfs(startNode, disStart, 1);
    bfs(endNode, disEnd, 77);

    FOR(i, 1, n) {
        cout << max(disStart[i], disEnd[i]) << ' ';
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