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

ll n, m, k, hashP = 0, mode = 998244353;
ll h[N + 1], mul[N + 1], diff[N + 1];
string s = "", p;

void read() {
    getline(cin, s);
    cin >> p;
    cin >> k;

    ll l = 0;
    while(l < s.size()) {
        if(s[l] == ' ') s.erase(l, 1);
        else l ++;
    }

    n = s.size(); m = p.size(); s = ' ' + s; p = ' ' + p;
    mul[0] = 1;

    FOR(i, 1, n) {
        mul[i] = (mul[i - 1] * base) % mode;    
    }

    FOR(i, 1, p.size() - 1) {
        hashP = (hashP * base % mode + p[i]) % mode;
    }

    FOR(i, 1, n) {
        h[i] = (h[i - 1] * base % mode + s[i]) % mode;
    }
}

ll getHash(ll l, ll r) {
    return (h[r] -  h[l - 1] * mul[r - l + 1] % mode + mode) % mode;
}

void solve() {
    vector<pair<ll, ll>> a;

    FOR(i, 1, n - m + 1) {
        ll l = i, r = l + m - 1;

        if(getHash(l, r) == hashP) {
            ll L = max(1LL, r - k + 1), R = i;
            if(L <= R) {
                diff[L] ++;
                diff[R + 1] --;
            }
        }
    }

    ll cnt = 0, cur = 0;

    FOR(i, 1, n - k + 1) {
        cur += diff[i];
        if(cur > 0) cnt ++;
    }

    cout << cnt;
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