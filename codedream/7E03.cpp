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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 2e5;
ll n;

struct A {
    ll x, y, z, t;
};

vector<A> a;

namespace Sub1 {
    bool check() {
        if(n > 200) return 0;
        for(auto [x, y, z, t] : a) if(x > 200 || y > 200 || z > 200 || t > 200) return 0;
        return 1;
    }

    void solve() {
        pair<ll, ll> ansPair = {1e18, 1e18};

        FOR(i, 0, 200) FOR(j, 0, 200) {
            ll cnt = 0;
            for(auto [x, y, z, t] : a) {
                if(x <= i && i <= y && z <= j && j <= t) cnt ++;
            }

            if(cnt >= n) {
                ansPair = min(ansPair, {i, j});          
            }

        }

        if(ansPair.ft == 1e18 || ansPair.sc == 1e18) cout << -1;
        else cout << ansPair.ft << ' ' << ansPair.sc;
    }
}

namespace Sub2 {
    bool check() {
        return (n <= 2000);
    }

    A giao(A pos1, A pos2) {
        return {max(pos1.x, pos2.x), min(pos1.y, pos2.y), max(pos1.z, pos2.z), min(pos1.t, pos2.t)};
    }

    void solve() {
        pair<ll, ll> ans = {1e18, 1e18};

        FOR(i, 0, n) {
            ll cnt = 0;
            A pre = {0, 0, 0, 0};

            FOR(j, 0, n) if(i != j) {
                cnt ++;
                if(cnt == 1) pre = a[j];
                else pre = giao(pre, a[j]);
                if(pre.x > pre.y || pre.z > pre.t) break;
            }

            if(cnt >= n) {
                if(ans.ft + ans.sc > pre.x + pre.z) ans = {pre.x, pre.z};
                else if(ans.ft + ans.sc == pre.x + pre.z) ans = min(ans, {pre.x, pre.z});
            }
        }

        if(ans.ft == 1e18 || ans.sc == 1e18) cout << -1;
        else cout << ans.ft << ' ' << ans.sc;
    }
}

namespace Sub3 {
    A prefix[N + 1], suffix[N + 1];

    bool check() {
        return 1;
    }

    A giao(A pos1, A pos2) {
        return {max(pos1.x, pos2.x), min(pos1.y, pos2.y), max(pos1.z, pos2.z), min(pos1.t, pos2.t)};
    }

    bool check(A pre) {
        if(pre.x > pre.y || pre.z > pre.t) return 0;
        return 1;
    }

    void solve() {
        prefix[0] = a[0]; suffix[n] = a[n];
        FOR(i, 1, n)  prefix[i] = giao(prefix[i - 1], a[i]);
        FORD(i, n - 1, 0) suffix[i] = giao(suffix[i + 1], a[i]);

        pair<ll, ll> ans = {1e18, 1e18};
        if(check(prefix[n - 1])) ans = {prefix[n - 1].x, prefix[n - 1].z};
        if(check(suffix[1])) {
            if(ans.ft == 1e18) ans = {suffix[1].x, suffix[1].z};
            else {
                if(ans.ft + ans.sc > suffix[1].x + suffix[1].z) ans = {suffix[1].x, suffix[1].z};
                else if(ans.ft + ans.sc == suffix[1].x + suffix[1].z) ans = min(ans, {suffix[1].x, suffix[1].z});
            }
        }

        FOR(i, 1, n - 1) {
            A pre = giao(prefix[i - 1], suffix[i + 1]);
            if(check(pre)) {
                if(ans.ft + ans.sc > pre.x + pre.z) ans = {pre.x, pre.z};
                else if(ans.ft + ans.sc == pre.x + pre.z) ans = min(ans, {pre.x, pre.z});
            }
        }

        if(ans.ft == 1e18 || ans.sc == 1e18) cout << -1;
        else cout << ans.ft << ' ' << ans.sc;
    }
}

void read() {
    cin >> n;
    FOR(i, 1, n + 1) {
        ll x, y, z, t; cin >> x >> y >> z >> t;
        a.pb({x, z, t, y});
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
    //file();
    read();
    solve();
    write();
    return 0;
}