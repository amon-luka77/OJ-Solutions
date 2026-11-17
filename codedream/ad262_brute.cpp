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
const ll N = 1e5;
ll n, m, a[N + 1];

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= m; i ++) {
        ll l, r, x; cin >> l >> r >> x;
        ll cnt = 0;

        for(ll j = l; j <= r; j ++) {
            cnt += (a[j] == x);
        }

        cout << cnt << el;
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