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
const ll N = 3e4;
ll n, q, a[N + 1];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    cin >> q;
    for(ll i = 1; i <= q
        ; i ++) {
        set<ll> k;
        ll l, r; cin >> l >> r;
        for(ll j = l; j <= r; j ++) {
            k.insert(a[j]);
        }
        cout << k.size() << el;
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