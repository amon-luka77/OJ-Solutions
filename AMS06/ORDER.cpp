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
#define NAME "ORDER"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 100;
ll n;
struct ORDER {
    ll t, d, p, id;
};
vector<ORDER> order;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y, z; cin >> x >> y >> z; order.pb({x, y, z, i});
    }
    sort(all(order), [](const ORDER &x, const ORDER &y) {
        return x.d < y.d;
    });
}

namespace Sub1 {
    bool check() {
        return n <= 20;
    }

    bool check(ll mask) {
        if(__builtin_popcountll(mask) <= 1) return 1;
        vector<ll> c;
        for(ll tmp = mask; tmp > 0; tmp ^= tmp & -tmp) {
            ll pos = __lg(tmp & -tmp);
            c.pb(pos);
        }

        ll curTime = 0;

        FOR(i, 0, c.size() - 1) {
            auto [t, d, p, id] = order[c[i]];
            if(curTime + t >= d) return 0;
            curTime += t;
        }

        // for(auto i : c) cerr << order[i].id << ' ';
        // cerr << el;

        return 1;
    }

    ll dp[MASK(20) + 1], checkMask[MASK(20) + 1];

    void solve() {
        dp[0] = 0;
        vector<ll> b;
        FOR(mask, 0, MASK(n) - 1) if(check(mask)) {b.pb(mask); checkMask[mask] = 1;}
        for(auto mask : b) FOR(i, 0, n - 1) if(!BIT(mask, i) && checkMask[mask | MASK(i)]) {
            ll nextMask = mask | MASK(i);
            dp[nextMask] = max(dp[nextMask], dp[mask] + order[i].p);
        }

        ll ans = 0;
        for(auto mask : b) if(dp[ans] < dp[mask]) ans = mask;
        cout << dp[ans] << el;
        cout << __builtin_popcountll(ans) << el;
        vector<ll> trace;
        for(ll tmp = ans; tmp > 0; tmp ^= tmp & -tmp) {
            ll pos = __lg(tmp & -tmp);
            trace.pb(order[pos].id);
        }
        for(auto i : trace) cout << i << ' ';
    }
}

namespace Sub2 {
    bool check() {
        return 1;
    }

    const ll maxTime = 2000;
    struct TRACE {
        ll x, y, z;
    }; 

    ORDER newOrder[N + 1];
    TRACE trace[N + 1][maxTime + 1];
    ll dp[N + 1][maxTime + 1];

    void solve() {
        FOR(i, 0, n - 1) newOrder[i + 1] = order[i];
        FOR(i, 1, n) FOR(j, 1, maxTime) dp[i][j] = -1e18;

        FOR(i, 1, n) FOR(j, 1, maxTime) {
            auto [t, d, p, id] = newOrder[i];
            if(j >= d || j < t) continue;
            dp[i][j] = dp[i][j - 1]; 
            FOR(k, 0, i - 1)  {
                if(dp[i][j] < dp[k][j - t] + p) {
                    dp[i][j] = dp[k][j - t] + p;
                    trace[i][j] = {k, j - t, id};
                }
            }
        }

        ll pos = 0, curTime = 0;
        FOR(i, 1, n) FOR(j, 1, maxTime) if(dp[pos][curTime] < dp[i][j]) {
            pos = i; curTime = j;
        }

        // cout << pos << ' ' << curTime << el;

        vector<ll> ans;
        cout << dp[pos][curTime] << el;

        while(1) {
            // cout << pos << ' ' << curTime << el;
            auto [x, y, id] = trace[pos][curTime];
            if(id == 0) break;
            ans.pb(id);
            pos = x, curTime = y;
        }
        
        cout << ans.size() << el;
        FORD(i, ans.size() - 1, 0) cout << ans[i] << ' ';
    }
}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    if(Sub2::check()) {Sub2::solve(); return;}

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