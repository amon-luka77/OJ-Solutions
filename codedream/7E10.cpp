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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, m, edgeId = 0, a[N + 1];
vector<pair<ll, ll>> edge[7 * N + 1];

void read() {
    cin >> n >> m; edgeId = n;
    FOR(i, 1, m) {
        ll k; cin >> k;
        FOR(i, 1, k) cin >> a[i];
        FOR(i, 1, k) {
            edge[a[i]].pb({++edgeId, i - 1});
            edge[edgeId].pb({a[i], k - i});
            if(i > 1) edge[edgeId - 1].pb({edgeId, 0});
        }
        FORD(i, k, 1) {
            edge[a[i]].pb({++edgeId, k - i});
            edge[edgeId].pb({a[i], i - 1});
            if(i < k) edge[edgeId - 1].pb({edgeId, 0});
        }
    }
}

ll dis[7 * N + 1];
void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    memset(dis, 0x3f, sizeof dis); dis[1] = 0;

    while(!pq.empty()) {
        auto[d, u] = pq.top(); pq.pop();

        if(d > dis[u] || u == n) continue;

        for(auto &[i, j] : edge[u]) if(dis[i] > d + j) {
            dis[i] = d + j; pq.push({dis[i], i});
        }
    }

    cout << dis[n];
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}