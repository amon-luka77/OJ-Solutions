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
const ll N = 400;
ll n, ans = 0, cur = 0, a[N + 1], b[N + 1];
ll newAB[N + 1][N + 1], prefixAB[N + 1][N + 1];
ll prefixA[N + 1], prefixB[N + 1];

ll sum(ll i, ll j) {
    if(i <= j) return prefixA[j] - prefixA[i - 1];
    else return prefixB[i] - prefixB[j - 1];
}

void read() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i];
        prefixA[i] = prefixA[i - 1] + a[i];
    }
    FOR(i, 1, n) {
        cin >> b[i];
        prefixB[i] = prefixB[i - 1] + b[i];
    } 
    
    FOR(x, 1, n) FOR(y, x + 1, n) FOR(c, 1, n) FOR(d, c + 1, n) {
        cur = 0;
        FOR(i, x, y) FOR(j, c, d) {
            cur += sum(i, j);
        }
        ans = max(ans, cur);
    } 
    cout << ans;

    exit(0);
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