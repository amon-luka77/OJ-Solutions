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
}



void solve() {
    FOR(i, 1, n) FOR(j, 1, n) {
        newAB[i][j] = sum(i, j);
    }

    FOR(i, 1, n) FOR(j, 1, n) {
        prefixAB[i][j] = prefixAB[i - 1][j] + prefixAB[i][j - 1] - prefixAB[i - 1][j - 1] + newAB[i][j];
    }

    FOR(i, 1, n) FOR(j, i, n) {
        vector<ll> newB(n + 1, 0);
        ll amon = 0;

        FOR(k, 1, n) {
            newB[k] = prefixAB[j][k] - prefixAB[j][k - 1] - prefixAB[i - 1][k] + prefixAB[i - 1][k - 1];

            amon = max(amon + newB[k], newB[k]);
            ans = max(ans, amon);
        }
    }

    cout << ans;
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