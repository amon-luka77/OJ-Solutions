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

const ll N = 1e6, base = 31;
ll n; 
string s, preS, revS; 

long long h[N + 1][2][2], mul[N + 1][2][2], mode[2];
string a[2];

void read() {
    cin >> s;
    n = s.size();
    preS = s;
    revS = s; reverse(all(revS));
    s = ' ' + s; revS = ' ' + revS;
    mode[0] = 1e9 + 7;
    mode[1] = 998244353;
    a[0] = s; a[1] = revS;

    FOR(i, 0, 1) FOR(j, 0, 1) {
        mul[0][i][j] = 1;
    }

    FOR(k, 1, n) FOR(i, 0, 1) FOR(j, 0, 1) {
        // pos k, xau i, mode j;
        h[k][i][j] = (h[k - 1][i][j] * base + (a[i][k] - 'A' + 1)) % mode[j];
        mul[k][i][j] = (mul[k - 1][i][j] * base) % mode[j];
    }
}

ll getHash(ll l, ll r, ll t, ll m) {
    return (h[r][t][m] - h[l - 1][t][m] * mul[r - l + 1][t][m] % mode[m] + mode[m]) % mode[m];
}

bool check(ll l, ll r) {
    if(getHash(l, r, 0, 0) == getHash(n - r + 1, n - l + 1, 1, 0) && 
        getHash(l, r, 0, 1) == getHash(n - r + 1, n - l + 1, 1, 1)) {
            return 1;
    } 
    return 0;
}

void solve() {

    FOR(i, 1, n) {
        if(check(i, n)) {
            cout << preS;
            FORD(j, i - 1, 1) cout << s[j];
            exit(0);
        }
    }

    cout << preS << preS;
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
