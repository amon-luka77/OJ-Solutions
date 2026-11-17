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
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 3e5;
ll n;
pair<ll, ll> a[N + 1];

void read() {
    cin >> n; if(n == 1) {cout << 0; exit(0);}
    FOR(i, 1, n) cin >> a[i].ft;
    FOR(i, 1, n) cin >> a[i].sc;
}

ll getDis(ll i, ll j) {
    return abs(a[i].ft - a[j].ft) + abs(a[i].sc - a[j].sc);
}

namespace Sub1 {
    bool check() {return n <= 20;}

    void solve() {
        ll res = 1e18, k; vector<ll> a, b;
        FOR(mask, 1, MASK(n) - 1) if(__builtin_popcountll(mask) < n &&__builtin_popcountll(mask) > 0) {
            a.clear(); b.clear();
            FOR(i, 0, n - 1) {  
                if(BIT(mask, i)) a.pb(i + 1);
                else b.pb(i + 1);
            }

        ll maxDis = 0;
            for(auto i : a) for(auto j : a) maxDis = max(maxDis, getDis(i, j));
            for(auto i : b) for(auto j : b) maxDis = max(maxDis, getDis(i, j));
            res = min(res, maxDis);
        } cout << res;
    }
}

void solve() {
    if(Sub1::check()) return Sub1::solve(), void();
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