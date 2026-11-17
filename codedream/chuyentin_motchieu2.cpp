#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i, a, b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, b, a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 2e5;
ll n, k, q, diff[N + 1], prefix[N + 1];

void read() {
    cin >> n >> k >> q;

    FOR(i, 1, n) {
        ll x, y; cin >> x >> y;
        diff[x] ++;
        diff[y + 1] --;
    }

    ll cnt = 0, cur = 0;
    
    FOR(i, 1, N) {
        cur += diff[i];
        prefix[i] = prefix[i - 1] + (cur >= k);
    }

    FOR(i, 1, q) {
        ll x, y; cin >> x >> y;

        cout << prefix[y] - prefix[x - 1] << el;
    }
}

void solve() {

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