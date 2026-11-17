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
string s, revS; 

long long h[N + 1][2][2], mul[N + 1][2], mode= 1e9 + 2277;
string a[2];

void read() {
    cin >> s;
    n = s.size();
    revS = s; reverse(all(revS));
    s = ' ' + s; revS = ' ' + revS;

    FOR(j, 0, 1) {
        mul[0][j] = 1;
    }

    FOR(k, 1, n) FOR(i, 0, 1) FOR(j, 0, 1) {
        // pos k, xau i, mode j;
        if(n >= 5e5) {
            if(i == 0) h[k][i][j] = (h[k - 1][i][j] * base + (s[k] - 'a' + 1));
            else h[k][i][j] = (h[k - 1][i][j] * base + (s[n - k + 1] - 'a' + 1));
            mul[k][j] = (mul[k - 1][j] * base);            
        } else {
            if(i == 0) h[k][i][j] = (h[k - 1][i][j] * base % mode + (s[k] - 'a' + 1)) % mode;
            else h[k][i][j] = (h[k - 1][i][j] * base % mode + (s[n - k + 1] - 'a' + 1)) % mode;
            mul[k][j] = (mul[k - 1][j] * base) % mode;  
        }

    }
}

ll getHash(ll l, ll r, ll t, ll m) {
    if(n >= 5e5) return (h[r][t][m] - h[l - 1][t][m] * mul[r - l + 1][m]);
    else return (h[r][t][m] - h[l - 1][t][m] * mul[r - l + 1][m] % mode + mode) % mode;
}

bool check(ll l, ll r) {
    if(getHash(l, r, 0, 0) == getHash(n - r + 1, n - l + 1, 1, 0)) {
            return 1;
    } 
    return 0;
}

void solve() {
    ll ansL = 1, ansR = 1;

    FOR(i, 1, n) {
        ll l = (ansR - ansL + 1) >> 1, r = min(i - 1, n - i);

        while(l <= r) {
            ll mid = (l + r) >> 1;

            if(check(i - mid, i + mid)) {
                ansL = i - mid, ansR = i + mid;

                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    FOR(i, 1, n - 1) {
        if(s[i] == s[i + 1]) {
            ll l = (ansR - ansL + 1) >> 1, r = min(i - 1, n - i - 1);

            while(l <= r) {
                ll mid = (l + r) >> 1;

                if(check(i - mid, i + 1 + mid)) {
                    ansL = i - mid, ansR = i + 1 + mid;
                    
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
    }

    FOR(i, ansL, ansR) cout << s[i];
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