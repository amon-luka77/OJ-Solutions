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
ll t, s[N + 1], d[N + 1], add[N + 1], multiDis[N + 1], dis[N + 1];
ll n, m, k, l, hoa[N + 1];
bool mark[N + 1];

void read() {
    cin >> t;
}

void solve() {
    while(t --) {
        cin >> n >> m >> k >> l;

        FOR(i, 1, n) {
            dis[i] = 1e18;
            add[i] = 0;
            multiDis[i] = 1e18;
            mark[i] = 0;
            hoa[i] = 0;
        }

        FOR(i, 1, k) {
            cin >> s[i];
            hoa[s[i]] ++;
        }
        FOR(i, 1, l) {
            cin >> d[i];
        }

        vector<vector<ll>> edge(n + 1, vector<ll>());
        FOR(i, 1, m) {
            ll x, y; cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        } 

        queue<ll> q;
        q.push(1);
        dis[1] = 0;
        add[1] = hoa[1];

        while(!q.empty()) {
            auto u = q.front();
            q.pop();

            for(auto i : edge[u]) {
                if(dis[i] == 1e18) {
                    dis[i] = dis[u] + 1;
                    add[i] = add[u] + hoa[i];
                    q.push(i);
                }
            }
        }

        queue<tuple<ll, ll, ll>> pq;
        FOR(i, 1, l) {
            pq.push({d[i], hoa[d[i]], d[i]});
            multiDis[d[i]] = 0;
            if(add[d[i]] == k) {
                mark[d[i]] = 1;
            }
        }

        while(!pq.empty()) {
            auto [u, y, root] = pq.front();
            pq.pop();

            for(auto i : edge[u]) {
                if(multiDis[i] == 1e18) {
                    multiDis[i] = multiDis[u] + 1;
                    if(dis[root] == dis[i] + multiDis[i] && add[i] + y == k) {
                        mark[i] = 1;
                    }
                    pq.push({i, y + hoa[i], root});
                }
            }
        }

        FOR(i, 2, n) cout << mark[i];
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