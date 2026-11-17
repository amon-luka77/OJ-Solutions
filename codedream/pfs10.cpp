#include <bits/stdc++.h>
#define ll long long
#define ft first
#define sc second
#define el '\n'
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i ++)
#define FORD(i,b,a) for (int i = (b), _a = (a); i >= _a; i --)
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(name) freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
const ll N = 0;
ll n;
string s;
map<vector<ll>, ll> ts;

void read() {
    cin >> n >> s;
    s = ' ' + s;
    vector<ll> a(26, 0);
    vector<ll> c(26, 1);
    ts[a] ++;
    ts[c] ++;
    ll cnt = 0;

    

    cout << cnt;
}

void solve() {

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