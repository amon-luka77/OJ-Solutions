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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "CANDY"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e6;
ll n, m, a[N + 1], b[N + 1];

void read() {
    cin >> m >> n;
    FOR(i, 1, m) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
}

namespace Sub1 {
    bool check() {
        return (n <= 1000 && m <= 1000);
    }

    ll ans[10001];

    void solve() {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        FOR(i, 1, n) pq.push({0, i});
        FOR(i, 1, m) {
            // cerr << b[i] << ' ';
            // cerr << "begin\n";
            while(b[i] > 0) {
                auto [x, y] = pq.top(); pq.pop();
                ans[y] += a[i]; b[i] --;
                pq.push({x + a[i], y});
            }
            // cerr << "end\n";
        }
        FOR(i, 1, n) cout << ans[i] << ' ';
    }
}

namespace Sub2 {
    bool check() {
        FOR(i, 1, m) if(n % b[i] != 0) return 0;
        return 1;
    }
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll ans[N + 1];

    void solve() {
        ll k = b[1];
        for(ll i = 1; i <= n; i += k) pq.push({0, i});
        FOR(i, 1, m) {
            auto [x, y] = pq.top(); pq.pop();
            ans[y] += a[i]; b[i] --;
            pq.push({x + a[i], y});
        }


        for(ll i = 1; i <= n; i += k) FOR(j, 1, k) cout << ans[i] << ' ';
    }
}

namespace Sub3 {
    bool check() {
        return 1;
    }

    ll diff[N + 1], ans[N + 1];

    void solve() {
        ll pos = 1;
        FOR(i, 1, m) {
            if(pos + b[i] - 1 <= n) {
                diff[pos] += a[i];
                diff[pos + b[i]] -= a[i];
                pos += b[i]; if(pos > n) pos -= n;
            } else {
                diff[pos] += a[i];
                ll x = pos + b[i] - n;
                diff[1] += a[i];
                diff[x] -= a[i];
                pos = x;
            }
        }

        FOR(i, 1, n) {
            ans[i] = ans[i - 1] + diff[i];
            cout << ans[i] << ' ';
        }
    }
}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub2::check()) {Sub2::solve(); return;}
    if(Sub3::check()) {Sub3::solve(); return;}
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