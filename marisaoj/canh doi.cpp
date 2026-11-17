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
ll n, m; 

void read() {
    cin >> n >> m;

    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;

        edge[x].pb({y, z});
        edge[y].pb({x, z});
    } 
}

void solve() {
    priority_queue<NODE, vector<NODE>, cmp> pq;
    FOR(i, 1, n) d[i] = 1e18;

    d[1] = 0;
    pq.push({1, 0, 1});

    while(!pq.empty()) {
        auto [u, dis, w] = pq.top();

        if(w != 1 && dis + w > d[u]) continue;

        for(auto [i, j] : edge[u]) {
            if(w == 1) {
                pq.push
            }
        }
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