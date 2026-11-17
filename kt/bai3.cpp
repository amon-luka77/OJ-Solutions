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
ll n, m, a[N + 1];

void read() {
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++) {
        cin >> a[i];
    }

    for(ll i = 1; i <= n; i ++) {
        ll l = 1, r = m, ans = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(a[mid] >= i) {
                ans = a[mid];
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        cout << ans - i << el;
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