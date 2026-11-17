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

const ll N = 1e5;
ll n, m, d1[N + 1], d2[N + 1];

vector<pair<ll, ll>> edge[N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 1, m) {
        ll x, y, z; cin >> x >> y >> z;
        edge[x].pb({y, z});
        edge[y].pb({x, z});
    }
}

void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    FOR(i, 1, n) {
        d1[i] = 1e18;
        d2[i] = 1e18;
    }

    d1[1] = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        auto [dis, u] = pq.top();
        pq.pop();

        if(dis > d2[u]) continue;

        for(auto [i, j] : edge[u]) {
            if(d1[i] > dis + j) {
                d2[i] = d1[i];
                d1[i] = dis + j;
                pq.push({d1[i], i});
            }

            if(d2[i] > dis + j && d1[i] < dis + j) {
                d2[i] = dis + j;
                pq.push({d2[i], i});
            }
        }
    }

    cout << d2[n];
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