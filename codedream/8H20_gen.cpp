#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define el "\n"
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "8H20"
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
const ll NTEST = 100;

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll>(l, r)(rd);
}

void makeTest() {
    ofstream cout(NAME".inp");
    ll n = 10000, q = 10000; cout << n << ' ' << q << el;
    FOR(i, 1, n) cout << i << ' ';
    cout << el;
    FOR(i, 1, q) cout << Rand(1, 3) << ' ';
}

void solve() {
    double maxTime = 0;
    FOR(iTest, 1, NTEST) {
        makeTest();

        system(NAME"_trau.exe");
        double t1 = (double)clock() / (double)CLOCKS_PER_SEC;
        system(NAME".exe");
        double t2 = (double)clock() / (double)CLOCKS_PER_SEC;

        double Time = t2 - t1; maxTime = max(maxTime, Time);

        if(system("fc " NAME ".out " NAME ".ans > nul")) {
            cout << "TEST: " << iTest << ": WRONG!\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << el;
            return;
        } else {
            cout << "TEST: " << iTest << ": CORRECT!\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << el;
        }
    } cout << "MAXTIME: " << fixed << setprecision(4) << maxTime;
}

int main() {
    solve();
}
