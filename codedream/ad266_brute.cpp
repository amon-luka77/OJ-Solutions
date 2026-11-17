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
ll n, q, a[N + 1];

void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;
        unordered_map<ll, ll> b;
        ll cnt = 0;
        for(ll j = l; j <= r; j ++) {
            b[a[j]] ++;
            cnt += (b[a[j]] == 2);
            cnt -= (b[a[j]] == 3);
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