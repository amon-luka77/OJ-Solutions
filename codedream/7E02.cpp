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
#define NAME ""
using namespace std;

const ll N = 1e5;
ll n, a[N + 3], V;
bool vs[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    cin >> V;
}

void solve() {
    if(V <= 1e7) {
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
        return;
    }

    ll d = 0, cnt = 0;
// d + k * a[i] + 1 >= a[i + 1];
// a[i] <= d + 1
    FOR(i, 1, n - 1) {
        if(d >= V) break;
        ll j = i;
        while(j + 1 < n && a[j + 1] <= d + 1) j ++;
        i = j;
        ll x = (a[i + 1] - d - 1 + a[i] - 1) / a[i];
        cnt += x;
        d += x * a[i];

        // cout << a[i] << ' ' << cnt << el;
    }

    if(d < V) {
        cnt += (a[n] - 1 + V - d) / a[n];
    }

    cout << cnt;
}

void write() {

}

int main() {
    boost;
    // file("7E02");
    read();
    solve();
    write();
    return 0;
}