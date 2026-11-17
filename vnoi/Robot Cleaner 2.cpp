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
const ll N = 0;
ll t;

void read() {
    cin >> t;
    while(t --) {
        ll n, m, a, b;
        cin >> n >> m >> a >> b;
        
        ll dr = 1, dc = 1, ans = 0;
        ll cel = 1, col = 1;
        vector<bool> hang(1e3 + 5, 0), cot(1e3 + 5, 0);
        hang[a] = 1, cot[b] = 1;

        while(1) {
            if(cel == n) break;
            if(col == m) break;
            a += dr, b += dc;
            ans ++;

            cel += (!hang[a]);
            col += (!cot[b]);
            hang[a] = 1; cot[b] = 1;

            if(a == 1 || a == n) dr *= -1;
            if(b == 1 || b == m) dc *= -1;
        }

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