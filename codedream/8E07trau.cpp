#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define el "\n"
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BI(x, i) (((x) >> (i)) & 1)
#define NAME "8E07"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".ans", "w", stdout);
    }
}

const ll N = 1e5;
ll n, q, sumT = 0;
ll query[N + 1];
vector<vector<ll>> a;

void read() {
    cin >> n >> q; vector<ll> b;
    FOR(i, 1, n) {
        ll k; cin >> k; sumT += k;
        FOR(i, 1, k) {ll x; cin >> x; b.pb(x);}
        sort(all(b), greater<ll>()); a.pb(b); b.clear();
    }
    FOR(i, 1, q) cin >> query[i];
}


void solveQ(ll AMON) {
    ll x = query[AMON];
    ll maxCnt = 0, ans = 0;

    FOR(i, 0, a.size() - 1) {
        auto &b = a[i];
        ll l = 0, r = b.size() - 1, res = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(b[mid] >= x) {
                l = mid + 1; res = mid + 1;
            } else r = mid - 1;
        }
        if(maxCnt <= res) {ans = i + 1; maxCnt = res;}
    } cout << ans << el; cerr << ans << el;
}

void solve() {
    FOR(i, 1, q) solveQ(i);
}

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
