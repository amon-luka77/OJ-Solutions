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

const ll N = 1e6;

string s;
ll n, kmp[N + 1];

void read() {
    cin >> s;
    n = s.size(); s = ' ' + s;
}

void solve() {
    ll k = 0;
    kmp[1] = 0;

    FOR(i, 2, n) {
        while(k > 0 && s[i] != s[k + 1]) k = kmp[k];

        if(s[i] == s[k + 1]) k ++;

        kmp[i] = k;
    }

    vector<int> z(n + 1);

    int l = 0, r = 0;

    for (int i = 2; i <= n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l + 1]);

        while (i + z[i] <= n &&
            s[z[i] + 1] == s[i + z[i]])
            z[i]++;

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    FOR(i, 1, n) cout << z[i] << ' '; 
    cout << el;
    FOR(i, 1, n) cout << kmp[i] << ' ';
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