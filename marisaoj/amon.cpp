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

const ll N = 0;
ll n;
ll mod = 2021;

void read() {
    cin >> n;
}

void solve() {
    ll tmp1 = n;
    ll tmp2 = n + 1;
    ll tmp3 = 2 * n + 1;

    vector<ll> a; a.pb(tmp1); a.pb(tmp2); a.pb(tmp3);
    FOR(i, 0, 2) if(a[i] % 2 == 0) {a[i] /= 2; break;}
    FOR(i, 0, 2) if(a[i] % 3 == 0) {a[i] /= 3; break;}
    FOR(i, 0, 2) a[i] %= mod;
    ll res = 1;
    for(auto i : a) res = (res * i) % mod;
    cout << res;
}

void write() {

}

int main() {
    boost;
    // file();
    read();
    solve();
    write();
    return 0;
}
