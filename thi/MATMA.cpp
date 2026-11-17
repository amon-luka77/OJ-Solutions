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
#define file(name) freopen(name".INP", "r", stdin); freopen(name".OUT", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)

const ll N = 1e4;
ll n; string s;
char a[2 * N + 1];

void read() {
    cin >> s; n = s.size(); s = ' ' + s;
    FOR(i, 1, n) {
        a[i] = s[i];
        a[i + n] = s[i];
    }
}   

void solve() {
    ll ans = 0; bool ok = 1;

    FOR(i, 1, n) {
        if(a[i] != '0') {
            ok = 0; break;
        }
    }

    if(ok) {cout << n; exit(0);}

    FOR(i, 1, 2 * n) {
        ll cnt = 1;
        FORD(j, i - 1, 1) {
            if(a[j] != '0' && a[i] != a[j]) break;
            cnt ++;
        }

        FOR(j, i + 1, 2 * n) {
            if(a[j] != '0' && a[i] != a[j]) break;
            cnt ++;
        }

        ans = max(ans, min(cnt, n));
    }

    cout << ans;
}

void write() {

}

int main() {
    boost;
    file("MATMA");
    read();
    solve();
    write();
    return 0;
}