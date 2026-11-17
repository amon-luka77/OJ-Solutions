#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e5;
ll n, k, q, diff[N + 1], diffSum[N + 1], diffMi[N + 1], a[N + 1];

void read() {
    cin >> n >> k >> q;
    for(ll i = 1; i <= n; i ++) {
        ll x; cin >> x;

        diff[1] += max(k - abs(1 - i), 1LL) * x;

        diffSum[max(i - k + 1, 1LL)] += x;
        diffSum[i] -= x;
        diffMi[i] += x;
        diffMi[min(i + k - 1, n)] -= x;

    }

    ll x = 0, y = 0;

    for(ll i = 1; i <= n; i ++) {
        a[i] = a[i - 1] + diff[i] + x - y;

        x += diffSum[i];
        y += diffMi[i];

    }

    for(ll i = 1; i <= q; i ++) {
        ll x; cin >> x;

        cout << a[x] << el;
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