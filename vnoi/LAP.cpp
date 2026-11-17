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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

namespace Sub1 {
    bool check() {
        return (n <= 2000);
    }

    void solve() {
        ll cnt = 0;
        vector<ll> b;
        FOR(i, 1, n) b.pb(a[i]);

        while(!b.empty()) {
            ll maxPos = 0, minPos = 0;
            vector<ll> c = b; b.clear();
            FOR(i, 1, c.size() - 1) {
                if(c[maxPos] < c[i]) maxPos = i;
                if(c[minPos] > c[i]) minPos = i;
            }

            if(minPos > maxPos) swap(minPos, maxPos);

            FOR(i, 0, c.size() - 1) if(!(i >= minPos && i <= maxPos)) {
                b.pb(c[i]);
            }

            cnt ++;
        }

        cout << cnt;
    }
}

namespace Sub3 {
    void solve() {
        priority_queue<pair<ll, ll>> maxA;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> minA;
        set<ll> pos;
        FOR(i, 1, n) {
            pos.insert(a[i]);
            maxA.push({a[i], i});
            minA.push({a[i], i});
        }

        ll cnt = 0;
        while(1) {
            while(!maxA.empty() && pos.find(maxA.top().sc) == pos.end()) maxA.pop();
            while(!minA.empty() && pos.find(minA.top().sc) == pos.end()) minA.pop();

            if(maxA.empty() || minA.empty()) break;
            cnt ++;
            ll L = maxA.top().sc;
            ll R = minA.top().sc;
            if(L > R) swap(L, R);

            while(!pos.empty()) {
                auto it = pos.lower_bound(L);
                if(it == pos.end() || *it > R) break;
                pos.erase(it);
            }
        }

        cout << cnt;
    }
}

void solve() {
    if(Sub1::check()) {Sub1::solve(); return;}
    Sub3::solve();
}

void write() {

}

int main() {
    boost;
    file("LAB");
    read();
    solve();
    write();
    return 0;
}