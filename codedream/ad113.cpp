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

const ll N = 0;
ll n, m, mod;

struct Matrix {
    ll n, m;
    ll d[10][10];

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
            res.d[i][k] += d[i][j] * a.d[j][k];
            if(res.d[i][k] >= mod * mod) res.d[i][k] -= mod * mod;
        }

        FOR(i, 1, x) FOR(j, 1, z) res.d[i][j] %= mod;

        return res;
    }

    Matrix operator ^ (ll k) const {
        Matrix res(n, n), mul = *this;
        FOR(i, 1, n) res.d[i][i] = 1;

        while(k > 0) {
            if(k % 2) res = (res * mul);
            mul = mul * mul;
            k >>= 1;
        }

        return res;
    }
};

Matrix a(2, 4), b(4, 4);

void read() {
    cin >> n >> m;
    mod = m;

    a.d[1][1] = 1; a.d[1][2] = 1, a.d[1][3] = 2;
    b.d[1][1] = 0, b.d[1][2] = 0, b.d[1][3] = 1;
    b.d[2][1] = 1, b.d[2][2] = 0, b.d[2][3] = 1;
    b.d[3][1] = 0, b.d[3][2] = 1, b.d[3][3] = 1;

    Matrix res = a * (b ^ n);

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