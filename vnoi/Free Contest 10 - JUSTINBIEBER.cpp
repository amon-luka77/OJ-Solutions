#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (ll i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 20;

bool vs[N + 1];
ll a[N + 1], b[N + 1];

ll n, ans = 1e18;

void backtrack (ll pos, ll sum) {
    if(pos > n) {
        ans = min(ans, sum); 
        return;
    }

    FOR(i, 1, n) {
        if(!vs[i]) {
            vs[i] = 1;
            backtrack(pos + 1, sum + abs(pos - i) + abs(a[pos] - b[i]));
            vs[i] = 0;
        }
    }
}

void read() {
    while(cin >> n) {
        if(n == 0) break;
        memset(vs, false, sizeof(vs));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));

        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];

        ans = 1e18;

        backtrack(1, 0);

        cout << ans << el;
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