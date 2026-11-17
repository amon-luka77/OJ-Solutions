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
const ll N = 1e6;
ll n, m, parent[N + 1];
void read() {
    cin >> n >> m;
}

void make_set() {
    for(ll i = 1; i <= n; i ++) {
        parent[i] = i;
    }
}

ll find_set(ll k) {
    if(k == parent[k]) return k;
    return parent[k] = find_set(parent[k]);
}

void union_set(ll u, ll v) {
    ll x = find_set(u);
    ll y = find_set(v);

    parent[x] = y;
}

void solve() {
    make_set();

    for(ll i = 1; i <= m; i ++) {
        char x; ll y; cin >> x >> y;

        if(x == '-') {
            union_set(y, y + 1);
        } else {
            ll t = find_set(y);
            if(t <= n && t >= 1) cout << t << el;
            else cout << -1 << el;
        }

    }
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