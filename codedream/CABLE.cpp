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

const ll N = 2e5;
ll n, a[N + 1];

map<ll, ll> hashing;

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
}

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rd);
}

ll prefix[N + 1];

void solve() {
    FOR(i, 1, n) {
        if(hashing.find(a[i]) == hashing.end()) {
            hashing[a[i]] = Rand(1, (ll)1e18);
        } a[i] = hashing[a[i]];
    }

    map<ll, ll> cnt;
    ll res = 0; cnt[0] ++;
    FOR(i, 1, n) {
        prefix[i] = prefix[i - 1] ^ a[i];
        res += cnt[prefix[i]];
        cnt[prefix[i]] ++;
    } cout << res;
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
