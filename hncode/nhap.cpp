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
const ll N = 1e5;
ll n, m, ans = 1e18, a[N + 1], t[N + 1], d[N + 1];
vector<pair<ll, ll>> b;

void read() {
    cin >> n >> m;
    b.pb({0, 0});
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        b.pb({a[i], i});
    }
    for(ll i = 1; i <= n; i ++) {
        cin >> t[i];
    }

    sort(b.begin() + 1, b.end());
}

ll binaryL(ll tg) {
    ll l = 1, r = b.size() - 1, t = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(b[mid].ft >= tg) {
            r = mid - 1;
            t = mid;
        } else {
            l = mid + 1;
        }
    }

    return t;
}

ll binaryR(ll tg) {
    ll l = 1, r = b.size() - 1, t = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(b[mid].ft <= tg) {
            l = mid + 1;
            t = mid;
        } else {
            r = mid - 1;
        }
    }

    return t;
}

struct Q2 {
    ll x, y, z;
};

struct Q3 {
    ll x, y, z;
};

struct cmp {
    bool operator()(Q3 &x, Q3 &y) {
        return x.z > y.z;
    }
};

void dijkstra(ll idx) {
    for(ll i = 1; i <= n; i ++) {
        d[i] = 1e18;
    }

    d[idx] = t[idx];
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({t[idx], idx});
    
    while(!pq.empty()) {
        auto [dis, u] = pq.top();
        pq.pop();

        if(a[u] == m) {
            ans = min(ans, dis);
            continue;
        }
        if(dis > d[u]) continue;

        ll L = binaryL(a[u] + 1), R = binaryR(a[u] + 1);
        for(ll i = L; i <= R; i ++) {
            if(d[b[i].sc] > dis + t[b[i].sc] + abs(u - b[i].sc)) {
                d[b[i].sc] = dis + t[b[i].sc] + abs(u - b[i].sc);
                pq.push({d[b[i].sc], b[i].sc});
            }
        }
    }
}

void solve() {
    if(m == 1) {
        for(ll i = 1; i <= n; i ++) {
            if(a[i] == m) {
                ans = min(ans, t[i]);
            }
        }
        cout << ans;
    } else if(m == n) {
        vector<Q2> k;
        for(ll i = 1; i <= n; i ++) {
            k.pb({a[i], i, t[i]});
        }
        sort(all(k), [](Q2 &x, Q2 &y) {
            return x.x < y.x;
        });

        ans = k[0].z;
        for(ll i = 1; i < k.size(); i ++) {
            ans += k[i].z + abs(k[i - 1].y - k[i].y);
        }
        cout << ans;
    } else {
        for(ll i = 1; i <= n; i ++) {
            if(a[i] == 1) {
                dijkstra(i);
            }
        }

        cout << ans;
    }
}

void write() {

}

int main() {
    boost;
    file("MH");
    read();
    solve();
    write();
    return 0;
}