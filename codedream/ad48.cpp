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

const ll N = 5e5, base = 400;
ll n, m, h[N + 1][3][3], mul[N + 1][3], mode[3], a[N + 1][3];

void read() {
    cin >> n >> m;
    mode[1] = 1e9 + 7;
    mode[2] = 998244353;

    FOR(i, 1, n) cin >> a[i][1];
    FOR(i, 1, m) cin >> a[i][2];
    FOR(i, 1, 2) mul[0][i] = 1;

    FOR(i, 1, max(n, m)) FOR(j, 1, 2) {
        mul[i][j] = (mul[i - 1][j] * base) % mode[j];
    }

    FOR(i, 1, n) FOR(j, 1, 2) {
        h[i][j][1] = (h[i - 1][j][1] * base + a[i][1]) % mode[j];
    }

    FOR(i, 1, m) FOR(j, 1, 2) {
        h[i][j][2] = (h[i - 1][j][2] * base + a[i][2]) % mode[j];
    }
}   

ll getHash(ll l, ll r, ll t, ll m) {
    return (h[r][m][t] - h[l - 1][m][t] * mul[r - l + 1][m] % mode[m] + mode[m]) % mode[m];
}


bool check(ll l, ll r, ll curL, ll curR) {
    if(getHash(l, r, 2, 1) == getHash(curL, curR, 1, 1) && 
        getHash(l, r, 2, 2) == getHash(curL, curR, 1, 2)) {
            return 1;
    }

    return 0;
}

void solve() {
    FOR(i, 1, m - n + 1) {
        if(check(i + 1, i + n - 1, 2, n)) {
            cout << i; exit(0);
        }

        if(a[1][1] == a[i][2]) {
            ll l = 1, r = n, pos = 0;
            
            while(l <= r) {
                ll mid = (l + r) >> 1;

                if(check(i, i + mid - 1, 1, mid)) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            
            if(check(i + pos + 1, i + n - 1, pos + 2, n)) {
                cout << i; exit(0);
            }
        }
    }

    cout << -1;
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