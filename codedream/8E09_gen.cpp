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
#define NAME "8E09"
using namespace std;

const ll NTEST = 1000;
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll>(l, r)(rd);
}

void makeTest() {
    ofstream cout(NAME".inp");
    ll n = 10; cout << n << el;
    FOR(i, 1, n - 1) cout << Rand(1, 3) << ' ';
}

void solve() {
    FOR(i, 1, NTEST) {
        makeTest();

        system(NAME"_trau.exe");
        system(NAME".exe");

        if(system("fc " NAME ".out " NAME ".ans > nul")) {
            cout << "TEST: " << i << ": WA!\n";
            return;
        } else cout << "TEST: " << i << ": AC!\n";
    }
}

void write() {

}

int main() {
    solve();
}
