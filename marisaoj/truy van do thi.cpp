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

const ll N = 1e5, LOG = 30;
ll n, q, a[N + 1], minA[N + 1][LOG + 1];

void read() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
}

void getQuery(ll u, ll k) {
    FOR(i, 0, LOG) if((k >> i) & 1) u = minA[u][i];
    
    cout << u << el;
}

void solve() {
    FOR(i, 1, n) minA[i][0] = a[i];
    FOR(j, 1, LOG) FOR(i, 1, n) {
        minA[i][j] = minA[minA[i][j - 1]][j - 1];
    }

    while(q --) {
        ll x, y; cin >> x >> y;
        getQuery(x, y);
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