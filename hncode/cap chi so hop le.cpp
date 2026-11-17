#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 1e6;
ll n, a[N + 1], snt[N + 1];
ll ts[N + 1];

void sang() {
    for(ll i = 2; i * i <= N; i ++) {
        if(snt[i] == 0) {
            for(ll j = i * i; j <= N; j += i) {
                snt[j] = i;
            }
        }
    }

    FOR(i, 2, N) {
        if(snt[i] == 0) snt[i] = i;
    }
}

void read() {
    sang();

    cin >> n;

    FOR(i, 1, n) {
        cin >> a[i];
        ts[a[i]] ++;
    }

    ll cnt = 0;
    FOR(i, 1, n) {
        ll x = a[i];

        while(x > 1) {
            ll k = snt[x];

            cnt += ts[a[i] / k];
            while(x > 1 && x % k == 0) {
                x /= k;
            }
        }
    }

    cout << cnt;
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

/*
i, j
ai = k * aj;
ai / k = aj
*/