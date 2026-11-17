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
#define file(name) freopen(name".inp", "r", stdin); freopen(name".ans", "w", stdout)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1LL)
#define NAME ""
using namespace std;

const ll N = 1e5;
ll n, a[N + 1], V;
bool vs[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> V;
}

void solve() {
    ll cnt = 1, d = 1;

    while(d < V) {
        ll maxA = 0;
        ll l = 1, r = n, ans = 0;
        while(l <= r) {
            ll mid = (l + r) >> 1;
            if(a[mid] <= d + 1) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        d += a[ans];
        cnt ++;
    }

    cout << cnt;
}

void write() {

}

int main() {
    boost;
    file("7E02");
    read();
    solve();
    write();
    return 0;
}