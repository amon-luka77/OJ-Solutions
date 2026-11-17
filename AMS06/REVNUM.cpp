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
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "REVNUM"
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, k, a[N + 1];

void read() {
    cin >> n >> k;
    FOR(i, 1, n) cin >> a[i];
}

vector<string> b;

void solve() {
    FOR(i, 1, n) {
        string t = to_string(a[i]);
        reverse(all(t)); b.pb(t);
    }

    sort(all(b), [](const string &x, const string &y) {
        return x + y < y + x;
    });

    string ans = ""; ll j = 0;
    FOR(i, 0, n - 1) if(b[i][0] != '0') {ans += b[i]; j = i; break;}

    FOR(i, 0, j - 1) ans += b[i];
    FOR(i, j + 1, n - 1) ans += b[i];
    cout << ans;
}

void write() {

}

int main() {
    boost;
    file();
    read();
    solve();
    write();
    return 0;
}

// 91 01