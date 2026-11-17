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
ll n, L, R, X, u, v, a[N + 1];
ll d[N + 1];

vector<ll> edge[N + 1];
vector<ll> b;

ll binary(ll k) {
    ll l = 1, r = b.size() - 1, ans = 0;

    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(b[mid] <= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return ans;
}

void read() {
    cin >> n >> L >> R >> X >> u >> v;
    b.pb(0);

    FOR(i, 1, n) {
        cin >> a[i];
        b.pb(a[i]);
    }

    sort(b.begin() + 1, b.end());
    b.erase(unique(b.begin()  + 1, b.end()), b.end());

    FOR(i, 1, n) {
        a[i] = binary(a[i]);
        edge[a[i]].pb(i);
    }
}

void solve() {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    FOR(i, 1, n) d[i] = 1e18;

    d[u] = 0;
    pq.push({0, u});

    while(!pq.empty()) {
        auto [dis, u] = pq.top();
        pq.pop();

        if(dis > d[u]) continue;

        for(auto i : edge[a[u]]) {
            if(i == u) continue;

            if(d[i] > dis + X) {
                d[i] = dis + X;
                pq.push({d[i], i});
            } 
        }

        edge[a[u]].clear();

        if(u > 1 && d[u - 1] > dis + L) {
            d[u - 1] = dis + L;
            pq.push({d[u - 1], u - 1});
        }

        if(u < n && d[u + 1] > dis + R) {
            d[u + 1] = dis + R;
            pq.push({d[u + 1], u + 1});
        }
    }

    cout << d[v];
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