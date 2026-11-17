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

const ll N = 1e5, base = 77, mod1 = 1e9, mod2 = 998244353;
string s1, s2, s3; 

ll sz = 0;
ll mode[3], h[5][5][N + 1], mul[5][5][N + 1];
string a[5];

void read() {
    cin >> s1 >> s2 >> s3;
    sz = s1.size() + s2.size() + s3.size();
    s1 = ' ' + s1; s2 = ' ' + s2; s3 = ' ' + s3;
    mode[1] = mod1;
    mode[2] = mod2;
    a[1] = s1, a[2] = s2, a[3] = s3;

    FOR(i, 1, 2) FOR(j, 1, 3) {
        mul[i][j][0] = 1;
    }

    FOR(i, 1, s1.size() - 1) {
        h[1][1][i] = (h[1][1][i - 1] * base + (s1[i] - 'a' + 1)) % mod1;
        mul[1][1][i] = (mul[1][1][i - 1] * base) % mod1;
        h[2][1][i] = (h[2][1][i - 1] * base + (s1[i] - 'a' + 1)) % mod2;
        mul[2][1][i] = (mul[2][1][i - 1] * base) % mod2;
    }

    FOR(i, 1, s2.size() - 1) {
        h[1][2][i] = (h[1][2][i - 1] * base + (s2[i] - 'a' + 1)) % mod1;
        mul[1][2][i] = (mul[1][2][i - 1] * base) % mod1;
        h[2][2][i] = (h[2][2][i - 1] * base + (s2[i] - 'a' + 1)) % mod2;
        mul[2][2][i] = (mul[2][2][i - 1] * base) % mod2;
    }
        
    FOR(i, 1, s3.size() - 1) {
        h[1][3][i] = (h[1][3][i - 1] * base + (s3[i] - 'a' + 1)) % mod1;
        mul[1][3][i] = (mul[1][3][i - 1] * base) % mod1;
        h[2][3][i] = (h[2][3][i - 1] * base + (s3[i] - 'a' + 1)) % mod2;
        mul[2][3][i] = (mul[2][3][i - 1] * base) % mod2;
    }
}

ll getHash(ll l, ll r, ll t, ll m) {
    return (h[m][t][r] - h[m][t][l - 1] * mul[m][t][r - l + 1] % mode[m] + mode[m]) % mode[m];
}

ll minSize(ll x, ll y, ll z) {
    ll minXY = min(a[x].size(), a[y].size());
    ll minYZ = min(a[y].size(), a[z].size());

    ll ans1 = 0, ans2 = 0;

    FOR(i, 1, minXY - 1) {
        if(getHash(a[x].size() - i, a[x].size() - 1, x, 1) == getHash(1, i, y, 1) && 
            getHash(a[x].size() - i, a[x].size() - 1, x, 2) == getHash(1, i, y, 2)) {
                ans1 = i;
        }
    }

    FOR(i, 1, minYZ - 1) {
        if(getHash(a[y].size() - i, a[y].size() - 1, y, 1) == getHash(0, i, z, 1) && 
            getHash(a[y].size() - i, a[y].size() - 1, y, 2) == getHash(0, i, z, 2)) {
                ans2 = i;
        }
    }

    return sz - ans1 - ans2;
}

void solve() {
    cout << min({minSize(1, 2, 3), minSize(1, 3, 2),
                minSize(2, 1, 3), minSize(2, 3, 1),
                minSize(3, 1, 2), minSize(3, 2, 1)}) << el;

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