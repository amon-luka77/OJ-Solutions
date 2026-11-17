#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define el "\n"
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "8E06"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 2e5;
ll n, m, q;
pair<ll, ll> a[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i].ft >> a[i].sc;
}

void solve() {
    cin >> q;
    FOR(i, 1, q) {
        ll x; cin >> x;
        ll res = 0;
        FOR(i, 1, n) {
            ll dis = x - a[i].sc; if(dis < 0) {dis += m;} dis ++;
            res += (a[i].ft - dis) / m + (a[i].ft >= dis);
        } cout << res << el;
        if(i == q) cerr << res << el;
    }
}

// 3 4 5 6 7 0

void write() {

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    file();
    read();
    solve();
    write();
    return 0;
}

