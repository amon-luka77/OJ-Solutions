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
const ll N = 100;
ll n, m;
char a[N + 1][N + 1];

void read() {
    cin >> n >> m;

    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
    }
}

void solve() {
    ll n1 = 0, n2 = 0;

    FOR(i, 1, n) {
        bool ok = 1;

        FOR(j, 1, m) {
            if(a[i][j] != '.') {
                n2 ++;
                ok = !ok;
            }

            if(a[i][j] == '.' && ok) {
                n1 ++;
            }
        }
    }
    
    cout << n * m - n1 - n2 / 2;
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