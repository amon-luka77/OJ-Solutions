#include<bits/stdc++.h>
#define ll long long
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define NAME "nhap"

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rd);
}

const ll numTest = 1000;

#define pb push_back
#define all(x) (x).begin(), (x).end()

void makeTest() {
    ofstream cout(NAME".inp");

    ll n = 1e3; cout << n << "\n";
    FOR(i, 1, n) cout << 0 << ' ';
    cout << "\n";
    FOR(i, 1, n) cout << (ll)1e9 << ' ';
}

void solve() {
    FOR(i, 1, numTest) {
        makeTest();

        system(NAME ".exe");
        system(NAME "_trau.exe");

        if(system("fc " NAME ".out " NAME ".ans > nul")) {
            cout << "TEST: " << i << " WRONG!\n";
            return;
        } else cout << "TEST: " << i << " AC!\n";
    }
}

int main() {
    solve();
}
