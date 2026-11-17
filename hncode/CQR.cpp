#include <bits/stdc++.h>
#define ll int
#define ft first
#define sc second
#define el '\n'
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 2e5;
ll n, q, a[N + 1];

set<ll> value[51];

void read() {
    cin >> n;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        value[a[i]].insert(i);
    }
}
void solve() {
    cin >> q;
    while(q --) {
        ll l, r, x, y; cin >> l >> r >> x >> y;
        auto it = value[x].lower_bound(l);
        while(it != value[x].end() && *it <= r) {
            ll t = *it;
            it = value[x].erase(it);
            value[y].insert(t);
            a[t] = y;
        }
    }
}
void write() {
    for(ll i = 1; i <= n; i ++) {
        cout << a[i] << ' ';
    }
}
int main() {
    boost;
    //file();
    read();
    solve();
    write();
    return 0;
}