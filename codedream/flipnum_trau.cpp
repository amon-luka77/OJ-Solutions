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
#define NAME "flipnum"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 0;
ll n;

void read() {
    cin >> n;
    ll res = 1e18;
    FOR(i, n + 1, (ll)1e7) {
        string s = to_string(i);
        reverse(all(s));
        ll num = stoll(s);
        string t = to_string(num);
        reverse(all(t));
        ll kk = stoll(t);
        if(kk > n) res = min(res, num);
    } cout << res; cerr << res << el;
}

void solve() {

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
