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
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 2e5;
ll n, m, q;
pair<ll, ll> a[N + 1];
pair<ll, ll> query[N + 1];
map<ll, ll> diff;
ll ans[N + 1];

void read() {
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i].ft >> a[i].sc;
    cin >> q;
    FOR(i, 1, q) {cin >> query[i].ft; query[i].sc = i;}
    sort(query + 1, query + q + 1);
}

void solve() {
    ll AMON = 0;

    FOR(i, 1, n) {
        AMON += a[i].ft / m;
        a[i].ft -= m * (a[i].ft / m);
        if(a[i].ft >= 1) {
            diff[a[i].sc] ++;
            if(a[i].sc + a[i].ft <= m) diff[a[i].sc + a[i].ft] --;
            else {
                diff[m] --;
                diff[0] ++;
                diff[(a[i].sc + a[i].ft) % m] --;
            }
        }
    }

    ll pos = 1;
    for(auto &[i, j] : diff) {
        while(query[pos].ft < i) {
            ans[query[pos].sc] = AMON;
            pos ++; if(pos > q) break;
        } AMON += j;
//        cerr << AMON << el;
    }

    FOR(i, pos, q) ans[i] = AMON;

    FOR(i, 1, q) cout << ans[i] << el;
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
