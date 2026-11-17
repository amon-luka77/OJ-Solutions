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
const ll N = 5e4;
ll n, q, a[N + 1], mark[N + 1];
ll prefix[10005][10005];
vector<ll> b;
bool sub3 = 1;

void read() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++) {
        cin >> a[i];
        if(mark[a[i]] == 0) b.pb(a[i]);
        mark[a[i]] ++;
    }
}

void solve() {
        bool check[N + 1];

        for(auto i : b) {
            for(ll j = 1; j <= n; j ++) {
                prefix[i][j] = prefix[i][j - 1] + (a[j] == i);
            }
        }

        for(ll j = 1; j <= q; j ++) {
            ll l, r, u, v, cnt = 0; cin >> l >> r >> u >> v;
            memset(check, 0, sizeof(check));
            for(ll i = 1; i <= 50; i ++) {
                cnt += (prefix[i][r] - prefix[i][l - 1]) * (prefix[i][v] - prefix[i][u - 1]);
            }

            cout << cnt << el;
        }
}

void write() {

}

int main() {
    boost;
    file("DAYSO");
    read();
    solve();
    write();
    return 0;
}