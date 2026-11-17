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
const ll N = 2e5;
ll n, k;

void read() {
    cin >> n >> k;
}

void sub1() {
    vector<ll> a (n + 5, 0);
    FOR(i, 1, n) {
        char x; cin >> x;
        a[i] = x - '0';
    }

    FOR(i, 1, k) {
        vector<ll> b = a;
        FOR(j, 2, n - 1) {
            if(b[j - 1] && b[j + 1]) {
                a[j] = !a[j];
            }
        }
    }
    FOR(k, 1, n) cout << a[k];
}

void sub2() {
    vector<ll> a(n + 5, 0);

    FOR(i, 1, n) {
        char x; cin >> x;
        a[i] = x - '0';
    }

    map<vector<ll>, ll> check;
    vector<vector<ll>> c;
    c.pb(a);

    while(1) {
        vector<ll> b = a;

        FOR(j, 2, n - 1) {
            if(b[j - 1] && b[j + 1]) {
                a[j] = !a[j];
            }
        }

        if(check.find(a) != check.end()) break;
        check[a] = 1;
        c.pb(a);
    }

    vector<ll> a1 = c.back();
    if(a == a1) {
        FOR(i, 1, n) cout << a1[i];
        exit(0);
    }

    vector<vector<ll>> newC;
    ll chuki = 0;
    FORD(i, c.size() - 1, 0) {
        chuki ++;
        newC.pb(c[i]);
        if(c[i] == a) break;
    }

    reverse(all(newC));

    FOR(i, 1, n) {
        cout << newC[k % chuki][i];
    }
}

void solve() {
    if(n <= 5000 && k <= 5000) {
        sub1();
    } else {
        sub2();
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