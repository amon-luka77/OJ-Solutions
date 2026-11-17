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

const ll N = 2e5, LOG = 33;
ll n, q, par[N + 1][LOG + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) {
        ll x; cin >> x;
        par[i][0] = x;
    }
}

ll getQuery(ll u, ll k) {
    FORD(i, LOG, 0) if(BIT(k, i)) u = par[u][i];
    return u;
}

void solve() {
    FOR(j, 1, LOG) FOR(i, 1, n) par[i][j] = par[par[i][j - 1]][j - 1];

    FOR(i, 1, q) {
        ll x, k; cin >> x >> k;
        cout << getQuery(x, k) << el;
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