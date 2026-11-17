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
ll t;

void read() {
    cin >> t;
    while(t --) {
        ll n, m;
        cin >> n >> m;
        string s; cin >> s;
        s = ' ' + s;
        vector<ll> diff(n + 5, 0), ans(26, 0);

        for(ll i = 1; i <= m; i ++) {
            ll x; cin >> x;
            diff[1] ++;
            diff[x + 1] --;
        }

        diff[1] ++;

        ll cur = 0;

        for(ll i = 1; i <= n; i ++) {
            cur += diff[i];
            ans[s[i] - 'a'] += cur;
        }

        for(ll i = 0; i < 26; i ++) {
            cout << ans[i] << ' ';
        }
        cout << el;
    }
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