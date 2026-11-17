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
using namespace std;
const ll N = 2e5, maxN = 1e9;
ll n, a[N + 1];
string s;
map<ll, ll> diff;

void read() {
    cin >> n;
    
    FOR(i, 1, n) cin >> a[i];

    cin >> s; s = ' ' + s;
}

void solve() {
    FOR(i, 1, n) {
        if(s[i] == '>') {
            diff[a[i] + 1] ++;
            diff[maxN + 1] --;
        } else if(s[i] == '<') {
            diff[1] ++;
            diff[a[i]] --;
        } else {
            diff[a[i]] ++;
            diff[a[i] + 1] --;
        }
    }

    ll cur = 0, ans = 1e18;

    for(auto &[i, j] : diff) {
        cur += j;
        ans = min(ans, n - cur);
    }

    cout << ans;
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