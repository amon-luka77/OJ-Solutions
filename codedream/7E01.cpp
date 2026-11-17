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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 2e5 + 5;
ll n, m, k, a[N + 1];

deque<ll> pos[N + 1];
set<ll> b;
set<pair<ll, ll>> c;

void read() {
    cin >> n >> m >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        pos[a[i]].pb(i);
    }
}

void solve() {
    FOR(i, 1, k) {
        if(b.find(a[i]) == b.end()) {
            b.insert(a[i]);
            if(!pos[a[i]].empty()) pos[a[i]].pop_front();
            if(pos[a[i]].empty()) c.insert({1e18, a[i]});
            else c.insert({pos[a[i]].front(), a[i]});
        } else {
            auto it = c.find({pos[a[i]].front(), a[i]});
            if(it != c.end()) c.erase(it);
            if(!pos[a[i]].empty()) pos[a[i]].pop_front();
            if(pos[a[i]].empty()) c.insert({1e18, a[i]});
            else c.insert({pos[a[i]].front(), a[i]});
        }
    }

    ll cnt = 0;
    FOR(i, k + 1, n) {
        if(b.find(a[i]) == b.end()) {
            if(b.size() < k) {
                b.insert(a[i]);
                if(!pos[a[i]].empty()) pos[a[i]].pop_front();
                if(pos[a[i]].empty()) c.insert({1e18, a[i]});
                else c.insert({pos[a[i]].front(), a[i]});
            } else {
                auto it = prev(c.end());
                auto [x, y] = *it; if(it != c.end()) c.erase(it);
                b.erase(y);
                b.insert(a[i]);
                if(!pos[a[i]].empty()) pos[a[i]].pop_front();
                if(pos[a[i]].empty()) c.insert({1e18, a[i]});
                else c.insert({pos[a[i]].front(), a[i]});
                cnt ++;
                // cout << x << ' ' << y << el;
            }
        } else {
            auto it = c.find({pos[a[i]].front(), a[i]});
            if(it != c.end()) c.erase(it);
            if(!pos[a[i]].empty()) pos[a[i]].pop_front();
            if(pos[a[i]].empty()) c.insert({1e18, a[i]});
            else c.insert({pos[a[i]].front(), a[i]});
        }
    }

    cout << cnt;
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