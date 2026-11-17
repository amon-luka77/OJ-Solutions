#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 2e5;
ll n, k, a[N + 1], b[N + 1];

void read() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] %= k;
    }

    ll cnt = 0;

    for(ll i = 1; i <= n; i ++) {
        ll t = b[(k - a[i]) % k];
        cnt += t;
        b[a[i]] ++;
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
1 4 0 0 4 1

*/