#include<bits/stdc++.h>
#define ft first
#define sc second
#define pb push_back
#define ll long long
#define el '\n'
#define all(x) x.begin(), x.end()
#define FOR(i, a, b) for(ll i = (a), _b = (b); i <= _b; i ++)
#define FORD(i, a, b) for(ll i = (a), _b = (b); i >= _b; i --)
#define MASK(i) (1 << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define NAME "8E02"
using namespace std;

ll NTEST = 100;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    return l + rd() % (r - l + 1);
}

void makeTest() {
    ofstream cout(NAME".inp");
    ll n = Rand(1, (ll)100);
    cout << n << el;
    FOR(i, 1, n) cout << Rand(1, (ll)100) << ' ';
}

void solve() {
    double maxTime = 0;
    FOR(iTest, 1, NTEST) {
        makeTest();
        double t1 = (double)clock() / (double)CLOCKS_PER_SEC;
        system(NAME".exe");
        double t2 = (double)clock() / (double)CLOCKS_PER_SEC;
        system(NAME"trau.exe");
        double Time = double(t2 - t1); maxTime = max(maxTime, Time);

        if(system("fc " NAME ".out " NAME ".ans > nul")) {
            cout << "TEST " << iTest << ": WRONG!\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << el;
            return;
        } else {
            cout << "TEST " << iTest << ": CORRECT!\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << el;
        }
    }

    cout << "Max Time: " << maxTime;
}

int main() {
    solve();
}
