#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define NAME "GCDFACT"

using namespace std;

const ll N = 1e5;
ll n, a[N + 1];

void read() {
    ll t; cin >> t;
    while(t --) {
        cin >> n;
        ll d = 0;
        FOR(i, 1, n) {
            cin >> a[i];
            d = (i == 1 ? a[i] : __gcd(a[i], d));
        }

        sort(a + 1, a + n + 1);

        ll x = 1;
        FOR(i, 1, a[1]) {
            if(x > d) break;
            x *= i;
        } cout << (x == d ? "YES\n" : "NO\n");
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if(fopen(NAME ".inp", "r")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
    read();
}
