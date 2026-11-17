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

const ll N = 5e3, base = 77, mod1 = 1e9, mod2 = 998244353;
ll n; string s; 
ll mode[3], h[N + 1][5], mul[N + 1][5];

void read() {
    cin >> n >> s;
    s = ' ' + s;
    mode[1] = mod1;
    mode[2] = mod2;
    FOR(i, 1, 2) mul[0][i] = 1;
    
    FOR(i, 1, n) {
        h[i][1] = (h[i - 1][1] * base + (s[i] - 'a' + 1)) % mode[1];
        mul[i][1] = (mul[i - 1][1] * base) % mode[1];
        h[i][2] = (h[i - 1][2] * base + (s[i] - 'a' + 1)) % mode[2];
        mul[i][2] = (mul[i - 1][2] * base) % mode[2];
    }
}

ll getHash(ll l, ll r, ll m) {
    return (h[r][m] - h[l - 1][m] * mul[r - l + 1][m] % mode[m] + mode[m]) % mode[m];
}

bool check(ll len) {
    bool ok = 0;
    map<pair<ll, ll>, ll> ts;

    FOR(i, 1, n - len + 1) {
        if(i > len) {
            ts[{getHash(i - len, i - 1, 1), getHash(i - len, i - 1, 2)}] ++;
        }

        if(ts.find({getHash(i, i + len - 1, 1), getHash(i, i + len - 1, 2)}) != ts.end()) {
            ok = 1;
            break;
        }
    }

    return ok;
}

void solve() {
    ll l = 1, r = n, ans = 0;
    
    while(l <= r) {
        ll mid = (l + r) >> 1;

        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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