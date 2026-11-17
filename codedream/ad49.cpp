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

const ll N = 1e6, base = 256;
ll n, m, q, h[N + 1][3][3], mul[N + 1][3], mode[3];
string a1, b1;
string a[3]; 

void read() {
    cin >> n >> m;
    cin >> a1 >> b1;
    a1 = ' ' + a1;
    b1 = ' ' + b1;
}

void prepare() {
    FOR(i, 1, 2) mul[0][i] = 1;
    a[1] = a1; a[2] = b1;
    mode[1] = 1e9 + 7; mode[2] = 998244353;

    FOR(i, 1, max(n, m)) FOR(j, 1, 2) {
        mul[i][j] = (mul[i - 1][j] * base) % mode[j];
    }

    FOR(i, 1, n) FOR(j, 1, 2) {
        h[i][1][j] = (h[i - 1][1][j] * base + a[1][i]) % mode[j];
    }

    FOR(i, 1, m) FOR(j, 1, 2) {
        h[i][2][j] = (h[i - 1][2][j] * base + a[2][i]) % mode[j];
    }
}

ll getHash(ll l, ll r, ll t, ll m) {
    return (h[r][t][m] - h[l - 1][t][m] * mul[r - l + 1][m] % mode[m] + mode[m]) % mode[m];
}

bool check(ll l, ll r, ll curL, ll curR) {
    if(getHash(l, r, 1, 1) == getHash(curL, curR, 2, 1) && 
        getHash(l, r, 1, 2) == getHash(curL, curR, 2, 2)) {
            return 1;
    }

    return 0;
}

void solve() {
    prepare();

    cin >> q;
    FOR(i, 1, q) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if(r1 - l1 == r2 - l2 && check(l1, r1, l2, r2)) {
            cout << '=';
            continue;
        }

        ll kc = min(r1 - l1, r2 - l2) + 1;

        ll l = 0, r = kc, ans = 0;

        while(l <= r) {
            ll mid = (l + r) >> 1;

            if(check(l1, l1 + mid - 1, l2, l2 + mid - 1)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        if(ans == kc) {
            if(r1 - l1 < r2 - l2) cout << '<';
            else cout << '>';
        } else {
            if(a[1][l1 + ans] < a[2][l2 + ans]) cout << '<';
            else cout << '>';
        }
    }
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