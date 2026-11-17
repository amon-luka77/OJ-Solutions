#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e6;
ll n, m, s, t, dis[N + 1], trace[N + 1];
bool check[N + 1];
ll gh_r = -1e18, gh_l = 1e18;

struct KK {
    ll x, y, z;
};

vector<KK> edge[N + 1];

void read() {
    cin >> n >> m >> s >> t;

    for(ll i = 1; i <= m; i ++) {
        ll x, y, z, h; cin >> x >> y >> z >> h;
        gh_r = max(gh_r, h);
        gh_l = min(gh_l, h);
        edge[x].pb({y, z, h});
        edge[y].pb({x, z, h});
    }

    for(ll i = 1; i <= n; i ++) {
        dis[i] = 1e18;
    }
}

void bfs(ll s, ll k) {
    queue<ll> q;
    q.push(s);
    check[s] = 1;

    while(!q.empty()) {
        ll u = q.front(); q.pop();

        for(auto [i, j, h] : edge[u]) {
            if(h >= k && !check[i]) {
                check[i] = 1;
                q.push(i);
            }
        }
    }
}

bool check_go(ll k) {
    for(ll i = 1; i <= n; i ++) check[i] = 0;

    bfs(s, k);

    return check[t];
}

void solve() {
    ll l = gh_l, r = gh_r, ans = 0;

    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(check_go(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }

    }

    cout << ans << el;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dis[u]) continue;

        for(auto [i, j, h] : edge[u]) {
            if(h < ans) continue;
            if(dis[i] > d + j) {
                dis[i] = d + j;
                trace[i] = u;
                pq.push({dis[i], i});
            }
        }
    }
    vector<ll> kq;

    while(t > 0) {
        kq.pb(t);
        t = trace[t];
    }

    for(ll i = kq.size() - 1; i >= 0; i --) {
        cout << kq[i] << ' ';
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