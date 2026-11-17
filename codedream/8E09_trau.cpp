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
#define NAME "8E09"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 100;
ll n, a[N + 1];
ll res = 1e18;

void read() {
    cin >> n; res = n - 1;
    FOR(i, 1, n - 1) cin >> a[i];
}

void backtrack(ll pos, ll cnt, ll val) {
    if(pos + cnt >= n) {return res = min(res, val), void();}

    FOR(i, 1, cnt) backtrack(pos + i, cnt, val + 1);
    FOR(i, 1, cnt + 1) backtrack(pos + i, cnt + 1, val + a[pos] + 1);
}

void solve() {
    backtrack(1, 1, 1);
    cout << res; cerr << res << el;
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
