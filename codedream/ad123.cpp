/*
    The Fool that doesn't belong to this era;
    The Mysterious Ruler above the Gray Fog;
    The King of Yellow and Black who wields good luck
*/
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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 20;
ll pw10[N + 1], mod;

struct Matrix {
    ll n, m;
    ll d[N + 1][N + 1];

    Matrix(ll _n, ll _m) {
        n = _n, m = _m;
        memset(d, 0, sizeof d);
    }

    Matrix operator + (const Matrix &a) const {
        Matrix res(n, m);
        FOR(i, 1, n) FOR(j, 1, m) {
            res.d[i][j] = d[i][j] + a.d[i][j];
            if(res.d[i][j] >= mod) res.d[i][j] -= mod;
        }

        return res;
    }

    Matrix operator * (const Matrix &a) const {
        ll x = n, y = m, z = a.m;
        Matrix res(x, z);

        FOR(i, 1, x) FOR(j, 1, y) FOR(k, 1, z) {
            res.d[i][k] = (res.d[i][k] + (__int128_t)d[i][j] * a.d[j][k] % mod) % mod;
        }

        return res;
    }

    Matrix operator ^ (ll k) const {
        Matrix res(n, n), mul = *this;
        FOR(i, 1, n) res.d[i][i] = 1;
        
        while(k > 0) {
            if(k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }

        return res;
    }
};

void read() {
    ll x, n, m; cin >> x >> n >> m; mod = m;
    string s = to_string(x); ll numSize = s.size(); s = ' ' + s;

    pw10[0] = 1;
    FOR(i, 1, numSize) pw10[i] = pw10[i - 1] * 10;

    Matrix a(2, numSize + 2), b(numSize + 2, numSize + 2);

    a.d[1][1] = x % m;
    FOR(i, 2, numSize + 1) a.d[1][i] = 1;

    b.d[1][1] = pw10[numSize];
    FOR(i, 1, numSize) {
        b.d[i + 1][1] = (s[i] - '0') * pw10[numSize - i];
    }

    FOR(i, 2, numSize + 1) b.d[2][i] = 1;

    // FOR(i, 1, numSize + 1) FOR(j, 1, numSize + 1) cout << b.d[i][j] << " \n"[j == numSize + 1];

    Matrix res = a * (b ^ (n - 1));
    cout << res.d[1][1];
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