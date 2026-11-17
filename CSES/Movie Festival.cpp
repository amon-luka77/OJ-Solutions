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
ll n;
vector<pair<ll, ll>> a;

void read() {
    cin >> n;
    FOR(i, 1, n) {
        ll x, y; cin >> x >> y;
        a.pb({x, y});
    }

    sort(all(a), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        if(x.sc != y.sc) return x.sc < y.sc;
        return x.ft < y.ft;
    });
}

void solve() {
    ll ans = 1, cur = a[0].sc;
    FOR(i, 1, a.size() - 1) {
        if(cur <= a[i].ft) {
            ans ++; cur = a[i].sc;
        }
    }

    cout << ans;
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