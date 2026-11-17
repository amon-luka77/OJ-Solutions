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
ll n, q, a[N + 1];
void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
    }
}
void solve() {
    SegmentTree node(n);

    for(ll i = 1; i <= q; i ++) {
        ll l, r; cin >> l >> r;

        query.pb({l, r, i});
    }

    sort(all(query), cmp);

    for(ll i = 0; i < query.size(); i ++) {
        if(i == 0) {
            for(ll j = 1; j <= query[i].se; j ++) {
                if(pos[a[j]] == 0
                ])
            }
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