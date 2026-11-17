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
#define NAME ""
using namespace std;

void file() {
    if(fopen(NAME".inp", "r")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll N = 1e5;
ll n, a[N + 1], b[N + 1], diff[N + 2];
ll sum = 0;

void read() {
    cin >> n;
    FOR(i, 1, n) {cin >> a[i]; sum += a[i];}
}

bool check(ll k) {
    FOR(i, 0, n + 1) {b[i] = 0; diff[i] = 0;}
    FOR(i, 1, n) {
        b[i] = b[i - 1] + diff[i];
        if(b[i] > a[i]) return 0;
        if(i + k > n + 1 && b[i] < a[i]) return 0;

        if(i + k <= n + 1 && b[i] < a[i]) {
            diff[i + k] -= (a[i] - b[i]);
            b[i] = a[i];
        }
    }
    return 1;
}

void solve() {
    vector<ll> c;
    for(ll i = 1; i * i <= sum; i ++) {
        if(sum % i == 0) {
            if(i <= n) c.pb(i);
            if(i * i != sum && sum / i <= n) c.pb(sum / i);
        }
    } sort(all(c));

    FORD(i, c.size() -1 , 1) if(check(c[i])) {cout << c[i]; return;}
    cout << 1;
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
