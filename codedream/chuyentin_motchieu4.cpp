#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(root) (root).begin(),(root).end()
using namespace std;
const ll N = 0;
ll t;

void read() {
    cin >> t;
}

void solve() {
    while(t --) {
        ll n, root, m;
        cin >> n >> root >> m;

        vector<ll> diff(n + 5, 0);

        FOR(i, 1, m) {
            ll x, y; cin >> x >> y;
            diff[x] ++;
            diff[y + 1] --;
        }

        ll start_node = 1, sum = 0;
        bool ok = 1;

        FOR(i, 1, n) {
            sum += diff[i];

            if(sum == 0) {
                if(root >= start_node && root < i) {
                    cout << min(2 * m, i - start_node) << el;
                    ok = 0;
                    break;
                }

                start_node = -77;
            }

            if(start_node == -77 && sum > 0) {
                start_node = i;
            }
        }

        if(ok && sum > 0 && root >= start_node && root <= n) {
                cout << min(2 * m, n - start_node + 1) << el;
        } else {
            cout << 1 << el;
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