#include<bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define el "\n"
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1LL << (i))
#define BI(x, i) (((x) >> (i)) & 1)
#define NAME "8E07"

using namespace std;

const ll NTEST = 100;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());


ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll>(l, r)(rd);
}

void makeTest() {
    ofstream cout(NAME".inp");
    ll n = Rand(1, 1000), m = Rand(1, 1000); cout << n << ' ' << m << el;
    vector<ll> a(101, 0);
    FOR(i, 1, 100) a.pb(i);
    shuffle(all(a), rd);
    FOR(i, 1, n) {
        ll k = Rand(5, 50); cout << k << ' ';
        FOR(j, 1, k) cout << a[Rand(0, 99)] << ' ';
        cout << el;
    }
    FOR(i, 1, m) cout << Rand(1, 110) << el;
}

void solve() {
    double maxTime = 0;
    FOR(iTest, 1, NTEST) {
        makeTest();

        system(NAME"trau.exe");
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

