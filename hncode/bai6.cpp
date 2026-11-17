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
const ll N = 2e5;
ll n, a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    ll cnt = 0;

    FOR(i, 1, n) {
        set<ll> left, right;

        ll l = i - 1, r = i + 1;
        while(l >= 1 && a[l] < a[i]) left.insert(a[l --]);
        while(r <= n && a[r] < a[i]) right.insert(a[r ++]);

        if(left.empty() || right.empty()) continue;
        for(auto j : left) {
            if(right.find(a[i] - j) != right.end()) cnt ++;
        }
        cout << el;
    }

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