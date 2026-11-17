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
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5, base = 77, mod = 1e9 + 7;
ll n, m, k;
unordered_map<ll, ll> b;
ll h[N + 1][2], mul[N + 1];
string s1, s2;
string ans = "";

void read() {
    cin >> n >> m >> k;
    cin >> s1 >> s2;
    s1 = ' ' + s1; s2 = ' ' + s2;
    mul[0] = 1;
    FOR(i, 1, n) {
        h[i][1] = (h[i - 1][1] * base % mod + s1[i] - 'A') % mod;
    }
    FOR(i, 1, m) {
        h[i][2] = (h[i - 1][2] * base % mod + s2[i] - 'A') % mod;
    }
    FOR(i, 1, max(n, m)) {
        mul[i] = (mul[i - 1] * base) % mod;
    }
}

ll getHash(ll l, ll r, ll i) {
    return (h[r][i] - h[l - 1][i] * mul[r - l + 1] % mod + mod) % mod;
}

bool check(ll mid) {
    // return 1;
    b.clear();
    FOR(i, 1, m - mid + 1) {
        // cerr << getHash(i, i + mid - 1, 1) << ' ';
        b[getHash(i, i + mid - 1, 2)] ++;
    }

    FOR(i, 1, n - mid + 1) {
        if(b[getHash(i, i + mid - 1, 1)] >= k) {
            return 1;
        }
    }

    return 0;
}

void solve() {
    ll l = 1, r = min(n, m), len = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) {
            l = mid + 1;
            len = mid;
            // cout << 77 << el;
        } else {
            r = mid - 1;
        }
    }

    b.clear();
    FOR(i, 1, m - len + 1) {
        b[getHash(i, i + len - 1, 2)] ++;
    }
    
    FOR(i, 1, n - len + 1) {
        if(b[getHash(i, i + len - 1, 1)] >= k) {
            if(ans == "") ans = s1.substr(i, len);
            else ans = min(ans, s1.substr(i, len));
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
