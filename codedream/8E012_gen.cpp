
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
#define NAME "8E012"
using namespace std;

const ll NTEST = 100;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll>(l, r)(rd);
}

void makeTest() {
    ofstream cout(NAME".inp");

    ll n = Rand(5, 20), q = Rand(1, 10);
    cout << n << ' ' << q << el;
    FOR(i, 1, n) cout << Rand(1, 1000) << ' ';
    cout << el; vector<char> a;
    FOR(i, 1, 10) a.pb('+');
    FOR(i, 1, 2) a.pb('-');
    FOR(i, 1, 15) a.pb('?');
    shuffle(all(a), rd);

    FOR(i, 1, q) {
        ll x = Rand(1, n - 1), y = Rand(x + 1, n);
        cout << a[Rand(0, a.size() - 1)] << ' ' << x << ' ' << y << el;
    }
}

void solve() {
    double maxTime = 0;
    FOR(i, 1, NTEST) {
        makeTest();

        system(NAME"_trau.exe");
        double t1 = (double)clock() / (double)CLOCKS_PER_SEC;
        system(NAME".exe");
        double t2 = (double)clock() / (double)CLOCKS_PER_SEC;
        double Time = t2 - t1; maxTime = max(maxTime, Time);

        if(system("fc " NAME ".out " NAME ".ans > nul")) {
            cout << "TEST: " << i << ": WA!\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << el;
            return;
        } else {
            cout << "TEST: " << i << ": AC!\n";
            cout << "TIME: " << fixed << setprecision(4) << Time << el;
        }
    } cout << "MAXTIME: " << fixed << setprecision(4) << maxTime << el;
}

int main() {
    solve();
}
