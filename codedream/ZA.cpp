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

const ll N = 2e3;
ll n, ans = 0, a[N + 1][N + 1];
bool vs[N + 1][N + 1];

void backtrack(ll pos, ll sum) {
    if(pos > n) {
        ans = max(ans, sum);
        return;
    }

    FOR(i, pos, n) {
        FOR(j, 1, pos) {
            if(!vs[i][j]) {
                backtrack(pos + 1, sum + a[i][j]);
            }
        }
    }
}

void read() {
    cin >> n;
    FOR(i, 1, n) {
        FOR(j, 1, i) {
            cin >> a[i][j];
        }
    }
}

void solve() {
    if(n <= 5) {
        backtrack(1, 0);
        cout << ans;
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