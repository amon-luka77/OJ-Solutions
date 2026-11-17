#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define all(x) x.begin(), x.end()
#define el "\n"
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "8E06"
using namespace std;

const ll NTEST = 100;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rd);
}

void makeTest() {
    ofstream cout(NAME ".inp");
    ll n = Rand(5, 10), m = Rand(1, 10);
    cout << n << ' ' << m << el;
    FOR(i, 1, n) cout << Rand(1, 10) << ' ' << Rand(1, m) << el;
    cout << m << el;
    FOR(i, 0, m - 1) cout << i << el;
}

void solve() {
    double Maxtime = 0;

    FOR(i, 1, NTEST) {
        makeTest();

        system(NAME "trau.exe");
        double t1 = (double) clock() / (double) CLOCKS_PER_SEC;
        system(NAME ".exe");
        double t2 = (double) clock() / (double) CLOCKS_PER_SEC;
        double Time = t2 - t1; Maxtime = max(Maxtime, Time);

        if(system("fc " NAME ".out " NAME ".ans > nul")) {
            cout << "TEST: " << i << " WRONG\n";
            cout << "TIME: " << fixed << setprecision(4) << Time;
            return;
        } else {
            cout << "TEST: " << i << " AC\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << "\n";
        }
    } cout << "MAXTIME: " << Maxtime;

}

int main() {
    solve();
}
