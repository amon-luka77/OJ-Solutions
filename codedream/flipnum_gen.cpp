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
#define NAME "flipnum"
using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
const ll NTEST = 10000;

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll>(l, r)(rd);
}

void makeTest() {
    ofstream cout(NAME".inp");
    vector<ll> num;
    FOR(i, 1, 9) num.pb(i);
    FOR(i, 1, 17) num.pb(9);
    shuffle(all(num), rd);
    FOR(i, 1, 5) cout << num[Rand(0, num.size() - 1)];
    cout << 0;
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

