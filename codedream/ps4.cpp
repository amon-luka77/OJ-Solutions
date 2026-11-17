#include<bits/stdc++.h>
#define int long long 
#define ll long long 
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i --)

using namespace std;

pair<int, int> a[4], base[4];

#define ft first
#define sc second

int mod, n, k;

ll power(ll a, ll b) {
    ll res = 0;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    } return res;
}

struct Matrix {
    ll n, m;
    ll d[4 + 1][4 + 1];

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
        Matrix res(x, z);z

        FOR(i, 1, x) FOR(j, 1, y) FOR(k, 1, z) {
            res.d[i][k] = (res.d[i][k] + power(d[i][j], a.d[j][k])) % mod;
        }  

        return res;
    }

    Matrix operator ^ (ll k) const {
        Matrix res(n, n);

        FOR(i, 1, n) res.d[i][i] = 1;
        Matrix mul = *this;

        while(k > 0) {
            if(k % 2) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }

        return res;
    }
};


Matrix L(5, 5), R(5, 5), A(5, 5);

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> mod;

    L.d[1][1] = 1, L.d[1][2] = 0;
    L.d[2][1] = 1, L.d[2][2] = 1;

    R.d[1][1] = 1, R.d[1][2] = 1;
    R.d[2][1] = 0, R.d[2][2] = 1;
    
    FOR(i, 1, n) {
        char x; cin >> x;

        if(i == 1) A = (x == 'L' ? L : R);
        else A = A * (x == 'L' ? L : R);
    }

    A = A ^ k;

    int x = 0, y = 0;

    FOR(i, 1, 2) {
        x = (x + A.d[1][i]) % mod;
        y = (y + A.d[2][i]) % mod;
    }

    cout << x << ' ' << y;
}
