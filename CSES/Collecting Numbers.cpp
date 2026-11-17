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

const ll N = 2e5;
ll n;
pair<ll, ll> a[N + 1];

void read() {
    cin >> n;
    FOR(i, 1, n) {
        cin >> a[i].ft; a[i].sc = i;
        // cout << a[i].ft << ' ' << a[i].sc << el;
    }

    sort(a + 1, a + n + 1);
}

void solve() {
    ll cnt = 1;

    FOR(i, 2, n) {
        // cout << i << ' ';
        cnt += (a[i - 1].sc > a[i].sc);
    }

    cout << cnt;
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