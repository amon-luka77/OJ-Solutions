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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME "CANDY"
using namespace std;

const ll N = 0;
const ll NTEST = 500;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r) {
    return l + rd() % (r - l + 1);
}

void read() {

}

ll a[20];

string readFile(string name) {
    ifstream fin(name);
    stringstream ss;
    ss << fin.rdbuf();

    string s = ss.str();
    if (s.empty() || s.back() != '\n')
        s += '\n';

    return s;
}

string shorten(string s, int lim = 80) {
    if ((int)s.size() <= lim) return s;
    return s.substr(0, lim) + "...";
}

void makeTest() {
    ofstream cout(NAME".inp");
    
    ll n = Rand(0, 1000), m = Rand(1, 1000);
    vector<ll> a; cout << n << ' ' << m << el;
    FOR(i, 1, m) a.pb(Rand(0, (ll)1e9));
    sort(all(a)); for(auto i : a) cout << i << ' ';
    cout << el;
    FOR(i, 1, n) cout << Rand(1, n) << ' ';
}

void solve() {
    double maxTime = 0;
    FOR(iTest, 1, NTEST) {
        makeTest();

        system(NAME"trau.exe");

        auto st = chrono::steady_clock::now();
        system(NAME ".exe");
        auto ed = chrono::steady_clock::now();

        double t = chrono::duration<double>(ed - st).count();
        maxTime = max(maxTime, t);

        if (system("fc " NAME ".out " NAME ".ans > nul")) {

            cout << "\n========================\n";
            cout << "TEST " << iTest << ": WRONG\n";
            cout << "Time : " << fixed << setprecision(4) << t << " s\n\n";

            cout << "INPUT:\n";
            cout << readFile(NAME ".inp") << '\n';
            cout << "------------------------\n";

            cout << "EXPECTED:\n";
            cout << readFile(NAME ".ans") << '\n';
            cout << "------------------------\n";

            cout << "YOUR OUTPUT:\n";
            cout << readFile(NAME ".out") << '\n';
            cout << "------------------------\n";

            return;
        }
        else {
            string ans = readFile(NAME ".ans");

            cout << "TEST " << setw(3) << iTest
                << ": CORRECT"
                << " | ANS = " << shorten(ans)
                << " | "
                << fixed << setprecision(4)
                << t << " s\n";
        }
    }
    cout << "\nMax Time = "
     << fixed << setprecision(4)
     << maxTime << " s\n";
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